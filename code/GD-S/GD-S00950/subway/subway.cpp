#include <bits/stdc++.h>
#define PROBLEM "subway"
// #define LOCAL

#ifdef LOCAL
#define logf(...) ((void)::fprintf(stderr, __VA_ARGS__))
#define debug(...) (([&]()->void __VA_ARGS__)())
#else
#define logf(...) (void())
#define debug(...) (void())
#endif

typedef int i32;
typedef long long i64;

i32 constexpr MaxN = 512, MaxM = 5e5 + 10;
i64 constexpr Infinity = 0x3f3f3f3f3f3f3f3fll;

i64 dis[MaxN][MaxN];
i32 W[MaxM];
std::vector<std::pair<i32, i32>> T[MaxM];

int main()
{
#ifndef LOCAL
    freopen(PROBLEM ".in", "r", stdin);
    freopen(PROBLEM ".out", "w", stdout);
#endif

    memset(dis, 0x3f, sizeof dis);

    i32 C, N, M, D, Q;
    scanf("%d %d %d %d %d", &C, &N, &M, &D, &Q);

    for (i32 i = 1; i <= M; ++i)
        scanf("%d", W + i);

    for (i32 i = 1, Ki; i <= N; ++i)
    {
        scanf("%d", &Ki), dis[i][i] = 0;
        for (i32 j = 1, plat, time; j <= Ki; ++j)
        {
            scanf("%d %d", &plat, &time);
            for (auto const &x : T[plat])
                dis[i][x.first] = dis[x.first][i] = std::min(dis[x.first][i], (i64)time + x.second);
            T[plat].emplace_back(i, time);
        }
    }

    for (i32 k = 1; k <= N; ++k)
        for (i32 i = 1; i <= N; ++i)
            for (i32 j = i + 1; j <= N; ++j)
                dis[i][j] = dis[j][i] = std::min(dis[i][j], dis[i][k] + dis[k][j]);

    for (i32 i = 1, x, y; i <= Q; ++i)
    {
        scanf("%d %d", &x, &y);

        i64 ans = Infinity;

        for (auto const &p1 : T[x])
            for (auto const &p2 : T[y])
                ans = std::min(ans, (i64)W[x] + p1.second + dis[p1.first][p2.first] + p2.second + W[y]);

        printf("%lld\n", ans);
    }
}
