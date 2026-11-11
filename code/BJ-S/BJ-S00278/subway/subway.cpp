#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn=510;
const int maxm=5e5+10;
int T,n,m,d,q;
int p[maxm];
int c[maxn];
vector<int> e[maxn];
struct NODE{
    int to;
    ll cost;
};
vector<NODE> g[maxm];
ll dis[maxn][maxn];
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>T>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>p[i];
    for(int i=1;i<=n;i++){
        cin>>c[i];
        for(int j=1;j<=c[i];j++){
            int v,w;
            cin>>v>>w;
            e[i].push_back(v);
            g[v].push_back({i,w});
        }
    }
    memset(dis,0x3f,sizeof(dis));
    for(int i=1;i<=m;i++){
        int len=g[i].size();
        for(int j=0;j<len;j++){
            for(int k=j+1;k<len;k++){
                int u=g[i][j].to,v=g[i][k].to;
                ll w=g[i][j].cost+g[i][k].cost;
                dis[u][v]=min(dis[u][v],w);
                dis[v][u]=min(dis[v][u],w);
            }
        }
    }
    for(int i=1;i<=n;i++) dis[i][i]=0;
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
    while(q--){
        int x,y;
        cin>>x>>y;
        ll ans=1e18;
        for(int i=0;i<g[x].size();i++){
            for(int j=0;j<g[y].size();j++){
                int u=g[x][i].to,v=g[y][j].to,w=g[x][i].cost+g[y][j].cost;
                ans=min(ans,dis[u][v]+p[x]+p[y]+w);
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
