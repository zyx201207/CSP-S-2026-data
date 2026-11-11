#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 2e6 + 7;
ll c, t, n, d, x[N];

ll read()
{
    char c;
    ll k = 0;
    c = getchar();
    while(c >= '0' && c <='9')k *= 10, k += c - '0', c = getchar();
    return k;
}

void oprt()
{
    n = read(), d = read();
    for(ll i = 1; i <= n; i++)x[i] = read();
    if(abs(x[2] - x[1]) >= d)printf("0");
    else if(x[2] - x[1] == x[3] - x[2])
    {
        ll ans = 0;
        for(ll i = 1; i < n; i++)ans += i;
        printf("%lld", ans);
    }
}

int main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    c = read(), t = read();
    while(--t)
    {
        oprt();
        if(oprt)printf("\n");
    }
    return 0;
}
