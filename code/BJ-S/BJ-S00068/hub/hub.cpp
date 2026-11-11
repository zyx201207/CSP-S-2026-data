#include <bits/stdc++.h>
using namespace std;
using ll = long long;
vector<int> g[1000005];
int vis[1000005], vis2[1000005], dis[1000005];
void dfs(int u) {
    vis2[u] = 1;
    for (int v : g[u]) {
        if (vis[v] && !vis2[v]) dfs(v);
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    int c, T;
    cin >> c >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        for (int i = 1; i <= n; ++i) {
            g[i].clear();
        }
        for (int i = 1; i < n; ++i) {
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        int all = (1 << n) - 1, mi = 1e9;
        for (int i = 0; i <= all; ++i) {
            if (__builtin_popcount(i) != k) continue;
            for (int j = 1; j <= n; ++j) if ((i >> (j - 1)) & 1) vis[j] = 1;
            for (int j = 1; j <= n; ++j) vis2[j] = 0;
            int cnt = 0;
            for (int j = 1; j <= n; ++j) {
                if (vis[j] && !vis2[j]) {
                    dfs(j);
                    cnt++;
                }
            }
            if (cnt > 2) continue;
            int ma = 0;
            for (int j = 1; j <= n; ++j) {
                for (int k = 1; k <= n; ++k) dis[k] = 1e9;
                queue<int> q;
                dis[i] = 0;
                q.push(i);
                while (!q.empty()) {
                    int u = q.front();
                    q.pop();
                    if (vis[u]) {
                        ma = max(ma, dis[u]);
                        break;
                    }
                    for (int v : g[u]) {
                        if (dis[u] + 1 < dis[v]) {
                            dis[v] = dis[u] + 1;
                            q.push(v);
                        }
                    }
                }
                mi = min(mi, ma);
            }
        }
        cout << mi << endl;
    }
    return 0;
}