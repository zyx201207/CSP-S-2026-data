#include<bits/stdc++.h>
using namespace std;
int c, t, n, k, f[20][20], fa[20];
vector <int> g[20];
bool vis[20], vv[20];
int find(int x){
    if(x == fa[x]) return x;
    return fa[x] = find(x);
}
void merge(int x, int y){
    fa[find(x)] = find(y);
}
int main(){
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    cin >> c >> t;
    while(t--){
        cin >> n >> k;
        for(int i = 1; i < n; i++){
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
            f[u][v] = f[v][u] = 1;
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(i == j || f[i][j]) continue;
            f[i][j] = f[j][i] = 1e9;
        }
    }
    for(int i = 1; i <= (1 << n) - 1; i++){
        int cnt = 0;
        memset(vis, 0, sizeof(vis));
        for(int j = 0; j < n; j++){
            if((1 << j) & i){
                cnt++;
                vis[j + 1] = 1;
            }
        }
        if(cnt != k) continue;
        for(int i = 1; i <= n; i++){
                fa[i] = i;
        }
            for(int i = 1; i <= n; i++){
                if(!vis[i]) continue;
                for(int j = 0; j < g[i].size(); j++){
                        int v = g[i][j];
                    if(vis[v]){
                        if(find(i) != find(v)) merge(i, v);
                    }
                }
            }
            int lst1 = 0, lst2 = 0, cnt1 = 0, ok = 0;
            for(int i = 1; i <= n; i++){
                if(!vis[i]) continue;
                if(find(i) != lst1){
                    if(lst1 == 0){
                        lst1 = find(i);
                        cnt1++;
                        continue;
                    }
                    if(find(i) == lst2) continue;
                    if(lst2 == 0){
                        cnt1++;
                        lst2 = find(i);
                        continue;
                    }
                    ok = 1;
                }
            }
            if(ok || cnt1 > 2) continue;
            for(int i = 1; i <= n; i++){
                for(int j = 1; j <= n; j++){
                if(vis[i] && vis[j]) f[i][j] = 0;
                for(int k = 1; k <= n; k++){
                    f[i][j] = min(f[i][j], f[i][k] + f[j][k]);
                }
            }
            }
            int res = 0;
            for(int i = 1; i <= n; i++){
                for(int j = 1; j <= n; j++){
                    res = max(res, f[i][j]);
                }
            }
            cout << res << '\n';
    }
    return 0;
}
