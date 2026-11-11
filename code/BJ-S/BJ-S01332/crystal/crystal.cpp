#include <bits/stdc++.h>
using namespace std;

long long n, m, a[500005], sum[500005];

bool check(long long mid)
{
    for (long long i = mid; i <= n; i++)
    {
        if (a[i] * mid - (sum[i] - sum[i - mid]) <= m)
        {
            return 1;
        }
        
    }
    return 0;
}

int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    scanf("%lld%lld", &n, &m);
    for (long long i = 1; i <= n; i++)
    {
        scanf("%lld", &a[i]);
        sum[i] = sum[i - 1] + a[i];
    }
    sort (a + 1, a + n + 1);
    for (long long i = 1; i <= n; i++)
    {
        sum[i] = sum[i - 1] + a[i];
    }
    long long l = 0, r = n;
    while (l <= r)
    {
        long long mid = l + r >> 1;
        if (check(mid))
        {
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    printf("%lld", l - 1);
    return 0;
}