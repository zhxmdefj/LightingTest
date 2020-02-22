#pragma once

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <vector>

using namespace glm;

const float SPEED = 2.5f;
vec3 worldfront = vec3(0.0f, 0.0f, -1.0f);
vec3 worldright = vec3(1.0f, 0.0f, 0.0f);
vec3 worldup = normalize(cross(worldfront, worldright));

enum Movement {
    MFORWARD,
    MBACKWARD,
    MLEFT,
    MRIGHT,
    MUP,
    MDOWN
};

class MoveableObject 
{
public:
    vec3 Position;
    vec3 Front;
    vec3 Up;
    vec3 Right;
    float MovementSpeed;

    MoveableObject(
        vec3 position = vec3(0.0f, 0.0f, 0.0f)
        )
        :
        Position(position),
        Front(worldfront),
        Up(worldup),
        Right(worldright),
        MovementSpeed(SPEED)
    {

    }

    void ProcessKeyboard(Movement direction, float deltaTime)
    {
        float velocity = MovementSpeed * deltaTime;
        if (direction == MFORWARD)
            Position += Front * velocity;
        if (direction == MBACKWARD)
            Position -= Front * velocity;
        if (direction == MLEFT)
            Position -= Right * velocity;
        if (direction == MRIGHT)
            Position += Right * velocity;
        if (direction == MUP)
            Position += Up * velocity;
        if (direction == MDOWN)
            Position -= Up * velocity;
    }

private:
    void updateObjectVectors()
    {
        Right = normalize(cross(Front, worldup));
        Up = normalize(cross(Right, Front));
    }
};

