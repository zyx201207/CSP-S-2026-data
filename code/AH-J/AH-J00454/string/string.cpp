#include <cstdio>

#define N 200000
using Ll = long long;
Ll p[N];
char q[N];

Ll min(const Ll a, const Ll b)
{
    return a < b ? a : b;
}

int main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    Ll n;
    scanf("%lld", &n);
    for (Ll i = 0LL; i < n; ++i)
    {
        scanf("%lld %c", &p[i], &q[i]);
    }
    Ll r = 0LL;
    for (Ll a = 0LL, b = 0LL, c = n - 1LL, d = 0LL; a != c;)
    {
        const Ll x = p[a] - b, y = p[c] - d;
        if (x < y)
        {
            if (q[a] != q[c])
            {
                r += x;
            }
            ++a;
            b = 0LL;
            d += x;
        }
        else
        {
            if (q[a] != q[c])
            {
                r += y;
            }
            --c;
            d = 0LL;
            b += y;
        }
    }
    printf("%lld\n", r);
    return 0;
}