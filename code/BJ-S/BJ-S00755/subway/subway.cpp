#include<bits/stdc++.h>
using namespace std;
#define int long long
int dis[1010][1010],c,n,m,d,q;
int ww[1010],k[510],a[510][1010],t[510][1010];
vector<int>mp[510];
struct node{
    int u,v,w;
};
vector<node>e;
inline void floyd(){
    memset(dis,0x3f,sizeof(dis));
    for(int i=1;i<=n;i++)dis[i][i]=0;
    for(auto [u,v,w]:e){
        dis[u][v]=min(dis[u][v],w);
        dis[v][u]=min(dis[v][u],w);
    }
    for(int s=1;s<=m;s++){
        for(int v=1;v<=m;v++){
            for(int u=1;u<=m;u++){
                dis[v][u]=min(dis[v][u],dis[v][s]+dis[s][u]);
                dis[u][v]=min(dis[u][v],dis[u][s]+dis[s][v]);
            }
        }
    }
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>ww[i];
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            cin>>a[i][j]>>t[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=k[i];j++){
            for(int ii=1;ii<=k[i];ii++){
                e.push_back({a[i][j],a[i][ii],t[i][j]+t[i][ii]});
            }
        }
    }
    floyd();
    while(q--){
        int x,y;
        cin>>x>>y;
        cout<<dis[x][y]+ww[x]+ww[y]<<"\n";
    }
    return 0;
}
