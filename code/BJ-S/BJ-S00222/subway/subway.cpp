#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,c,d,q,w[500001],id[500001],vis[2001],dis[2001][2001];
struct node{
    int v,w;
};
vector<node>g[1000001];
void dijkstra(int s){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>que;
    memset(dis[s],0x3f,sizeof(dis[s]));
    memset(vis,0,sizeof(vis));
    dis[s][s]=0;
    que.push({0,s});
    while(!que.empty()){
        int u=que.top().second;que.pop();
        if(vis[u])continue;
        vis[u]=1;
        for(node i:g[u]){
            int v=i.v,w=i.w;
            if(dis[s][v]>dis[s][u]+w){
                dis[s][v]=dis[s][u]+w;
                que.push({dis[s][v],v});
            }
        }
    }
}
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
    for(int i=1;i<=m;i++)scanf("%lld",&w[i]);
    int cnt=m;
    for(int i=1;i<=n;i++){
        int k;scanf("%lld",&k);
        for(int j=1;j<=k;j++)id[j]=++cnt;
        for(int j=1;j<=k;j++){
            int a,w;
            scanf("%lld%lld",&a,&w);
            g[id[j]].push_back({a,w});
            g[a].push_back({id[j],w});
            if(j<k){
                g[id[j]].push_back({id[j+1],0});
                g[id[j+1]].push_back({id[j],0});
            }
        }
    }
    for(int i=1;i<=cnt;i++)dijkstra(i);
    for(int i=1;i<=q;i++){
        int x,y;scanf("%lld%lld",&x,&y);
        printf("%lld\n",w[x]+w[y]+dis[x][y]);
    }
    return 0;
}