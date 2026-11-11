#include<bits/stdc++.h>
using namespace std;
const int N = 12;
int c, t, n, k, ans, b[N], dis[N], vis[N];
vector<int> g[N];
void dfs2(int u, int fa){
    vis[u] = 1;
    for(int v : g[u]){
        if(v == fa) continue;
        if(b[v] == 0) continue;
        dfs2(v, u);
    }
}
void dfs3(int u, int fa){
    for(int v : g[u]){
        if(v == fa) continue;
        dis[v] = min(dis[v], dis[u] + 1);
        dfs3(v, u);
    }
}
void dfs(int i, int s){
    if(n - i + 1 + s < k) return;
    if(s == k){
        int cnt = 0;
        memset(vis, 0, sizeof vis);
        for(int i = 1; i <= n; i++){
            if(b[i] && !vis[i]){
                cnt++;
                dfs2(i, 0);
            }
        }
        if(cnt > 2) return;
        memset(dis, 0x3f, sizeof dis);
        for(int i = 1; i <= n; i++){
            if(b[i]){
                dis[i] = 0;
                dfs3(i, 0);
            }
        }
        int res = 0;
        for(int i = 1; i <= n; i++){
            res = max(res, dis[i]);
        }
        ans = min(ans, res);
        return;
    }
    b[i] = 1;
    dfs(i + 1, s + 1);
    b[i] = 0;
    dfs(i + 1, s);
}
int main(){
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> c >> t;
    while(t--){
        ans = 0x3f3f3f3f;
        cin >> n >> k;
        for(int i = 1, u, v; i < n; i++){
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        dfs(1, 0);
        cout << ans << "\n";
        for(int i = 1; i <= n; i++){
            g[i].clear();
        }
    }
    return 0;
}
