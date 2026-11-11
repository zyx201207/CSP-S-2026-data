#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 2e6 + 5;

int n;

long long x[N], bf[N], nt[N], d;

int fib(long long key)
{
    key -= d;
    int l = 1, r = n;
    while (l < r)
    {
        int mid = (l + r) / 2;
        if (x[mid] >= key) r = mid;
        else l = mid + 1;
    }
    return r;
}

int fia(long long key)
{
    key += d;
    int l = 1, r = n;
    while (l < r)
    {
        int mid = (l + r + 1) / 2;
        if (x[mid] <= key) l = mid;
        else r = mid - 1;
    }
    return l;
}

int main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    int c, T;
    scanf("%d%d", &c, &T);
    while (T--)
    {
        scanf("%d%lld", &n, &d);
        for (int i = 1; i <= n; i++)
        {
            scanf("%lld", &x[i]);
        }
        if (c == 11 || c == 12)
        {
            if (d < x[2] - x[1])
            {
                printf("0\n");
                continue;
            }
            long long step = 2 * d / (x[2] - x[1]);
            if (step > n || step == 2) printf("0\n");
            else printf("%lld\n", n - step + 1);
        }
        else
        {
            bf[1] = 1;
            for (int i = 2; i <= n; i++)
            {
                if (x[i] - d <= x[i - 1])
                {
                    bf[i] = 2;
                    if (x[fib(x[fib(x[i])])] != x[fib(x[fib(x[i]) + 1])]) bf[i] = bf[i - 2] + 1;
                }
                else bf[i] = 1;
            }
            nt[n] = 1;
            for (int i = n - 1; i >= 1; i--)
            {
                if (x[i] + d >= x[i + 1])
                {
                    nt[i] = 2;
                    if (x[fia(x[fia(x[i])])] != x[fia(x[fia(x[i]) - 1])]) nt[i] = nt[i + 2] + 1;
                }
                else nt[i] = 1;
            }
            long long ans = 0;
            for (int i = 1; i < n; i++)
            {
                if (x[i + 1] - x[i] > d) continue;
                int mk1 = fib(x[i + 1]), mk2 = fia(x[i]);
                for (int j = mk1; j < i; j++)
                {
                    int mk3 = fia(x[mk1]) + 1;
                    for (int k = mk3; k <= mk2; k++)
                    {
                        ans += 1ll * (bf[j]) * (nt[k]);
                        // printf("%d %lld %lld\n", i, bf[j], nt[k]);
                    }
                }
            }
            printf("%lld\n", ans);
        }
    }
    return 0;
}