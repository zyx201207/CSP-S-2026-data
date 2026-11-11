#include <cstdio>

using Ll = long long;

int main()
{
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    Ll n, m;
    scanf("%lld%lld", &n, &m);
    for (Ll i = 0LL, l = 0LL, k = 1LL, s = 0LL; i < n; ++i)
    {
        Ll a;
        scanf("%lld", &a);
        if (!l)
        {
            l = a;
        }
        else if (a == l)
        {
            ++k;
        }
        else
        {
            l = a;
            printf("%lld ", s += k);
            k = 1LL;
        }
    }
    putchar('\n');
    return 0;
}