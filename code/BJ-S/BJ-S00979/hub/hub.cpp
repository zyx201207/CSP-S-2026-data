#include <bits/stdc++.h>
using namespace std;
constexpr int N = 15;
int c, t, n, k, dis[N], ans;
vector<int> g[N];
bool h[N], vis[N];
void dfs(int x) {
    vis[x] = true;
    for (int y : g[x])
        if (h[y] && !vis[y]) dfs(y);
}
int main() {
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    scanf("%d%d", &c, &t);
    while (t--) {
        scanf("%d%d", &n, &k);
        ans = 2e9;
        for (int i = 1; i <= n; ++i) g[i].clear();
        for (int i = 1; i < n; ++i) {
            int u, v; scanf("%d%d", &u, &v);
            g[u].push_back(v);
            g[v].push_back(u);
        }
        for (int s = 0; s < (1<<n); ++s) {
            if (__builtin_popcount(s) != k) continue;
            memset(h, 0, sizeof(h));
            memset(vis, 0, sizeof(vis));
            for (int i = 0; i < n; ++i)
                if ((s>>i)&1) h[i+1] = true;
            int cnt = 0;
            for (int i = 1; i <= n; ++i)
                if (h[i] && !vis[i]) {
                    ++cnt;
                    dfs(i);
                }
            if (cnt > 2) continue;
            memset(dis, 0x3f, sizeof(dis));
            queue<int> q;
            for (int i = 1; i <= n; ++i)
                if (h[i]) q.push(i), dis[i] = 0;
            while (!q.empty()) {
                int x = q.front(); q.pop();
                for (int y : g[x])
                    if (dis[y] == 0x3f3f3f3f) {
                        dis[y] = dis[x] + 1;
                        q.push(y);
                    }
            }
            ans = min(ans, (*max_element(dis + 1, dis + n + 1)));
        } printf("%d\n", ans);
    }
    return 0;
}