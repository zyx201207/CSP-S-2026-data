#include<bits/stdc++.h>
// #define int ll
#define all(op) op.begin(),op.end()
#define all1(op) op.begin()+1,op.end()
using namespace std;
using ll=long long;
using db=double;
using ldb=long double;
using i128=__int128_t;
const int inf=1e9+7;
const ll INF=1e18+7,M=1e12+7;
const db eps=1e-9;
void solve(){
    int n,m,d,q;cin>>n>>m>>d>>q;
    vector<ll> a(m+1);
    for(int i=1;i<=m;i++)cin>>a[i];
    vector<vector<pair<int,ll>>> cd(m+1);
    for(int i=1;i<=n;i++){
        int c;cin>>c;
        for(int j=1;j<=c;j++){
            ll u,w;cin>>u>>w;
            cd[u].push_back({i,w});
        }
    }
    vector<vector<ll>> dis(n+1,vector<ll>(n+1,INF));
    for(int i=1;i<=n;i++)dis[i][i]=0;
    for(int i=1;i<=m;i++){
        for(int j=0;j<cd[i].size();j++){
            int u=cd[i][j].first;
            for(int k=j+1;k<cd[i].size();k++){
                int v=cd[i][k].first;
                dis[u][v]=min(dis[u][v],cd[i][j].second+cd[i][k].second);
                dis[v][u]=min(dis[u][v],cd[i][j].second+cd[i][k].second);
            }
        }
    }
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                dis[j][k]=min(dis[j][k],dis[j][i]+dis[i][k]);
            }
        }
    }

    for(int i=1;i<=q;i++){
        int u,v;cin>>u>>v;
        ll res=INF;
        for(auto x:cd[u]){
            for(auto y:cd[v]){
                res=min(res,x.second+y.second+dis[x.first][y.first]);
            }
        }
        cout<<res+a[u]+a[v]<<"\n";
    }
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    // freopen("subway7.in","r",stdin);
    // freopen("code.out","w",stdout);
    int C,T=1;
    cin>>C;
    // cin>>T;
    while(T--)solve();
    return 0;
}
/*
15:56
*/