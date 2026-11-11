#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vec;
constexpr int N = 2000005;
int n, k;
vec adj[N];
int f[N], dep[N], mxd[N], se[N], son[N];
int R;
void dfs0(int p) {
    dep[p] = dep[f[p]] + 1;
    if (dep[p] > dep[R])
        R = p;
    for (int v : adj[p]) {
        if (v == f[p])
            continue;
        f[v] = p;
        dfs0(v);
    }
}
int vis[N], bel[N];
int g[N];
inline void upd(int *a, int x) {
    if (x >= a[0])
        a[1] = a[0], a[0] = x;
    else if (x > a[1])
        a[1] = x;
}
void dfs1(int p) {
    mxd[p] = son[p] = 0;
    int mx[2] = {0, 0};
    for (int v : adj[p]) {
        if (vis[v] || v == f[p])
            continue;
        f[v] = p;
        bel[v] = bel[p];
        dfs1(v);
        if (mxd[p] < mxd[v] + 1)
            mxd[p] = mxd[v] + 1, son[p] = v;
        upd(mx, mxd[v] + 1);
    }
    se[p] = mx[1];
}
void dfs2(int p) {
    int mx[2] = {0, 0};
    for (int v : adj[p]) {
        if (vis[v] || v == f[p])
            continue;
        upd(mx, mxd[v] + 1);
    }
    // cerr << p << ' ' << mxd[p] << ',' << g[p] << ' ' << mx[0] << ',' << mx[1] << "????\n";
    for (int v : adj[p]) {
        if (vis[v] || v == f[p])
            continue;
        g[v] = max(g[p], mx[mx[0] == mxd[v] + 1]) + 1;
        // cerr << p << "->" << v << ' ' << mx[0] << ',' << mx[1] << ' ' << (mx[0] == mxd[v] + 1) << '\n';
        dfs2(v);
    }
}
int len;
vec a;
int val[N];
int s[N], cl[N], cr[N], ml[N];
inline void upd(int &x, int y) {
    x = max(x, y);
}
bool chk(int d) {
    // cerr << "chk " << d << ":\n";
    memset(s, 0, sizeof(int) * (len + 1));
    memset(ml, 0, sizeof(int) * (len + 1));
    for (int i = 1; i <= n; i++) {
        if (vis[i])
            continue;
        if (mxd[i] >= d)
            ++s[bel[i]];
    }
    for (int i = 1; i <= len; i++)
        s[i] += s[i - 1];
    for (int i = 0; i <= len; i++) {
        if (i < len)
            cl[i] = max(1, s[i] + max(0, i - d + 1));
        if (i)
            cr[i] = max(1, s[len] - s[i - 1] + max(0, len - i - d + 1));
        if (val[i] < d) {
            int to = d + i - val[i] + 1;
            if (to <= len)
                upd(ml[to], i + val[i] - d);
        } else if (i < len)
            upd(ml[i + 1], i);
        // cerr << cl[i] << ',' << cr[i] << ' ' << val[i] << '\n';
    }
    for (int i = 1; i <= len; i++) {
        // cerr << ml[i] << ',' << i << '\n';
        upd(ml[i], ml[i - 1]);
        if (cl[ml[i]] + cr[i] <= k)
            return 1;
    }
    for (int i = 0; i <= len; i++) {
        if (val[i] <= d || se[a[i]] > d)
            continue;
        int x = son[a[i]];
        int ad = 0;
        while (son[x] && mxd[son[x]] >= d && g[son[x]] <= d)
            x = son[x], ++ad;
        // cerr << i << ' ' << x << ' ' << son[x] << ' ' << ad << ' ' << s[len] << ' ' << max(0, i - d) + max(0, len - i - d) + 1 << "?\n";
        if (s[len] - ad + max(0, i - d) + max(0, len - i - d) + 1 <= k)
            return 1;
    }
    return 0;
}
void work() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        adj[i].clear();
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
    int pl, pr;
    R = f[1] = 0;
    dfs0(1);
    pl = R;
    R = f[pl] = 0;
    dfs0(pl);
    pr = R;
    int p = pr;
    a.clear();
    memset(vis + 1, 0, sizeof(int) * n);
    while (p) {
        vis[p] = 1;
        a.emplace_back(p);
        p = f[p];
    }
    len = a.size() - 1;
    // cerr << len << "??\n";
    for (int i = 0; i <= len; i++) {
        int x = a[i];
        // cerr << x << ' ';
        f[x] = 0;
        bel[x] = i;
        g[x] = -1;
        dfs1(x);
        for (int v : adj[x]) {
            if (vis[v])
                continue;
            g[v] = 0;
            dfs2(v);
        }
        val[i] = mxd[x];
    }
    // cerr << '\n';
    int l = 0, r = len;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (chk(mid))
            r = mid - 1;
        else
            l = mid + 1;
    }
    cout << l << '\n';
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    int c, T;
    cin >> c >> T;
    while (T--)
        work();
    return 0;
}