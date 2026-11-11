#include <bits/stdc++.h>
#define int long long
#define loop(i, a, b) for(int i = (a) ; i <= (b) ; i++)
#define rloop(i, a, b) for(omt i = (a) ; i >= (b) ; i--)
#define chkmax(x, y) ((x) = max((x), (y)))
#define chkmin(x, y) ((x) = min((x), (y)))
#define mid (((l) + (r)) / 2)
#define lowbit ((x) & (-(x)))
using namespace std;
const int N = 40;
int n, k, d[N];
vector<int> a[N];
bool cs[N], vis[N];
void dfs(int u) {
    vis[u] = 1;
    for(int v : a[u]) {
        if(vis[v]) continue;
        dfs(v);
    }
}
int bfs() {
    loop(i, 1, n) d[i] = 0x3f3f3f3f3f3f3f3fll, vis[i] = 0;
    queue<int> q;
    loop(i, 1, n) {
        if(cs[i]) d[i] = 0, q.push(i), vis[i] = 1;
    }
    while(q.size()) {
        int u = q.front(); q.pop();
        for(int v : a[u]) {
            if(vis[v]) continue;
            d[v] = d[u] + 1;
            vis[v] = 1;
            q.push(v);
        }
    }
    int ans = -0x3f3f3f3f3f3f3f3fll;
    loop(i, 1, n) chkmax(ans, d[i]);
    return ans;
}
int check() {
    loop(i, 1, n) vis[i] = 0;
    int cnt = 0;
    loop(i, 1, n) {
        if(vis[i]) continue;
        dfs(i), cnt++;
    }
    if(cnt != 2) return 0x3f3f3f3f3f3f3fll;
    return bfs();
}
void solve() {
    cin >> n >> k;
    loop(i, 1, n) a[i].clear();
    loop(i, 1, n - 1) {
        int u, v; cin >> u >> v;
        a[u].push_back(v), a[v].push_back(u);
    }
    int ans = 0x3f3f3f3f3f3f3f3fll;
    loop(j, 0, (1 << n) - 1) {
        int cnt = 0;
        loop(i, 1, n) {
            cs[i] = ((j >> (i - 1)) & 1);
            cnt += cs[i];
        }
        if(cnt != k) continue;
        chkmin(ans, check());
    }
    cout << ans << '\n';
}
signed main() {
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int c, t; cin >> c >>  t; while(t--)
    solve();
    return 0;
}