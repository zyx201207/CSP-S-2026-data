#include <cstdio>

#define N 200001
using Ll = long long;
Ll v[N], p[N];

Ll cnt(const Ll x)
{
    Ll r = 0LL;
    for (Ll i = p[0]; ~i; i = p[i])
    {
        r += v[i] >> x & 1LL;
    }
    return r;
}

void rm(const Ll x)
{
    for (Ll i = 0LL; ~p[i]; i = p[i])
    {
        while (!(v[p[i]] >> x & 1LL) && ~p[i])
        {
            p[i] = p[p[i]];
        }
    }
}

int main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    Ll n, m;
    scanf("%lld%lld", &n, &m);
    for (Ll i = 1LL; i <= n; ++i)
    {
        scanf("%lld", &v[i]);
        p[i - 1LL] = i;
    }
    p[n] = -1LL;
    for (Ll i = 29LL; i >= 0LL; --i)
    {
        const Ll t = cnt(i);
        if (t >= m)
        {
            rm(i);
        }
    }
    Ll r = 0x3FFFFFFFLL;
    for (Ll i = p[0], j = m; j--; i = p[i])
    {
        r &= v[i];
    }
    printf("%lld\n", r);
    return 0;
}