#include <algorithm>
#include <cstdio>
using std::sort;

#define N 500001
using Ll = long long;
Ll n, s[N];

Ll bs(const Ll k, const Ll p) // mx le k
{
    Ll l = 1LL, r = n;
    while (l < r)
    {
        const Ll m = l + r + 1LL >> 1LL;
        if (s[m] - (m - p) * (s[p] - s[p - 1LL]) - s[p] <= k)
        {
            l = m;
        }
        else
        {
            r = m - 1LL;
        }
    }
    return l;
}

int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    Ll m;
    scanf("%lld%lld", &n, &m);
    Ll mx = 0LL;
    for (Ll i = 1LL; i <= n; ++i)
    {
        scanf("%lld", &s[i]);
        if (mx < s[i])
        {
            mx = s[i];
        }
    }
    for (Ll i = 1LL; i <= n; ++i)
    {
        s[i] = mx - s[i];
    }
    sort(s + 1LL, s + n + 1LL);
    for (Ll i = 1LL; i <= n; ++i)
    {
        s[i] += s[i - 1LL];
    }
    Ll r = 0LL;
    for (Ll i = 1LL; i <= n; ++i)
    {
        const Ll t = bs(m, i) - i;
        if (r < t)
        {
            r = t;
        }
    }
    printf("%lld\n", r + 1LL);
    return 0;
}