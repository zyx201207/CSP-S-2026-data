#include<bits/stdc++.h>
using namespace std;

#define my long long
const my N = 5e5 + 5;

my c, t, n, d, x[N], cnt = 0;
bool vis[N], mn;

vector<my> G[N];

void dfs(my u, my ed, my jl){
    if(jl > mn) return;
    if(u == ed){
        if(jl < mn){
            mn = jl;
            cnt = 1;
        } else if(jl == mn) cnt++;
    }
    for(auto v : G[u]){
        if(vis[v] == true) continue;
        vis[v] = true;
        dfs(v, ed, jl + 1);
        vis[v] = false;
    }
}

signed main(){
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    cin >> c >> t;
    while(t--){
        cin >> n >> d;
        for(my i = 1; i <= n; i++) cin >> x[i];
        for(my i = 1; i <= n; i++){
            for(my j = i + 1; j <= n; j++){
                if(abs(x[i] - x[j]) <= d){
                    G[i].push_back(j);
                    G[j].push_back(i);
                }
            }
        }
        my ans = 0;
        for(my i = 1; i <= n; i++){
            for(my j = i + 1; j <= n; j++){
                mn = LONG_LONG_MAX, cnt = 0;
                memset(vis, false, sizeof(vis));
                vis[i] = true;
                dfs(i, j, 0);
                if(cnt == 2){
                    ans++;
                    cout << i << ' ' << j << '\n';
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/
