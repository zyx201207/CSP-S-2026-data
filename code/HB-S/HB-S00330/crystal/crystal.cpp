#include <bits/stdc++.h>
using namespace std;
#define N 500005
long long n, m, a[N], l = LONG_MAX, r = LONG_MIN, ans = -1, ansx;
bool check(long long x)
{
    ansx = 0;
    long long res = 0;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] <= x)
        {
            res += (x - a[i]);
            ansx++;
        }
    }
    return (res <= m);
}
int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    scanf("%lld%lld", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &a[i]);
        l = min(l, a[i]);
        r = max(r, a[i]);
    }
    while (l <= r)
    {
        long long mid = (l + r) / 2;
        if (check(mid))
        {
            l = mid + 1;
            ans = max(ans, ansx);
        }
        else
        {
            r = mid - 1;
        }
    }
    printf("%lld", ans);
    return 0;
}
