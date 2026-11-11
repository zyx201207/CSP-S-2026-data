#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define len 2000005
ll n, d;
int c, t;

ll readll()
{
    ll k = 0, p = 1;
    char c = getchar();
    while (c < '0' || c > '9')
    {
        if (c == '-')
            p = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9')
    {
        k = k * 10 + (c - '0');
        c = getchar();
    }
    return k * p;
}
int readint()
{
    int k = 0, p = 1;
    char c = getchar();
    while (c < '0' || c > '9')
    {
        if (c == '-')
            p = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9')
    {
        k = k * 10 + (c - '0');
        c = getchar();
    }
    return k * p;
}

int main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);

    c = readint();
    t = readint();
    while (t--)
    {
        ll cnt, x, sum;
        n = readll();
        d = readll();
        cnt = readll();
        x = readll();
        sum = x - cnt;
        for (int i = 3; i <= n; i++)
            x = readll();
        if (sum >= d)
        {
            printf("0\n");
        }
        else
        {
            ll g = ((d / sum) * 2) - 1;
            ll ans = n - g;
            if (ans < 0)
                printf("0\n");
            else
                printf("%lld\n", ans);
        }
    }
    return 0;
}
