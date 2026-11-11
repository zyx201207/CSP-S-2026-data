#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
constexpr int MAXN = 1e6 + 5;
int n, k, lim, dp[MAXN];
vector<int> G[MAXN];
int len[MAXN], smx[MAXN], son[MAXN];
void dfs(int u, int fa) {
    son[u] = 0, smx[u] = 0;
    for (int v : G[u]) if (v != fa) {
        dfs(v, u);
        if (len[son[u]] < len[v]) smx[u] = len[son[u]], son[u] = v;
        else smx[u] = max(smx[u], len[v]);
    }
    len[u] = len[son[u]] + 1, ++smx[u];
}
void DP(int u, int fa) {
    dp[u] = (len[u] > lim);
    for (int v : G[u]) if (v != fa) {
        DP(v, u);
        dp[u] += dp[v];
    }
}
int cur, dep[MAXN];
bool DFS(int u, int fa, int mx) {
    dep[u] = dep[fa] + 1;
    if (mx > lim) return false;
    if (cur + dp[u] + (len[u] <= lim) <= k) return true;
    for (int v : G[u]) if (v != fa) {
        int to = mx + 1;
        int x = (v == son[u] ? smx[u] : len[u]);
        if (x - 1 + dep[u] > lim) to = max(to, x);
        if (DFS(v, u, to)) return true;
    }
    return false;
}
bool check() {
    for (int u = 1; u <= n; ++u) {
        dfs(u, 0), DP(u, 0);
        if (dp[u] <= k) return true;
        dep[u] = 0;
        for (int v : G[u]) {
            cur = dp[u] - dp[v] + (len[u] <= lim);
            // cerr << u << ' ' << v << ' ' << cur << '\n';
            if (DFS(v, u, -1e9)) return true;
        }
    }
    return false;
}
int main() {
    IOS;
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    int c, T; cin >> c >> T;
    while (T--) {
        cin >> n >> k;
        for (int i = 1; i <= n; ++i) vector<int>().swap(G[i]);
        for (int i = 1, u, v; i < n; ++i) cin >> u >> v, G[u].emplace_back(v), G[v].emplace_back(u);
        // lim = 1, cerr << check() << '\n';
        int L = 0, R = n, mid, ans = n;
        while (L <= R) {
            mid = (L + R) >> 1;
            lim = mid;
            if (check()) ans = mid, R = mid - 1;
            else L = mid + 1;
        }
        cout << ans << '\n';
    }
    return 0;
}
/*
0 1
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10
*/