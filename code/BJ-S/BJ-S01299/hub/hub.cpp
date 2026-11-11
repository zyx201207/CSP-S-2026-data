#include <bits/stdc++.h>
using namespace std;

constexpr int maxn = 1e6 + 25;
void brute(int n, int k, const vector<vector<int>>& adj) {
    int ans = INT_MAX;
    queue<int> que;
    vector<int> dis(n + 1);
    bitset<maxn> select, vis;
    auto isvalid = [&]() {
        vis.reset();
        int cnt = 0;
        for (int i = 1; i <= n; ++i) {
            if (select[i] && !vis[i]) {
                ++cnt;
                if (cnt > 2) {
                    return false;
                }
                while (que.size()) { que.pop(); }
                que.push(i);
                while (!que.empty()) {
                    auto u = que.front();
                    que.pop();
                    for (auto v : adj[u]) {
                        if (select[v] && !vis[v]) {
                            vis[v] = true;
                            que.push(v);
                        }
                    }
                }
            }
        }
        return true;
    };
    auto contrib = [&]() {
        if (isvalid()) {
            while (que.size()) { que.pop(); }
            fill(dis.begin(), dis.end(), -1);
            for (int i = 1; i <= n; ++i) {
                if (select[i]) {
                    que.push(i);
                    dis[i] = 0;
                }
            }
            int radius = 0;
            while (!que.empty()) {
                auto u = que.front();
                que.pop();
                radius = max(radius, dis[u]);
                for (auto v : adj[u]) {
                    if (dis[v] == -1) {
                        dis[v] = dis[u] + 1;
                        que.push(v);
                    }
                }
            }
            ans = min(ans, radius);
        }
    };
    function<void(int, int)> dfs = [&](int cur, int tot) {
        if (tot == k) {
            contrib();
            return;
        }
        if (cur == n + 1) {
            return;
        }
        select[cur] = true;
        dfs(cur + 1, tot + 1);
        select[cur] = false;
        dfs(cur + 1, tot);
    };
    dfs(1, 0);
    printf("%d\n", ans);
}


int main() {
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    ios::sync_with_stdio(false);
    int c, t;
    scanf("%d%d", &c, &t);
    while (t--) {
        int n, k;
        scanf("%d%d", &n, &k);
        vector<vector<int>> adj(n + 1);
        for (int i = 1; i < n; ++i) {
            int u, v;
            scanf("%d%d", &u, &v);
            adj[u].emplace_back(v);
            adj[v].emplace_back(u);
        }
        brute(n, k, adj);
    }
    return 0;
}