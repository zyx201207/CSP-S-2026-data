#include <bits/stdc++.h>
#define For(i, j, k) for (int i = j; i <= k; ++ i)
#define Rof(i, j, k) for (int i = j; i >= k; -- i)
#define eb emplace_back
using namespace std;
using ll = long long;
using db = double;
using vi = vector<int>;
const int N = 1e6 + 10, inf = 0x3f3f3f3f;
int c, t, n, k, ans = inf;
vi g[N];
bool st[N], vis[N];
void dfs(int u, int fa) {
    if (st[u]) return;
    vis[u] = 1;
    For (i, 0, (int)g[u].size() - 1) {
        int v = g[u][i];
        if (!vis[v] && v != fa) dfs(v, u);
    }
}
int mxd = 0, dis[N];
void dfs2(int u, int fa) {
    if (st[u]) return;
    dis[u] = dis[fa] + 1;
    mxd = max(mxd, dis[u]);
    // cout << "DEDe" << dis[u] << '\n';
    For (i, 0, (int)g[u].size() - 1) {
        int v = g[u][i];
        if (v != fa) dfs(v, u);
    }
}
void work() {
    if (c >= 13 && c <= 14) {
        return ;
    }
    cin >> n >> k;
    For (i, 1, n) g[i].clear();
    For (i, 1, n) dis[i] = st[i] = vis[N] = 0;
    ans = inf;
    For (i, 1, n - 1) {
        int u, v; cin >> u >> v;
        g[u].eb(v), g[v].eb(u);
    }
    For (msk, 0, (1 << n) - 1) {
        int cnt = 0;
        For (i, 0, n + 1) dis[i] = st[i] = vis[i] = 0;
        For (i, 0, n - 1) {
            if ((msk >> i) & 1) {
                cnt ++ ;
                st[i + 1] = 1;
            }
        } 
        if (cnt != k) continue;
        cnt = 0;
        For (i, 1, n) {
            if (!vis[i] && st[i] == 0) {
                cnt ++ ;
                dfs(i, 0);
            }
        }
        if (cnt > 2) continue;
        // For (i, 0, n - 1) {
        //     cout << ((msk >> i) & 1) << ' ';
        // } cout << '\n';
        int mx = 0;
        For (i, 1, n) {
            if (!st[i]) {
                // cout << "!begin" << i << '\n'; 
                mxd = 0, dis[0] = -1;
                dfs2(i, 0);
                mx = max(mx, mxd);
            }
        }
        ans = min(ans, mx);
    } cout << ans << '\n';
}
int main() {
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> c >> t;
    while (t -- ) work();
    return 0;
}