#include <bits/stdc++.h>
using namespace std;

int c, n, m, d, q;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);

    cin >> c >> n >> m >> d >> q;
    vector<int> w(m + 1);
    for (int i = 1; i <= m; ++i) {
        cin >> w[i];
    }
    vector<vector<pair<int, int>>> g(m + 1);
    vector<vector<int>> dis(n + 1, vector<int>(n + 1, 1e9));
    for (int i = 1; i <= n; ++i) {
        int k;
        cin >> k;
        for (int j = 1; j <= k; ++j) {
            int a, t;
            cin >> a >> t;
            g[a].emplace_back(i, t);
        }
    }
    for (int i = 1; i <= n; ++i) {
        dis[i][i] = 0;
    }
    for (int i = 1; i <= m; ++i) {
        for (int j = 0; j < g[i].size(); ++j) {
            for (int k = 0; k < g[i].size(); ++k) {
                int u = g[i][j].first;
                int wu = g[i][j].second;
                int v = g[i][k].first;
                int wv = g[i][k].second;
                if (u == v) {
                    continue;
                }
                dis[u][v] = min(dis[u][v], wu + wv);
                dis[v][u] = min(dis[v][u], wu + wv);
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
    while (q--) {
        int x, y;
        cin >> x >> y;
        vector<int> used1;
        for (int i = 0; i < g[x].size(); ++i) {
            used1.push_back(g[x][i].first);
        }
        vector<int> used2;
        for (int i = 0; i < g[y].size(); ++i) {
            used2.push_back(g[y][i].first);
        }
        int minn = 1e9;
        int ii = used1[0], jj = used2[0];
        for (int i : used1) {
            for (int j : used2) {
                if (minn > dis[i][j]) {
                    minn = dis[i][j];
                    ii = i;
                    jj = j;
                }
            }
        }
        cout << minn + w[x] + w[y] + g[x][ii].second + g[y][jj].second << '\n';
    }
    return 0;
}


// 0 2 5 20 2
// 4 1 9 2 5
// 3 1 5 2 7 4 6
// 3 2 3 3 4 5 7
// 1 3
// 1 2