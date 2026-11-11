#include<bits/stdc++.h>
using namespace std;
#define int long long
int w[500010];
struct node{
    int v,w;
};
vector<node> g[500010];
int dis[510][510];
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=1;j<=k;j++){
            int x,v;
            cin>>x>>v;
            g[x].push_back({i,v});
        }
    }
    for(int i=0;i<=505;i++){
        for(int j=0;j<=505;j++){
            dis[i][j]=LONG_LONG_MAX;
        }
    }
    for(int i=1;i<=m;i++){
        for(auto nd1:g[i]){
            int u=nd1.v,w1=nd1.w;
            for(auto nd2:g[i]){
                int v=nd2.v,w2=nd2.w;
                if(u==v) dis[u][v]=0;
                else dis[u][v]=dis[v][u]=min(dis[u][v],w1+w2);//
            }
        }
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(dis[i][k]<LONG_LONG_MAX&&dis[k][j]<LONG_LONG_MAX) dis[i][j]=dis[j][i]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
    while(q--){
        int u,v;
        cin>>u>>v;
        int mi=dis[g[u][0].v][g[v][0].v]+g[u][0].w+g[v][0].w;
        for(auto nd1:g[u]){
            for(auto nd2:g[v]){
                mi=min(mi,dis[nd1.v][nd2.v]+nd1.w+nd2.w);
            }
        }
        cout<<w[u]+w[v]+mi<<"\n";
    }
    //cout<<n<<" "<<m<<" "<<d<<" "<<q;
    return 0;
}
//di yi ci jian dao yao du ru ce shi dian bian hao de