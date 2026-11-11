#include<bits/stdc++.h>
const int N = 1e6+5;
using namespace std;
#define ll long long
namespace Pinball{
    int n, m;
    vector<int> G[N];
namespace sub12{
    int dep[N], mx[N];
    void dfs(int u, int f){
        if (!f) dep[u] = 0;
        else dep[u] = dep[f] + 1;
        for (int v : G[u]){
            if (v == f) continue;
            dfs(v, u);
        }
    }
    void solve(){
        int ans = n;
        for (int i = 0;i < (1 << n);i++){
            if (__builtin_popcount(i) != m) continue;
            int cnt = m;
            for (int u = 1;u <= n;u++){
                if (!((i >> (u -1)) & 1)) continue;
                for (int v : G[u]){
                    if (v < u) continue;
                    if (!((i >> (v - 1)) & 1)) continue;
                    --cnt;
                }
            }
            if (cnt > 2) continue;
            for (int j = 1;j <= n;j++) mx[j] = n;
            for (int j = 1;j <= n;j++){
                if ((i >> (j - 1)) & 1){
                    dfs(j, 0);
                    for (int k = 1;k <= n;k++) mx[k] = min(mx[k], dep[k]);
                }
            }
            int t = 0;
            for (int j = 1;j <= n;j++) t = max(t, mx[j]);
            ans = min(ans, t);
        }
        cout << ans << '\n';
    }
}
    int mx1[N], sz[N], mx2[N], h[N];
    int f[1005][1005], ans;
    int dep[N];
    void dfs(int u, int f){
        mx1[u] = mx2[u] = 0;
        for (int v : G[u]){
            if (v == f) continue;
            dep[v] = dep[u] + 1;
            dfs(v, u);
            mx1[u] = max(mx1[u], mx1[v] + 1);
        }
    }
    int id[N], mx3[N];
    void dfs2(int u, int f){
        int mx = -1, se = -1;
        for (int v : G[u]){
            if (v == f) continue;
            mx2[v] = 1;
            if (mx1[v] + 1 > mx){
                se = mx;
                mx = mx1[v] + 1;
            }
            else se = max(se, mx1[v] + 1);
        }
        for (int v : G[u]){
            if (v == f) continue;
            if (mx1[v] + 1 == mx){
                mx2[v] = max(mx2[v], se + 1);
            }
            else{
                mx2[v] = max(mx2[v], mx + 1);
            }
            dfs2(v, u);
        }
    }
    void dfs3(int u, int fa){
        f[u][1] = 0;
        for (int i = 2;i <= m;i++) f[u][i] = 1e9;
        sz[u] = 1;
        for (int v : G[u]){
            if (v == fa) continue;
            dfs3(v, u);
            for (int i = 1;i <= m;i++) h[i] = max(f[u][i], mx1[v] + 1);
            for (int i = 1;i <= min(sz[u], m);i++){
                for (int j = 1;j <= min(sz[v], m);j++){
                    if (i + j > m) break;
                    h[i + j] = min(h[i + j], max(f[u][i], f[v][j]));
                }
            }
            sz[u] += sz[v];
            for (int i = 1;i <= m;i++) f[u][i] = h[i];
        }
    }
    void dfs4(int u, int fa, int I){
        id[u] = I;
        mx3[u] = -1e9;
        if (u != I){
            mx3[u] = max(mx3[fa], mx2[u] - dep[u]);
        }
        for (int v : G[u]){
            if (v == fa) continue;
            dfs4(v, u, I);
        }
    }
    int mx4[1005][1005], su[1005];
    void Purgatory(){
        cin >> n >> m;
        for (int i = 1;i <= n;i++){
            G[i].clear();
        }
        ans = n;
        for (int i = 2;i <= n;i++){
            int u, v;
            cin >> u >> v;
            G[u].emplace_back(v);
            G[v].emplace_back(u);
        }
        if (n == 2){
            cout << "0\n";
            return;
        }
        if (n <= 10){
            sub12::solve();
            return;
        }
        for (int rt = 1;rt <= n;rt++){
            if (G[rt].size() == 1) continue;
            dep[rt] = 0;
            dfs(rt, 0);
            dfs2(rt, 0);
            dfs3(rt, 0);
            for (int u : G[rt]) dfs4(u, rt, u);
            for (int i = G[rt].size() - 1;i >= 0;i--){
                su[i] = mx1[G[rt][i]] + 1;
                if (i + 1 < G[rt].size()) su[i] = max(su[i], su[i + 1]);
            }
            for (int i = 0, m1 = -1e9;i < G[rt].size();i++){
                for (int j = i + 1, m2 = -1e9;j < G[rt].size();j++){
                    int m3 = -1e9;
                    if (j + 1 < G[rt].size()) m3 = su[j + 1];
                    mx4[G[rt][i]][G[rt][j]] = max({m1, m2, m3});
                    mx4[G[rt][j]][G[rt][i]] = mx4[G[rt][i]][G[rt][j]];
                    m2 = max(m2, mx1[G[rt][j]] + 1);
                }
                m1 = max(m1, mx1[G[rt][i]] + 1);
            }
            ans = min(ans, f[rt][m]);
            for (int u = 1;u <= n;u++){
                for (int v = 1;v <= n;v++){
                    if (u == rt || v == rt) continue;
                    if (id[u] == id[v]) continue;
                    int t = 1e9;
                    for (int i = 1;i < m;i++){
                        t = min(t, max(f[u][i], f[v][m - i]));
                    }
                    t = max(t, mx4[id[u]][id[v]] + min(dep[u], dep[v]));
                    t = max(t, mx3[u] + dep[u]);
                    t = max(t, mx3[v] + dep[v]);
                    t = max(t, dep[u]);
                    t = max(t, dep[v]);
                    ans = min(ans, t);
                }
            }
        }
        cout << ans << '\n';
    }
}
signed main(){
    cin.tie(0)->sync_with_stdio(false);
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	int T = 1, c;
    cin >> c >> T;
	while (T--) Pinball::Purgatory();
	return 0;
}