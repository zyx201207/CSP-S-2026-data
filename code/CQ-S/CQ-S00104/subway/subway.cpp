//Change's Code
#include <bits/stdc++.h>
#define int long long
using namespace std;
int mi[510][510] = {}; //线路之间
signed main(){
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(false), cin.tie(0);
    int c, n, m, d, q;
    cin >> c >> n >> m >> d >> q;
    vector<int> w(m+1); //口->厅
    struct road{
        int v, w;
    };
    vector<vector<road> >
        tu(n+1), //线路之间
        tu2(m+1) //站线之间
    ; 
    for(int i=1;i<=m;i++){
        cin >> w[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++) mi[i][j] = 1e18;
        int k;
        cin >> k;
        for(int j=1;j<=k;j++){
            int x, t;
            cin >> x >> t;
            tu2[x].push_back({i, t});
        }
    }
    for(int i=1;i<=m;i++){
        for(auto a : tu2[i]){
            for(auto b : tu2[i]){
                if(a.v != b.v){
                    mi[a.v][b.v] = min(mi[a.v][b.v], a.w + b.w);
                    mi[b.v][a.v] = min(mi[b.v][a.v], a.w + b.w);
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(mi[i][j] != 1e18 && i != j){
                tu[i].push_back({j, mi[i][j]});
            }
        }
    }
    vector<vector<int> > dis(n+1, vector<int> (n+1, 1e18));
    auto dij = [&tu](int st, vector<int> &dis)-> void {
        struct pqnode{
            int u, dis;
            bool operator<(pqnode y) const {
                return dis > y.dis;
            }
        };
        priority_queue<pqnode> q;
        dis[st] = 0;
        q.push({st, 0});
        while(q.size()){
            auto u = q.top();
            q.pop();
            if(u.dis > dis[u.u]) continue;
            for(auto v : tu[u.u]){
                if(dis[v.v] > dis[u.u] + v.w){
                    dis[v.v] = dis[u.u] + v.w;
                    q.push({v.v, dis[v.v]});
                }
            }
        }
    };
    for(int i=1;i<=n;i++){
        dij(i, dis[i]);
    }
    while(q--){
        int x, y;
        cin >> x >> y;
        int ans = 1e18;
        for(auto a : tu2[x]){
            for(auto b : tu2[y]){
                if(dis[a.v][b.v] != 1e18){
                    ans = min(ans, dis[a.v][b.v] + a.w + b.w);
                }
            }
        }
        printf("%lld\n", ans + w[x] + w[y]);
    }
    return 0;
}
//AC