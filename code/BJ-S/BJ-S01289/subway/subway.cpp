#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

const int N=5e5+10,M=510;
vector<pii>e[N];
ll dis[M][M],w[N];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    freopen("subway.in","r",stdin);freopen("subway.out","w",stdout);
    int c,n,m,d,q;cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1;i<=n;i++){
        int k;cin>>k;
        while(k--){
            int a,t;cin>>a>>t;
            e[a].push_back({t,i});
        }
    }
    memset(dis,0x3f,sizeof(dis));
    for(int i=1;i<=n;i++)dis[i][i]=0;
    for(int i=1;i<=m;i++)
        for(int j=1;j<e[i].size();j++)
            for(int k=0;k<j;k++){
                int u=e[i][j].second,v=e[i][k].second;
                if(u!=v)dis[u][v]=dis[v][u]=min(dis[u][v],0ll+e[i][j].first+e[i][k].first);
            }
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
    while(q--){
        int u,v;cin>>u>>v;
        ll ans=dis[0][0];
        for(int i=0;i<e[u].size();i++)
            for(int j=0;j<e[v].size();j++)
                ans=min(ans,dis[e[u][i].second][e[v][j].second]+e[u][i].first+e[v][j].first);
        cout<<ans+w[u]+w[v]<<'\n';
    }
    return 0;
}
//14.59