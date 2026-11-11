#include <bits/stdc++.h>
using namespace std;
#define N 5005

int T, n, k, dis[N][N];
vector<int> e[N]; bool b[N], vis[N];

void dfs1(int u, int st, int fa) {
    for (int v : e[u]) if (v != fa) dis[st][v] = dis[st][u] + 1, dfs1(v, st, u);
} void dfs2(int u, int fa) { vis[u] = 1; for (int v : e[u]) if (v != fa && b[v]) dfs2(v, u); }

int main() {
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    scanf("%*d%d", &T);
    while (T--) {
        scanf("%d%d", &n, &k);
        for (int i = 1; i <= n; i++) e[i].clear();
        for (int i = 1; i < n; i++) {
            int u, v;
            scanf("%d%d", &u, &v);
            e[u].push_back(v);
            e[v].push_back(u);
        } for (int i = 1; i <= n; i++) dfs1(i, i, 0);
        int ans = (1 << 30);
        for (int i = 3; i < (1 << n); i++) {
            int ct = 0; for (int x = i; x; ++ct, x -= x & -x); if (ct != k) continue;
            for (int j = 1; j <= n; j++) {
                if ((i >> (j - 1)) & 1) b[j] = 1; else b[j] = 0;
                vis[j] = 0;
            } ct = 0; for (int j = 1; j <= n; j++) if (b[j] && !vis[j]) ++ct, dfs2(j, 0);
            if (ct > 2) continue;
            int res = 0;
            for (int i = 1; i <= n; i++) {
                int tot = (1 << 30);
                for (int j = 1; j <= n; j++) if (b[j]) tot = min(tot, dis[i][j]);
                res = max(res, tot);
            } ans = min(ans, res);
        } printf("%d\n", ans);
    }
    return 0;
}