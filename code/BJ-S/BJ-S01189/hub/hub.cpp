# include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 10;
int n, k;
vector <int> vec[MAXN];
int f[MAXN], g[MAXN], vis[MAXN], fa[MAXN];
void dfs(int u, int fa) {
    ::fa[u] = fa;
    for (int v : vec[u]) if (v != fa) dfs(v, u);
}
int dep[MAXN], mxd, tfa[MAXN];
void dfs2(int u, int fa) {
    tfa[u] = fa;
    dep[u] = dep[fa] + 1;
    if (dep[u] > dep[mxd]) mxd = u;
    for (int v : vec[u]) {
        if (vis[v] || v == fa) continue;
        dfs2(v, u);
    }
}
int dp[MAXN], mx[MAXN], mid;
void dfs3(int u, int fa) {
    mx[u] = 0;
    dp[u] = 1;
    for (int v : vec[u]) {
        if (v == fa || vis[v]) continue;
        dfs3(v, u);
        mx[u] =max(mx[u], mx[v] + 1);
        if (mx[v] + 1 > mid) dp[u] += dp[v];
    }
}
int calc2(int u) {
    dfs3(u, 0);

    return dp[u];
}
int calc(int u) {
    mxd = 0;
    dfs2(u, 0);
    u = mxd;
    dfs2(u, 0);
    int w = dep[mxd] - 1;
    for (int i = 1;i <= w / 2; i++) mxd = tfa[mxd];
    int res = calc2(mxd);
    if (w % 2 == 1) mxd = tfa[mxd];
    res = min(res, calc2(mxd));
    return res;
}
bool check(int mid) {
    ::mid = mid;
    for (int i = 1; i <= n; i++) {
        vis[i] = 0;
    }
    for (int i = 1; i <= n; i++) {
        vis[fa[i]] = 1;
        f[i] = calc(i);
        vis[fa[i]] = 0;
        // cout << f[i] << " " ;
    }
    // cout << endl ;
    for (int i = 1; i <= n; i++) {
        if (fa[i]) {
            vis[i] = 1;
            g[i] = calc(fa[i]);
            vis[i] = 0;
            // cout << g[i] << " " ;
        }
    }
    // cout << endl; 
    int mn = n;
    for (int i = 1;i <= n; i++) {
        if (fa[i]) mn = min(mn, f[i] + g[i]);
    }
    mn = min(mn, f[1]);
    return mn <= k;
}
void solve() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        vec[i].clear();
    }
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        vec[u].push_back(v);
        vec[v].push_back(u);
    }
    dfs(1, 0);
    // cout << check(1) << endl ;
    // return ;
    int l = 1, r = n, ans = n;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (check(mid)) ans = mid, r = mid - 1;
        else l = mid + 1;
    }
    cout << ans << endl ;
}
int main() {
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    int  c, t;
    cin >> c >> t;
    while (t--) {
        solve();
    }
    return 0;
}