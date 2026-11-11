//Change's Code
#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(false), cin.tie(0);
    int c, t;
    cin >> c >> t;
    while(t--){
        int n, d;
        cin >> n >> d;
        vector<int> sz(n+1);
        for(int i=1;i<=n;i++){
            cin >> sz[i];
        }
        auto solveA = [&]()->void {
            if(n < 4){
                puts("0");
                return ;
            }
            int c = d / (sz[2] - sz[1]);
            if(c < 2) {
                puts("0");
                return ;
            }
            printf("%lld\n", max(n - 2*c + 1, 0ll));
        };
        if(c == 11 || c == 12){
            solveA();
            continue;
        } else {
            vector<vector<int> >tu(n+1);
            for(int i=1;i<=n;i++){
                for(int j=i+1;j<=n;j++){
                    if(sz[j] - sz[i] <= d){
                        tu[i].push_back(j);
                    } else break;
                }
            }
            int ans = 0;
            auto dij = [&tu, &n](int st)-> int {
                vector<int> dis(n+1, 1e9), js(n+1, 0);
                struct pqnode{
                    int u, dis;
                    bool operator<(pqnode y) const {
                        return dis > y.dis;
                    }
                };
                priority_queue<pqnode> q;
                js[st] = 1;
                dis[st] = 0;
                q.push({st, 0});
                int ans = 0;
                while(q.size()){
                    auto u = q.top();
                    q.pop();
                    if(u.dis > dis[u.u]) continue;
                    if(js[u.u] == 2) ans ++;
                    for(auto v : tu[u.u]){
                        if(dis[v] > dis[u.u] + 1){
                            dis[v] = dis[u.u] + 1;
                            js[v] = js[u.u];
                            q.push({v, dis[v]});
                        } else if(dis[v] == dis[u.u] + 1){
                            js[v] += js[u.u];
                            if(js[v] > 2) js[v] = 3;
                        }
                    }
                }
                return ans;
            };
            for(int i=1;i<=n;i++){
                ans += dij(i);
            }
            printf("%lld\n", ans);
        }
    }
    return 0;
}
// 48pts