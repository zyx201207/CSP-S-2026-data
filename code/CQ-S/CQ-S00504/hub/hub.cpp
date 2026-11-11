#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
#define endl '\n'
#define eb emplace_back
#define pb push_back
#define all(x) x.begin(), x.end()
const int N = 1e6 + 10;
int n, k;
vector<int> g[N];
bool mark[N], vis[N];
int siz[N];
void dfs (int u) {
    vis[u] = 1;
    for (int v : g[u]) {
        if (!vis[v] && mark[v]) dfs(v);
    }
}
int dis[110][110];
void init (int u, int from, int d[]) {
    for (int v : g[u]) {
        if (v != from) {
            d[v] = d[u] + 1;
            init(v, u, d);
        }
    }
}
void sol() {
    cin >> n >> k;
    for (int i = 1; i <= n; i ++) g[i].clear();
    for (int i = 1; i < n; i ++) {
        int u, v; 
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    for (int i = 1; i <= n; i ++) init(i, 0, dis[i]);
    int ans = 1e9;
    for (int s = 0; s < (1 << n); s ++) {
        for (int i = 1; i <= n; i ++) {
            if (s >> (i - 1) & 1) {
                mark[i] = 1;
            } else mark[i] = 0;
        }
        for (int i = 1; i <= n; i ++) vis[i] = 0;
        int idx = 0;
        for (int i = 1; i <= n; i ++) if (!vis[i] && mark[i]) dfs(i), idx ++;
        if (idx <= 2 && __builtin_popcount(s) == k) {
            int ma = 0;
            for (int i = 1; i <= n; i ++) {
                int x = 1e9;
                for (int j = 1; j <= n; j ++) {
                    if (mark[j]) x = min(x, dis[i][j]);
                }
                ma = max(ma, x);
            }
            ans = min(ans, ma);
            // cout << ma << endl;
        }
    }
    cout << ans << endl;
}

int main() {
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int test_id, t;
    cin >> test_id >> t;
    while (t --) sol();
    cerr << "----TIMES: " << clock();
    return 0;
}
// 谨记：空间一定要算一遍大小；大样例过了一定要回测小样例；造corner case测边界；不要死磕！！
// 注意时间安排
// trust your self
