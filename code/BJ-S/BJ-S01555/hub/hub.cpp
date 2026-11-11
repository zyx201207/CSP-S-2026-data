#include <bits/stdc++.h>
using namespace std;
const int MAXN = 25;
vector<int> adj[MAXN];
int n, k;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    int c, t;
    cin >> c >> t;
    while (t--) {
        cin >> n >> k;
        for (int i = 1; i <= n; i++) adj[i].clear();
        for (int i = 1; i < n; i++) {
            int u, v; cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int ans = n;
        vector<int> comb(k);
        function<void(int, int)> dfs = [&](int idx, int start) {
            if (idx == k) {
                set<int> st(comb.begin(), comb.end());
                vector<bool> vis(n + 1, false);
                int blocks = 0;
                for (int x : comb) {
                    if (vis[x]) continue;
                    blocks++;
                    queue<int> q; q.push(x); vis[x] = true;
                    while (!q.empty()) {
                        int u = q.front(); q.pop();
                        for (int v : adj[u]) {
                            if (st.count(v) && !vis[v]) {
                                vis[v] = true;
                                q.push(v);
                            }
                        }
                    }
                }
                if (blocks > 2) return;
                vector<int> d(n + 1, -1);
                queue<int> q;
                for (int x : comb) {
                    d[x] = 0;
                    q.push(x);
                }
                while (!q.empty()) {
                    int u = q.front(); q.pop();
                    for (int v : adj[u]) {
                        if (d[v] == -1) {
                            d[v] = d[u] + 1;
                            q.push(v);
                        }
                    }
                }
                int maxd = 0;
                for (int i = 1; i <= n; i++) maxd = max(maxd, d[i]);
                ans = min(ans, maxd);
                return;
            }
            for (int i = start; i <= n; i++) {
                comb[idx] = i;
                dfs(idx + 1, i + 1);
            }
        };
        dfs(0, 1);
        cout << ans << "\n";
    }
    return 0;
}

