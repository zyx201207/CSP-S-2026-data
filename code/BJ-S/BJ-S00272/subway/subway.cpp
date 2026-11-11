#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define pli pair<ll,int>
const int N=5e5+510,M=2e3+10;
const ll INF=1e18;
int c,n,m,d,q;
ll W[N];
struct edge{
    int v,ne;
    ll w;
}e[N<<1];
int h[N],idx;
void add(int u,int v,ll w){
    e[++idx].v=v;
    e[idx].w=w;
    e[idx].ne=h[u];
    h[u]=idx;
}
bool vis[N];
ll dis[M][M];
void dijkstra(int s){
    priority_queue<pli,vector<pli>,greater<pli> >q;
    for(int i=1;i<=m+n;i++){
        dis[s][i]=INF;
        vis[i]=false;
    }
    vis[s]=true;
    dis[s][s]=0;
    q.push({0,s});
    while(q.size()){
        pli t=q.top();
        q.pop();
        ll d=t.first;
        int u=t.second;
        if(d>dis[s][u])continue;
        for(int i=h[u];i;i=e[i].ne){
            int v=e[i].v;
            ll w=e[i].w;
            if(dis[s][v]>dis[s][u]+w){
                dis[s][v]=dis[s][u]+w;
                if(!vis[v]){
                    vis[v]=true;
                    q.push({dis[s][v],v});
                }
            }
        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
    for(int i=1;i<=m;i++){
        scanf("%lld",&W[i]);
    }
    for(int i=1;i<=n;i++){
        int k;
        scanf("%d",&k);
        for(int j=1;j<=k;j++){
            int u;
            ll w;
            scanf("%d%lld",&u,&w);
            add(u,i+m,w);
            add(i+m,u,w);
        }
    }
    for(int i=1;i<=m;i++)dijkstra(i);
    while(q--){
        int u,v;
        scanf("%d%d",&u,&v);
        ll ans=W[u]+W[v];
        printf("%lld\n",ans+dis[u][v]);
    }
    return 0;
}
