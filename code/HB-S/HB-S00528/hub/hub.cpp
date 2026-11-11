#include<bits/stdc++.h>

using namespace std;

using i64 = long long;

vector<int> paths[30];
bool vis[30];
int g[30][30];

void dfs(int x) {
    vis[x] = true;
    for (auto &i: paths[x]) {
        if (!vis[i]) {
            dfs(i);
        }
    }
}

int main() {
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    int c, t;
    cin >> c >> t;
    while (t--) {
        int ans = 1 << 30;
        int n, k;
        cin >> n >> k;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                g[i][j] = 1 << 25;
            }
        }
        for (int i = 0; i < n; ++i) {
            g[i][i] = 0;
        }
        for (int i = 0; i < n; ++i) {
            paths[i].clear();
        }
        for (int i = 0; i < n - 1; ++i) {
            int u, v;
            cin >> u >> v;
            --u, --v;
            paths[u].push_back(v);
            paths[v].push_back(u);
            g[u][v] = 1;
            g[v][u] = 1;
        }
        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
                }
            }
        }
        for (int i = 0; i < 1 << n; ++i) {
            vector<int> v;
            for (int j = 0; j < n; ++j) {
                if (i >> j & 1) {
                    v.push_back(j);
                }
            }
            if (v.size() != k) {
                continue;
            }
            memset(vis, 0xff, sizeof(vis));
            for (auto &i: v) {
                vis[i] = 0;
            }
            int p = 0;
            for (auto &i: v) {
                if (!vis[i]) {
                    ++p;
                    dfs(i);
                }
            }
            if (p > 2) {
                continue;
            }
            int res = 0;
            for (int i = 0; i < n; ++i) {
                int now = 1 << 25;
                for (auto &j: v) {
                    now = min(now, g[i][j]);
                }
                res = max(res, now);
            }
            ans = min(ans, res);
        }
        cout << ans << endl;
    }
    return 0;
}