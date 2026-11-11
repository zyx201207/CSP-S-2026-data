#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define urep(i, r, l) for(int i = (r); i >= (l); i--)
constexpr int _ = 2000005, mod = 998244353, inf = 0x3f3f3f3f3f3f3f3f;

#define ary array<int, 2>

inline int rd()
{
    signed c = getchar();
    int res = 0, f = 1;
    for(; !isdigit(c); c = getchar()) if(c == '-') f = -1;
    for(; isdigit(c); c = getchar()) res = res * 10 + (c ^ 48);
    return res * f;
}

int c, n, m, d, q;
int w[_];
vector <ary> e[_];
int dis[505][505];

signed main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    c = rd(), n = rd(), m = rd(), d = rd(), q = rd();
    rep(i, 1, m) w[i] = rd();
    int ki, ai, ti;
    rep(i, 1, n)
    {
        ki = rd();
        while(ki--) ai = rd(), ti = rd(), e[ai].emplace_back(ary{i, ti});
    }
    memset(dis, 0x3f, sizeof(dis));
    rep(i, 1, m) 
        for(auto [u, w] : e[i])
            for(auto [v, ww] : e[i])
                if(u != v) dis[u][v] = dis[v][u] = min(dis[u][v], w + ww);
    rep(i, 1, n) dis[i][i] = 0;
    rep(k, 1, n) rep(i, 1, n) rep(j, 1, n) dis[i][j] = dis[j][i] = min(dis[i][j], dis[i][k] + dis[k][j]);
    int ans = 0, x, y;
    while(q--)
    {
        ans = inf;
        x = rd(), y = rd();
        for(auto [u, w] : e[x]) for(auto [v, ww] : e[y]) ans = min(ans, w + ww + dis[u][v]);
        cout << ans + w[x] + w[y] << "\n";
    }
    return 0;
}