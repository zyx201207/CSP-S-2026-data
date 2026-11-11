#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N =5e5+10,M = 505;
struct Edge{
    ll to,w;
};
ll w[N];
vector<Edge> e[N];
int main(){
    cin.tie(nullptr),ios::sync_with_stdio(false);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q; cin >> c >> n >> m >> d >> q;
    for(int i = 1 ;i<=m;i++) cin >> w[i];
    for(int i = 1; i <= n;i++){
        int k; cin >> k;
        for(int j = 1 ;j<=k;j++){
            int a,t; cin >> a >>t;
            e[a].push_back({i,t});
        }
    }
    ll dis[505][505];
    memset(dis,0x3f,sizeof(dis));
    for(int i = 1;i<=m;i++){
        if(e[i].size() >= 2){
                for(auto [u,w1] : e[i]){
                    for(auto [v,w2] : e[i]){
                        if(u == v) continue;
                        dis[u][v] = dis[v][u] = w1+w2;
                    }
                }
        }
    }
    for(int k = 1 ;k <= n ;k++){
        for(int i = 1 ; i<=n;i++){
            for(int j = 1;j<=n;j++){
                dis[i][j] = min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
    for(int i = 1; i<=n;i++){
            dis[i][i] = 0;
        //for(int j = 1 ; j <= n;j++){
            //cout <<dis[i][j] << ' ';
       // }
        //cout << '\n';
    }

    while(q--){
        int x,y; cin >> x >>y;
        ll ans = 1e18;
        for(auto [u,w1] : e[x]){
            for(auto [v,w2] :e[y]){
                //cout <<  u << ' ' << w1 <<' ' << v << " " << w2 <<'\n';
                ans = min(ans,dis[u][v] + w1 + w2 );
                //cout << ans << '\n';
            }
        }
        cout << ans + w[x] +w[y] << "\n";
    }
    return 0;
}
