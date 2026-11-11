#include<bits/stdc++.h>
using namespace std;
const int N = 1e3+5;
int c, t, n, k;
vector<int> g[N];
int mxdep[N], rs, S, vis[N], f[N];
void dfs(int u, int fa){
    vis[u] = 1;
    for(auto v:g[u]) if(!vis[v] && (S&(1<<v-1))){
        dfs(v, u);
    }
}
int main(){
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    cin >> c >> t;
    while(t--){
        cin >> n >> k;
        for(int i = 1; i <= n; i++) g[i].clear();
        for(int i = 1; i < n; i++){
            int u, v; cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        if(n <= 20){
            int ans = 1e9;
            for(int i = 0; i < (1<<n); i++) if(__builtin_popcount(i) == k){
                S = i;
                for(int j = 1; j <= n; j++) vis[j] = 0;
                int cnt = 0;
                for(int j = 1; j <= n; j++) if((i&(1<<j-1)) && !vis[j]){
                    dfs(j, 0);
                    cnt++;
                }
                if(cnt == 2){
                    int q[25], l, r;
                    l = 1, r = 0;
                    for(int j = 1; j <= n; j++) vis[j] = 0;
                    for(int j = 1; j <= n; j++) if(i&(1<<j-1)){
                        q[++r] = j; vis[j] = 1;
                        f[j] = 0;
                    }
                    // cerr << i << '\n';
                    int now = 0;
                    while(l <= r){
                        int u = q[l++];
                        now = max(now, f[u]);
                        for(auto v:g[u]) if(!vis[v]){
                            q[++r] = v;
                            vis[v] = 1;
                            f[v] = f[u]+1;
                        }
                    }
                    ans = min(ans, now);
                }
            } cout << ans << '\n';
            continue;
        }
        rs = 1e9;
        if(k == 2){
            for(int i = 1; i <= n; i++){
                // dfs(i, 0, 0);

            }
        }
    }
    return 0;
}