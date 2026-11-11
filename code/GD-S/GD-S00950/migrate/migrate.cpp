#include <bits/stdc++.h>
#define PROBLEM "migrate"
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

i64 constexpr Infinity = 0x7f7f7f7f7f7f7f7fll;
i32 constexpr MaxN = 2e6 + 10;

i64 P[MaxN];
i64 dis[MaxN], met[MaxN];

int main()
{
#ifndef LOCAL
    freopen(PROBLEM ".in", "r", stdin);
    freopen(PROBLEM ".out", "w", stdout);
#endif

    i32 C, T;
    scanf("%d %d", &C, &T);

    while (T--)
    {
        i64 N, D;
        scanf("%lld %lld", &N, &D);

        for (i32 i = 1; i <= N; ++i)
            scanf("%lld", P + i);

        i64 ans = 0;
        for (i32 i = 1; i < N; ++i)
        {
            std::fill(dis + i + 1, dis + N + 1, Infinity), std::fill(met + i + 1, met + N + i, 0ll);

            dis[i] = 0, met[i] = 1;
            for (i32 j = i; j <= N; ++j)
            {
                for (i32 k = j + 1; k <= N && P[k] - P[j] <= D; ++k)
                    if (dis[k] > dis[j] + 1)
                        dis[k] = dis[j] + 1, met[k] = met[j];
                    else if (dis[k] == dis[j] + 1)
                        met[k] += met[j];
            }

            for (i32 j = i + 1; j <= N; ++j)
                // logf("For pair (%d, %d): dis= %lld, met= %lld.\n", i, j, dis[j], met[j]),
                ans += met[j] == 2;
        }

        printf("%lld\n", ans);
    }
}
