#include<iostream>
#include<queue>
#include<cstring>
#include<vector>
#define int long long
#define P pair<long long,long long>
using namespace std;
struct edge{
    int next,w;
};
int c,n,m,d,q1;
vector<edge> g[505];
edge t[500005][25];
int w[500005],idx[500005];
int dis[505][505];
priority_queue<P,vector<P>,greater<P> > q;
void Dij(int st){
    while(!q.empty())q.pop();
    q.push({0,st});
    dis[st][st]=0;
    while(!q.empty()){
        P tmp=q.top();q.pop();
        if(tmp.first>dis[st][tmp.second])continue;
        int u=tmp.second;
        for(int i=0;i<g[u].size();i++){
            edge v=g[u][i];
            if(dis[st][u]+v.w<dis[st][v.next]){
                dis[st][v.next]=dis[st][u]+v.w;
                q.push({dis[st][v.next],v.next});
            }
        }
    }
}
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q1);
   // printf("%lld %lld %lld %lld %lld\n",c,n,m,d,q1);
    for(int i=1;i<=m;i++){
        scanf("%lld",&w[i]);
     //   printf("%lld ",w[i]);
    }
   // printf("\n");
    for(int i=1,k;i<=n;i++){
        scanf("%lld",&k);
     //   printf("%lld ",k);
        for(int j=1,v,w;j<=k;j++){
            scanf("%lld%lld",&v,&w);
        //    printf("%lld %lld ",v,w);
            t[v][++idx[v]].next=i;
            t[v][idx[v]].w=w;
        }
       // printf("\n");
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=idx[i];j++){
            for(int k=j+1;k<=idx[i];k++){
                int u=t[i][j].next,v=t[i][k].next,w=t[i][j].w+t[i][k].w;
                g[u].push_back({v,w});
                g[v].push_back({u,w});
            }
        }
    }
    memset(dis,0x3f,sizeof(dis));
    for(int i=1;i<=n;i++){
        Dij(i);
    }
    while(q1--){
        int x,y;
        scanf("%lld%lld",&x,&y);
    //    printf("%lld %lld\n",x,y);
        int mn=0x3f3f3f3f3f3f3f3f;
        for(int i=1;i<=idx[x];i++){
            for(int j=1;j<=idx[y];j++){
                int u=t[x][i].next,v=t[y][j].next,w=t[x][i].w+t[y][j].w;
                mn=min(mn,dis[u][v]+w);
            }
        }
        printf("%lld\n",mn+w[x]+w[y]);
    }
    return 0;
}
