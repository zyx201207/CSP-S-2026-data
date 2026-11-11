#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define endl '\n'
#define CONTEST

int c;
const int inf = 2e18;
int lowbit(int x) {
    return x & -x;
}
int popcount(int x) {
    int cnt = 0;
    while (x) x -= lowbit(x), cnt++;
    return cnt;
}
void solve() {
    int n, k; cin >> n >> k;
    vector<vector<int>> g(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v; u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int i = 0; i < n - 1; i++) {
        for (int v : g[i]) {
            cerr << i << " -> " << v << endl;
        }
    }
    int ans = inf;
    int all = (1LL << n);
    for (int mask = 0; mask < all; mask++) {
        if (lowbit(mask) != k) continue;
        vector<bool> ky(n);
        for (int i = 0; i < n; i++) {
            if ((mask >> i) & 1) 
                ky[i] = true;
        }
        vector<bool> vis(n);
        auto dfs = [&](auto&& dfs, int u) -> void {
            for (int v : g[u]) {
                cerr << "Debug: " << u << " " << v << endl;
                if (vis[v] || !ky[v]) continue;
                vis[v] = true;
                dfs(dfs,v);
            }
        };
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (!vis[i] && ky[i]) {
                cnt++; dfs(dfs, i);
            }
        }
        if (cnt > 2) continue;
        int r2;
        int max_dis = 0;
        vis.assign(n, false);
        auto dfs2 = [&](auto&& dfs2, int u, bool pass, int dis) -> void {
            vis[u] = true;
            if (pass) r2 = u;
            max_dis = max(max_dis, dis);
            for (int v : g[u]) {
                if (vis[v]) continue;
                dfs2(dfs2, v, pass | (ky[u] && !ky[v]), (pass | (ky[u] && !ky[v]) ? dis + 1 : 0));
            }
        };
        dfs2(dfs2, 0, false, 0);
        dfs2(dfs2, r2, false, 0);
        ans = min(ans, max_dis);
    }
    cout << ans << endl;
}
signed main() {
    #ifdef CONTEST
    #ifndef LOCAL
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    #endif
    #endif

    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> c;
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;   
}
// CSP-S 2026 RP++