#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int N = 1000010;
int c, T;
int n, k;
vector<int> g[N];
int sz[N];
int dfn[N], dfc;
ll mxdep[N];
int dist[4010][4010];
ll f[4010][4010], dp[4010];
ll ans;
void dfs1(int u, int fa) {
    dfn[u] = ++dfc;
    sz[u] = 1;
    mxdep[u] = 0;
    f[u][1] = 0;
    for (int v : g[u]) if (v != fa) {
        dfs1(v, u);
        for (int i = 1; i <= sz[u] + sz[v]; i++) {
            dp[i] = 1e18;
        }
        for (int i = 1; i <= sz[u]; i++) {
            for (int j = 1; j <= sz[v]; j++) {
                dp[i + j] = min(dp[i + j], max(f[u][i], f[v][j]));
            }
        }
        for (int i = 1; i <= sz[u] + sz[v]; i++) {
            f[u][i] = min(dp[i], max(f[u][i], mxdep[v] + 1));
            dp[i] = 1e18;
        }
        sz[u] += sz[v];
        mxdep[u] = max(mxdep[u], mxdep[v] + 1);
    }
}
void dfs2(int u, int fa, int dist[]) {
    for (int v : g[u]) if (v != fa) {
        dist[v] = dist[u] + 1;
        dfs2(v, u, dist);
    }
}
void solve() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        g[i].clear();
    }
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    ans = 1e18;
    for (int x = 1; x <= n; x++) {
        dfs2(x, 0, dist[x]);
    }
    for (int x = 1; x <= n; x++) {
        dfc = 0;
        dfs1(x, 0);
        ans = min(ans, f[x][k]);
        for (int y : g[x]) {
            for (int z = 1; z <= n; z++) if (z != x) {
                if (dfn[y] <= dfn[z] && dfn[z] < dfn[y] + sz[y]) continue;
                ll cur = 0;
                for (int i = 1; i <= n; i++) {
                    if (dfn[y] <= dfn[i] && dfn[i] < dfn[y] + sz[y]) continue;
                    if (dfn[z] <= dfn[i] && dfn[i] < dfn[z] + sz[z]) continue;
                    cur = max<ll>(cur, min(dist[y][i], dist[z][i]));
                }
                ll mn = 1e18;
                for (int i = max(1, k - sz[z]); i < k && i <= sz[y]; i++) mn = min(mn, max(f[y][i], f[z][k - i]));
                ans = min(ans, max(cur, mn));
                if (ans == 1) {
                    cerr << "";
                }
            }
        }
    }
    cout << ans << "\n";
}
int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    cin >> c >> T;
    while (T--) solve();
}