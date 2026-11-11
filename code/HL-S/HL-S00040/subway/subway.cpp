#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using ull=unsigned long long;
using ld=long double;
struct Edge{
    ll ed,dis;
};
int c,n,m,d,q,k,a,t;
vector<vector<Edge>>edge;
vector<vector<ll>>dis;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    vector<ll>w(m+1);
    edge.resize(m+1);
    dis.resize(n+1,vector<ll>(n+1,1e+18));
    for(int i=1;i<=n;i++){
        dis[i][i]=0;
    }
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k;
        while(k--){
            cin>>a>>t;
            edge[a].push_back({i,t});
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=0;j<edge[i].size();j++){
            for(int k=j+1;k<edge[i].size();k++){
                dis[edge[i][j].ed][edge[i][k].ed]=min(dis[edge[i][j].ed][edge[i][k].ed],edge[i][j].dis+edge[i][k].dis);
                dis[edge[i][k].ed][edge[i][j].ed]=dis[edge[i][j].ed][edge[i][k].ed];
            }
        }
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
    while(q--){
        int u,v;
        ll ans=1e+18;
        cin>>u>>v;
        for(auto i:edge[u]){
            for(auto j:edge[v]){
                ans=min(ans,i.dis+j.dis+dis[i.ed][j.ed]);
            }
        }
        cout<<ans+w[u]+w[v]<<'\n';
    }
    return 0;
}
