#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;

int c, t;

int n, k;
vector<int> G[N];
int dep[N];

int f[N], g[N], cnt[N], ts[N];
bool vis[N], vis1[N];

int mx, tot, p;

void pre(int u, int fa) {
    for(auto v : G[u]) {
        if(v == fa) continue;
        dep[v] = dep[u] + 1;
        pre(v, u);
    }
}

void dfs(int u, int fa, int mid) {
    g[u] = 0x3f3f3f3f;
    f[u] = 0;
    for(auto v : G[u]) {
        if(v == fa) continue;
        dfs(v, u, mid);

        f[u] = max(f[u], f[v] + 1);
        g[u] = min(g[u], g[v] + 1);
        cnt[u] += cnt[v];
        ts[u] += (cnt[v] > 0);
    }

    if(f[u] + g[u] <= mid) f[u] = -1;
    else if(f[u] == mid) vis[u] = 1, g[u] = 0, f[u] = -1;

    tot += vis[u];
    cnt[u] += vis[u];
}

void dfs3(int u, int fa, int cntd) {
    if((cnt[u] && cntd) || vis[u]) vis1[u] = 1, p++;
    for(auto v : G[u]) {
        if(v == fa) continue;
        dfs3(v, u, cntd + cnt[u] - cnt[v]);
    }
}

void dfs2(int u, int fa, int cntd, int mng, int now, int mid) {
    if(vis1[u]) {
        mx = max({mx, g[u]});
    }
    // if(ts[u] + (cntd > 0) >= 2 && now) 
    //     mng = 0, cntd++, now = 0;
    // if(mng > mid + 1) {
    //     mng = min(mng, now ? dep[u] - dep[now] : 0);
    //     if(now) cntd++;
    //     now = 0;
    // }
    // if(vis[u]) {
    //     if(now) mng = min(mng, dep[u] - dep[now]);
    //     now = u;
    // }
    
    int mn[2] = {g[u], 0x3f3f3f3f}, id = u;
    for(auto v : G[u]) {
        if(v == fa) continue;
        if(g[v] < mn[0]) mn[1] = mn[0], mn[0] = g[v], id = v;
        else if(g[v] < mn[1]) mn[1] = g[v];
    }

    for(auto v : G[u]) {
        if(v == fa) continue;

        int nmng = min((v == id ? mn[1] : mn[0]), mng) + 1;
        dfs2(v, u, cntd + cnt[u] - cnt[v] - (now == u), nmng, now, mid);
    }
}

bool check(int mid) {
    mx = tot = p = 0;
    for(int i = 1; i <= n; i++) vis[i] = vis1[i] = cnt[i] = ts[i] = 0;

    dfs(1, 1, mid);

    if(f[1] >= 0) vis[1] = 1, tot++;
    dfs3(1, 1, 0);

    if(tot <= 2) return k >= tot;

    dfs2(1, 1, 0, 0x3f3f3f3f, 0, mid);

    return k >= p;
}

void solve() {
    cin >> n >> k;

    for(int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    dep[1] = 1;
    pre(1, 1);

    int l = 0, r = n, ans = n;
    while(l <= r) {
        int mid = (l + r) >> 1;
        if(check(mid)) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    cout << ans << '\n';

    for(int i = 1; i <= n; i++) G[i].clear(), dep[i] = 0;
}

int main() {
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);

    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> c >> t;

    while(t--) {
        solve();
    }
}