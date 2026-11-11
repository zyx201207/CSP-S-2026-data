#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[500010];
vector <pair<int,int>> vc[500010];
int dis[510][510];
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int c,n,m,d,q; cin>>c>>n>>m>>d>>q;
    for (int i=1; i<=m; i++){
        cin>>a[i];
    }
    for (int i=1; i<=n; i++){
        int t; cin>>t;
        for (int j=1; j<=t; j++){
            int x,y; cin>>x>>y;
            vc[x].push_back({i,y});
        }
    }
    memset(dis,0x3f,sizeof(dis));
    for (int i=1; i<=n; i++) dis[i][i]=0;
    for (int i=1; i<=m; i++){
        for (auto x:vc[i]){
            for (auto y:vc[i]){
                dis[x.first][y.first]=min(dis[x.first][y.first],x.second+y.second);
            }
        }
    }
    for (int k=1; k<=n; k++){
        for (int i=1; i<=n; i++){
            for (int j=1; j<=n; j++){
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
    for (int i=1; i<=q; i++){
        int u,v; cin>>u>>v;
        int mn=1e18;
        for (auto x:vc[u]){
            for (auto y:vc[v]){
                mn=min(mn,a[u]+a[v]+x.second+y.second+dis[x.first][y.first]);
            }
        }
        cout<<mn<<"\n";
    }
}
