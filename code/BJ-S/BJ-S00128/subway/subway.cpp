#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll c, n, m, d, q;
ll w[500005], k[505], dis[505][505];

struct node {
    ll v, w;
};

vector <node> g[500005];

int main () {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; ++i) {
        cin >> w[i];
    }
    for (int i = 1; i <= n; ++i) {
        cin >> k[i];
        for (int j = 1; j <= k[i]; ++j) {
            ll x, y;
            cin >> x >> y;
            g[x].push_back({i, y});
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            dis[i][j] = 1e18;
        }
        dis[i][i] = 0;
    }
    for (int i = 1; i <= m; ++i) {
        for (int j = 0; j < g[i].size(); ++j) {
            for (int k = j + 1; k < g[i].size(); ++k) {
                ll u = g[i][j].v, v = g[i][k].v, w1 = g[i][j].w, w2 = g[i][k].w;
                dis[u][v] = min(dis[u][v], w1 + w2);
                dis[v][u] = dis[u][v];
            }
        }
    }
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }
    for (int i = 1; i <= q; ++i) {
        ll x, y;
        cin >> x >> y;
        ll ans = 1e18;
        for (int j = 0; j < g[x].size(); ++j) {
            for (int k = 0; k < g[y].size(); ++k) {
                ll u = g[x][j].v, v = g[y][k].v;
                ans = min(ans, dis[u][v] + g[x][j].w + g[y][k].w + w[x] + w[y]);
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
