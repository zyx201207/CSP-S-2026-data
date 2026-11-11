#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll Inf = 1e18;

int c, n, m, d, q;
vector<int> w;
vector<vector<ll>> dis;
vector<vector<pair<int, int>>> bel;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);

    cin >> c >> n >> m >> d >> q;
    w.resize(m + 1);
    for (int i = 1; i <= m; i++) cin >> w[i];
    bel.resize(m + 1);
	for (int i = 1, k; i <= n; i++) {
        cin >> k;
        for (int j = 1, a, t; j <= k; j++) {
            cin >> a >> t;
            bel[a].push_back({i, t});
        }
    }
    dis.resize(n + 1, vector<ll>(n + 1, Inf));
    for (int i = 1; i <= n; i++) dis[i][i] = 0;
    for (int i = 1; i <= m; i++) {
        for (auto u : bel[i]) {
            for (auto v : bel[i]) {
                if (u.first == v.first) continue;
                dis[u.first][v.first] = min(dis[u.first][v.first], (ll)u.second + v.second);
                dis[v.first][u.first] = min(dis[v.first][u.first], (ll)v.second + u.second);
            }
        }
    }
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
    for (int i = 1, x, y; i <= q; i++) {
        cin >> x >> y;
        ll res = Inf;
        for (auto u : bel[x])
            for (auto v : bel[y])
                res = min(res, u.second + v.second + dis[u.first][v.first]);
        res += w[x] + w[y];
        cout << res << '\n';
    }

    return 0;
}

/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

*/
