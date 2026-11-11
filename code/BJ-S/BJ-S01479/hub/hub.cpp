#include <iostream>
#include <vector>
using namespace std;
struct Edge {
    int u, v;
} eg[4005];
int fa[4005], n, k;
bool used[4005], vis[4005];
vector<int> g[4005];
int find(int x) {
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}
void merge(int x, int y) {
    x = find(x), y = find(y);
    if (x == y) return ;
    fa[x] = y;
}
int dist = 1e9;
void walk(int u, int d, int p) {
    if (used[u]) {
        dist = min(d, dist);
        return ;
    }
    for (int v : g[u]) {
        if (v == p) continue;
        walk(v, d + 1, u);
    }
}
int calc() {
    int res = 0;
    for (int i = 1; i <= n; i++) {
        dist = 1e9;
        walk(i, 0, 0);
        res = max(res, dist);
    }
    return res;
}
int ans = 1e9;
void dfs(int u, int sele) {
    if (u == n + 1) {
        if (sele != k) return ;
        for (int i = 1; i <= n; i++) fa[i] = i, vis[i] = false;
        for (int i = 1; i < n; i++) {
            if (used[eg[i].u] && used[eg[i].v]) {
                merge(eg[i].u, eg[i].v);
            }
        }
        int scccnt = 0;
        for (int i = 1; i <= n; i++) {
            if (used[i]) {
                if (!vis[find(i)]) vis[find(i)] = true, scccnt++;
            }
        }
        if (scccnt <= 2) {
            ans = min(ans, calc());
        }
        return ;
    }
    dfs(u + 1, sele);
    used[u] = true;
    dfs(u + 1, sele + 1);
    used[u] = false;
}
void solve() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        g[i].clear();
    }
    for (int i = 1; i < n; i++) {
        cin >> eg[i].u >> eg[i].v;
        g[eg[i].u].push_back(eg[i].v);
        g[eg[i].v].push_back(eg[i].u);
    }
    ans = 1e9;
    dfs(1, 0);
    cout << ans << endl;
}
int main() {
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    int _, T;
    cin >> _ >> T;
    while (T--) solve();
} // 15pts?
