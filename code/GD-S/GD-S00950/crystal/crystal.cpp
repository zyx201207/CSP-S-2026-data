#include <bits/stdc++.h>
#define PROBLEM "crystal"
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

i64 constexpr MaxN = 5e5 + 10;

i64 A[MaxN], pre[MaxN];

int main()
{
#ifndef LOCAL
    freopen(PROBLEM ".in", "r", stdin);
    freopen(PROBLEM ".out", "w", stdout);
#endif

    i64 N, M;
    scanf("%lld %lld", &N, &M);

    for (i32 i = 1; i <= N; ++i)
        scanf("%lld", A + i);

    std::sort(A + 1, A + N + 1);

    for (i32 i = 1; i <= N; ++i)
        pre[i] += pre[i - 1] + A[i];

    i32 ans = 0;
    for (i32 i = N; i >= 1; --i)
    {
        // logf("Currently calculating at idx %d.\n", i);
        i32 L = 0, R = i;
        while (L + 1 < R)
        {
            i32 mid = (L + R) >> 1;
            i64 const expected = (A[i] * (i - mid)), had = (pre[i - 1] - pre[mid - 1]);
            i64 const required = expected - had;
            // logf("For [%d, %d]: expected= %lld, had= %lld, requried= %lld, ", mid, i - 1, expected, had, required);
            if (required <= M)
                // logf("updated R to %d.\n", mid),
                R = mid;
            else
                // logf("updated L to %d.\n", mid),
                L = mid;
        }

        ans = std::max<i32>(ans, i - R + 1);
    }

    printf("%d", ans);
}
