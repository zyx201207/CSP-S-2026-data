#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 1e6 + 5;
int n, k; vector <int> g[N];
// 显然二分，要求就是 dis(i) <= x。k=2 意味着你需要选出两个点，所有点到这两个点都不能 > x
namespace SOL1 {
    #define N 15
    vector <int> p, q; int dis[N][N]; bool vis[N], tag[N];
    void dfs(int u, int fa) {
        tag[u] = 1;
        for (int v : g[u]) if (v != fa && vis[v]) dfs(v, u);
    }
    bool check(int k) {
        for (int x : q) {
            int dd = 1e9;
            for (int y : p) dd = min(dd, dis[x][y]);
            if (dd > k) return false;
        } return true;
    }
    void solve() {
        memset(dis, 0x3f, sizeof dis);
        for (int i = 1; i <= n; i++) { for (int j : g[i]) dis[i][j] = 1; dis[i][i] = 0; }
        for (int k = 1; k <= n; k++) {
            for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) {
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        } int res = 1e9;
        for (int s = 0; s < (1 << n); s++) if (__builtin_popcount(s) == k) {
            p.clear(); q.clear(); int tot = 0;
            for (int i = 1; i <= n; i++) vis[i] = tag[i] = 0;
            for (int i = 1; i <= n; i++) if (s >> (i - 1) & 1) p.push_back(i), vis[i] = 1; else q.push_back(i);
            for (int x : p) if (!tag[x]) dfs(x, 0), tot++;
            if (tot <= 2) {
                int l = 0, r = n, ans = -1;
                while (l <= r) {
                    int mid = (l + r) >> 1;
                    if (check(mid)) r = mid - 1, ans = mid;
                    else l = mid + 1;
                } res = min(res, ans);
            }
        } cout << res << '\n';
    }
    #undef N
}
namespace SOL2 {
    int k, tot; bool tag[N];
    int dfs(int u, int fa) {
        int mx = 0; set <int> st;
        for (int v : g[u]) if (v != fa) {
            int tt = dfs(v, u); if (tt == -1) return -1;
            if (tag[v]) tag[u] = 1, st.insert(tt);
            mx = max(mx, tt);
        } 
        // cout << "!! " << u << ' ' << mx << ' ' << tot << '\n';
        // for (auto x : st) cout << x << ' '; if (st.size()) cout << '\n';
        assert(st.size() <= 2);
        if (st.size()) {
        	if (((mx + *st.rbegin()) / 2 > k) ||
        	(st.size() == 2 && (*st.begin() + *st.rbegin() + 1) / 2 > k)) tot++, tag[u] = 1, mx = -1;
        }
        else if (mx == k) tot++, tag[u] = 1, mx = -1;
        // if (u == 1) cout << "?? " << tot << '\n';
        if (tot > 2) return -1; return mx + 1;
    }
    bool check(int x) {
    	for (int i = 1; i <= n; i++) tag[i] = 0;
        k = x; tot = 0;
        return dfs(1, 0) != -1;
    }
    void solve() {
    	// cout << check(1) << '\n';
        int l = 0, r = n, ans = -1;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (check(mid)) r = mid - 1, ans = mid;
            else l = mid + 1;
        } cout << ans << '\n';
    }
}

signed main() {
    freopen("hub.in", "r", stdin); freopen("hub.out", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int _, T; for (cin >> _ >> T; T--; ) {
        cin >> n >> k;
        for (int i = 1; i <= n; i++) g[i].clear();
        for (int i = 1, x, y; i < n; i++) {
            cin >> x >> y;
            g[x].push_back(y); g[y].push_back(x);
        }
        if (n <= 10) SOL1::solve();
        else if (k == 2) SOL2::solve();
        // else if (n <= 10) SOL1::solve();
        // else cout << n << ' ' << k << '\n';
    }
    return 0;
}