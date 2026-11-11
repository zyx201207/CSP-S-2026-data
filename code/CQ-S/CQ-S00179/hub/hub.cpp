// Author: lzm0107
// 18:26

#include <bits/stdc++.h>
#include <cassert>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);

    int c, t;
    cin >> c >> t;
    for (int tid = 1; tid <= t; tid++) {
        int n, k;
        cin >> n >> k;
        vector<pair<int, int>> edges(n - 1);
        vector<vector<int>> adj(n);
        for (int i = 0; i < n - 1; i++) {
            cin >> edges[i].first >> edges[i].second;
            edges[i].first--;
            edges[i].second--;
            adj[edges[i].first].push_back(edges[i].second);
            adj[edges[i].second].push_back(edges[i].first);
        }
        int ans = numeric_limits<int>::max();
        for (int s = 0; s < 1 << n; s++) {
            if (__builtin_popcount(s) != k) { continue; }
            vector<int> parent(n);
            iota(parent.begin(), parent.end(), 0);
            auto get_root = [&](auto &&self, int u) -> int {
                return (u == parent[u] ? u : parent[u] = self(self, parent[u]));
            };
            auto unite = [&](int u, int v) -> void {
                u = get_root(get_root, u);
                v = get_root(get_root, v);
                parent[u] = v;
            };
            for (int e = 0; e < n - 1; e++) {
                int u = edges[e].first, v = edges[e].second;
                if ((s >> u & 1) && (s >> v & 1)) {
                    unite(u, v);
                }
            }
            int cnt = 0;
            for (int i = 0; i < n; i++) {
                if ((s >> i & 1) && parent[i] == i) {
                    cnt++;
                }
            }
            if (cnt > 2) { continue; }
            int dist = 0;
            for (int u = 0; u < n; u++) {
                if (s >> u & 1 ^ 1) {
                    int mdst = numeric_limits<int>::max();
                    vector<uint8_t> vis(n);
                    queue<pair<int, int>> que;
                    que.emplace(u, 0);
                    vis[u] = true;
                    while (!que.empty()) {
                        int t = que.front().first, d = que.front().second;
                        que.pop();
                        for (auto v : adj[t]) {
                            if (s >> v & 1) {
                                mdst = d + 1;
                                while (!que.empty()) { que.pop(); }
                                break;
                            }
                            if (!vis[v]) {
                                vis[v] = true;
                                que.emplace(v, d + 1);
                            }
                        }
                    }
                    dist = max(dist, mdst);
                }
            }
            ans = min(ans, dist);
        }
        cout << ans << '\n';
    }
    return 0;
}