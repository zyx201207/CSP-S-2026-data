#include <bits/stdc++.h>
#define int long long
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
const int N = 1e6 + 10, oo = 1e18;
int T, n, m, hve[N], ned[N], sz[N], mxs[N], RT, root, s, mx;
bool vis[N];
vector<int> g[N], rts;
void init(int u, int fa) {
    sz[u] = 1;
    for (int v : g[u]) {
        if (v == fa)
            continue;
        init(v, u);
        sz[u] += sz[v];
        mxs[u] = max(mxs[u], sz[v]);
    }
    mxs[u] = max(mxs[u], n - sz[u]);
    if (mxs[u] < mxs[RT])
        RT = u;
}
void bfs() {
    queue<int> q;
    q.push(RT);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        vis[u] = true;
        rts.push_back(u);
        if (rts.size() > 10)
            return;
        for (int v : g[u])
            if (!vis[v])
                q.push(v);
    }
}
void dfs(int u, int fa, int mid) {
    hve[u] = oo, ned[u] = 1;
    for (int v : g[u]) {
        if (v == fa)
            continue;
        dfs(v, u, mid);
        if (hve[v] != oo) {
            hve[u] = min(hve[u], hve[v] + 1);
            if (hve[v] > mid)
                ned[u] = max(ned[u], ned[v] - hve[v] + 1);
        }
        else
           ned[u] = max(ned[u], ned[v] + 1);
    }
    if (hve[u] != oo) {
        if (ned[u] + hve[u] - 1 <= mid)
            ned[u] = 0;
        else { 
           ned[u] = hve[u] = 0;
            root = u;
        }
    } else if (ned[u] > mid) {
        ned[u] = hve[u] = 0;
        root = u;
    }
}
int dfs2(int u, int fa) {
    int cnt = 0, son = 0;;
    for (int v : g[u]) {
        if (v == fa)
            continue;
        int ret = dfs2(v, u);
        if (ret) {
            cnt = max(cnt, ret + 1);
            son++;
        }
    }
    if (son >= 2 or !hve[u]) {
        mx = max(mx, cnt - 2);
        cnt = 1;
    }
    if (cnt)
        s++;
    return cnt;
}
bool check(int mid) {
    int ret = oo;
    for (int rt : rts) {
        root = 0;
        dfs(rt, 0, mid);
        s = mx = 0;
        dfs2(root, 0);
        ret = min(ret, s - mx);
    }
    return ret <= m;
}
void clear() {
    for (int i = 1; i <= n; i++) {
        g[i].clear();
        sz[i] = mxs[i] = 0;
    }
    rts.clear();
}
void solve() {
    clear();
    cin >> n >> m;
    for (int i = 1, u, v; i < n; i++) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    mxs[RT = 0] = oo;
    init(1, 0);
    bfs();
    int l = -1, r = n;
    while (l + 1 < r) {
        int mid = l + r >> 1;
        check(mid) ? r = mid : l = mid;
    }
    cout << r << "\n";
}
signed main() {
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    IOS;
    cin >> T >> T;
    while (T--)
        solve();
    return 0;
}
/*
Goodbye, CSP. 
maybe 100 + 100 + 100 + 30
*/