#include <bits/stdc++.h>
#define rep(i,j,k) for (int i = (j); i <= (k); i++)
#define rrep(i,j,k) for (int i = (j); i >= (k); i--)
#define orep(i,j,k) for (int i = (j); i < (k); i++)
#define fi first
#define se second
using namespace std;
using ll = long long;
using pii = pair<int, int>;
template <class T>
using vec = vector<T>;
using veci = vec<int>;

constexpr int N = 200005;
veci g[N];
int n, K, d;
int f[N], dep[N], mxdep[N];
vec<pii> edgs;

void dfs1(int u, int fa) {
    mxdep[u] = dep[u], f[u] = 0;
    for (int v : g[u]) {
        if (v == fa) continue;
        dep[v] = dep[u] + 1;
        dfs1(v, u);
        mxdep[u] = max(mxdep[u], mxdep[v]);
        f[u] += f[v];
    }
    if (mxdep[u] - dep[u] >= d) f[u] += 1;
}

int dfs2(int u, int fa, int x) {
    if (x > d) return K+1;
    int r = max(1, f[u]);
    int f = 0, s = 0;
    for (int v : g[u]) {
        if (v == fa) continue;
        int k = mxdep[v] - dep[u];
        if (k > f) s = f, f = k;
        else if (k > s) s = k;
    }
    for (int v : g[u]) {
        if (v == fa) continue;
        int k = f;
        if (k == mxdep[v] - dep[u]) k = s;
        r = min(r, dfs2(v, u, max(x,k) + 1));
    }
    return r;
}

bool check(int D) {
    d = D;
    for (pii p : edgs) {
        int u = p.fi, v = p.se;
        dep[u] = 0, dep[v] = 0;
        dfs1(u, v), dfs1(v, u);
        int x = dfs2(u, v, 0), y = dfs2(v, u, 0);
        if (x + y <= K) return true;
    }
    dep[1] = 0;
    dfs1(1, 0);
    if (dfs2(1, 0, 0) <= K) return true;
    return false;
}

void solve() {
    cin >> n >> K;
    rep(i, 1, n) {
        g[i].clear();
    }
    edgs.clear();
    rep(i, 1, n-1) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
        edgs.push_back({u, v});
    }
    int L = 0, R = n-1;
    while (L < R) {
        int mid = (L + R) >> 1;
        if (check(mid)) {
            R = mid;
        } else {
            L = mid + 1;
        }
    }
    cout << L << '\n';
}

int main() {
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int c, T;
    cin >> c >> T;
    while (T--) solve();
}