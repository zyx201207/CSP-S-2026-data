#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int K=5e5+5,Q=1e5+5;
int c,n,m,d,q,a[K],t[K],w[K];
ll ans[Q],dis[K];
bool vis[K];
vector<pair<int,int>> e[K];
vector<pair<int,int>> ask[K];
void dijkstra(int start){
    memset(dis,0x3f,sizeof dis);
    memset(vis,0,sizeof vis);
    dis[start]=0;
    for(int i=1;i<=m;i++){
        int u=-1;
        for(int j=1;j<=m;j++){
            if(!vis[j]&&(u==-1||dis[u]>dis[j])) u=j;
        }
        vis[u]=1;
        for(auto it:e[u]){
            int v=it.first,w=it.second;
            dis[v]=min(dis[v],dis[u]+w);
        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
    for(int i=1;i<=m;i++) scanf("%d",&w[i]);
    for(int i=1;i<=n;i++){
        int k; scanf("%d",&k);
        for(int j=1;j<=k;j++) scanf("%d%d",&a[j],&t[j]);
        for(int x=1;x<=k;x++){
            for(int y=x+1;y<=k;y++){
                e[a[x]].push_back({a[y],t[x]+t[y]});
                e[a[y]].push_back({a[x],t[x]+t[y]});
            }
        }
    }
    for(int i=1;i<=q;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        if(x>y) swap(x,y);
        ask[x].push_back({y,i});
    }
    for(int i=1;i<=m;i++){
        if(ask[i].size()==0) continue;
        dijkstra(i);
        for(auto it:ask[i]){
            int j=it.first,id=it.second;
            ans[id]=w[i]+w[j]+dis[j];
        }
    }
    for(int i=1;i<=q;i++) printf("%lld\n",ans[i]);
    return 0;
}