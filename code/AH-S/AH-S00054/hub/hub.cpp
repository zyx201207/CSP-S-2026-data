#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define _pair array<int, 2>
#define For(i, l, r) for (auto i = (l); i <= (r); ++i)
#define Rep(i, r, l) for (auto i = (r); i >= (l); --i)
#define pb push_back
#define forT() int _; for (cin >> _; _--; solve())
template<typename T> void cmax(T& x, T y) { x = max(x, y); }
template<typename T> void cmin(T& x, T y) { x = min(x, y); }
#define N 5050
vector<int> g[N];
int n, k;
int dp[N], w[N], dep[N], mdis[N];
void dfs(int u, int fa, int x) {
    dep[u] = dep[fa] + 1;
    for (auto&v : g[u]) {
        if (v == fa) continue;
        dfs(v, u, x);
        cmax(w[u], w[v] + 1);
        dp[u] += dp[v];
    }
    if (dp[u] || w[u] >= x) dp[u]++;
}
int c[N];
void dfs2(int u, int fa, int col) {
    _pair mx {-1, -1}, cmx{-1, -1};
    c[u] = col;
    for (auto&v : g[u]) {
        if (v == fa) continue;
        if (mx <= _pair{w[v], v}) {
            cmx = mx; mx = {w[v], v};
        }
        else cmax(cmx, {w[v], v});
    }
    for (auto&v : g[u]) {
        if (v == fa) continue;
        if (mx[1] != v) cmax(mdis[v], mx[0] + 2);
        else if (cmx[1] != -1) cmax(mdis[v], cmx[0] + 2);
    }
    for (auto&v : g[u]) {
        if (v != fa) {
            cmax(mdis[v], mdis[u] + 1);
            dfs2(v, u, col);
        }
    }
}
int dd[N][N], top[N];
bool check(int x) {
    For (rt, 1, n) {
        For (i, 1, n) dp[i] = w[i] = mdis[i] = top[i] = 0;
        dfs(rt, 0, x);
        if (dp[rt] <= k) return 1;
        priority_queue<_pair, vector<_pair>, greater<_pair>> pq;
        for (auto&v : g[rt]) {
            pq.push({w[v], v});
            if (pq.size() > 3) pq.pop();
        }
        _pair mx{-1, -1}, cmx{-1, -1}, ccmx{-1, -1};
        if (pq.size()) mx = pq.top(), pq.pop();
        if (pq.size()) cmx = pq.top(), pq.pop();
        if (pq.size()) ccmx = pq.top(), pq.pop();
        for (auto&v : g[rt]) dfs2(v, rt, v);
        For (i, 1, n) {
            if (mdis[i] > x) continue;
            dd[dep[i]][++top[dep[i]]] = i;
        }
        For (i, 2, n) {
            For (j, i, i + 1) {
                For (u, 1, top[i]) {
                    For (v, 1, top[j]) {
                        int uu = dd[i][u], vv = dd[j][v];
                        if (uu == vv) continue;
                        auto mmx = mx;
                        if (c[uu] == mx[1]) mmx = cmx;
                        if (c[vv] == mx[1]) mmx = cmx;
                        if (c[uu] == cmx[1] && mmx == cmx) mmx = ccmx;
                        if (c[vv] == cmx[1] && mmx == cmx) mmx = ccmx;
                        if (dp[uu] + dp[vv] > k) continue;
                        if (mmx[1] == -1 || dep[uu] + mmx[0] <= x) return 1;
                        if (mmx[1] != -1 && dep[vv] + mmx[0] <= x) return 1;
                    } 
                }
            }
        }
    }
    return 0;
}
void solve() {
    cin >> n >> k;
    For (i, 1, n) g[i].clear();
    For (i, 2, n) {
        int u, v; cin >> u >> v;
        g[u].pb(v); g[v].pb(u);
    }
    // if (n == k) {
    //     cout << 0 << '\n'; return;
    // }
    int ans = -1;
    for (int l = 1, r = n; l <= r; ) {
        int mid = l + r >> 1;
        if (check(mid)) ans = mid, r = mid - 1;
        else l = mid + 1;
    }
    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    int c; cin >> c;
    forT();
    return 0;
}
