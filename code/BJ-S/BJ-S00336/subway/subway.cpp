#include<bits/stdc++.h>
using namespace std;
using ll=long long;
constexpr ll N=505,M=5e5+5,inf=4e18;
ll c,n,m,d,q,w[M],dis[N][N];
struct to{
    ll id,t;
};
vector<to> G[M];

int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        ll k;
        cin>>k;
        for(int j=1;j<=k;j++){
            ll a,t;
            cin>>a>>t;
            G[a].push_back({i,t});
        }
    }
    //得到线路之间的距离
    memset(dis,0x3f,sizeof(dis));
    for(int i=1;i<=n;i++){
        dis[i][i]=0;
    }
    for(int i=1;i<=m;i++){
        ll siz=G[i].size(),u,v,c;
        for(int x=0;x<siz;x++){
            for(int y=x+1;y<siz;y++){
                u=G[i][x].id,v=G[i][y].id;
                c=G[i][x].t+G[i][y].t;
                dis[u][v]=min(dis[u][v],c);
                dis[v][u]=min(dis[v][u],c);
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
        ll x,y;
        cin>>x>>y;
        ll ans=inf;
        for(auto &i:G[x]){
            for(auto &j:G[y]){
                ans=min(ans,i.t+j.t+w[x]+w[y]+dis[i.id][j.id]);
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}