#ifndef GUARD_raycaster_hpp
#define GUARD_raycaster_hpp

#include <vector>
#include <SDL2/SDL.h>
#include "player.hpp"

struct RayCollision
{
    double distance;
    double offset;
};

class RayCaster
{
    std::vector<std::vector<char>> _map;

    void castSingleRay(const SDL_Rect *, const SDL_Rect *, int &) const;
    void drawRay(const RayCollision *) const;

    const RayCollision *findHorizontalRayCollision(const SDL_Rect *, const SDL_Rect *, const int &) const;
    double findFirstHIntersectionX(const int &, const SDL_Rect *, const double &) const;
    double findFirstHIntersectionY(const SDL_Rect *, const bool &) const;
    double findNextHIntersectionX(const int &) const;
    double findNextHIntersectionY(const bool &) const;

    const RayCollision *findVerticalRayCollision(const SDL_Rect *, const SDL_Rect *, const int &) const;
    double findFirstVIntersectionX(const SDL_Rect *, const bool &) const;
    double findFirstVIntersectionY(const int &, const SDL_Rect *, const double &) const;
    double findNextVIntersectionX(const bool &) const;
    double findNextVIntersectionY(const int &) const;

    bool rayIsOutsideViewArea(const SDL_Rect *, const double&, const double&) const;
    bool solidExists(const int &, const int &) const;

public:
    RayCaster(const std::vector<std::vector<char>> &);
    void castRays(const Player *) const;
};

#endif