#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using i8 = __int128;
void sv();
template <typename T = ll>
inline T fin()
{
    char c = getchar_unlocked();
    T f = 1, cnt = 1;
    string x;
    if (c == '-') f = -1, c = '0';
    while (c >= '0' && c <= '9')
    {
        x += c;
        cnt *= 10;
        c = getchar_unlocked();
    }
    T res = 0; cnt = 1;
    for (char c : x)
    {
        res += (c-'0')*cnt;
        cnt *= 10;
    }
    return res*f;
}
void fre()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
}

ll g[1145][1145];
const ll NM = 2500'00100;
ll w[NM], sc[NM];

signed main()
{
    memset(g, 0x3f, sizeof(g));
    for (ll i = 1; i <= NM; i++)
        sc[i] = i;
    fre();
    ll c, n, m, d, q;
    c = fin(), n = fin(), m = fin(), d = fin(), q = fin();
    vector <ll> w(m+114);
    for (ll i = 1; i <= m; i++)
        w[i] = fin();
    for (ll i = 1; i <= n; i++)
    {
        ll k;
        k = fin();
        for (ll j = 1; j <= k; j++)
        {
            ll x, t;
            x = fin(), t = fin();
            g[k][k+514] = g[k+514][k] = t;
        }
    }
    return 0;
}