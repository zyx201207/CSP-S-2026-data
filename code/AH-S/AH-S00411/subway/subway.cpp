#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL N=5e5+10;
struct Node{
    LL v,d;
    bool operator < (const Node &rhs)const{
        return d<rhs.d;
    }
};
LL c,n,m,d,q,w[N],vis[N],dis[N],a[N];
vector<Node>G[N];
void djs(LL u){
    memset(vis,0,sizeof(vis));
    memset(dis,0x3f,sizeof(dis));
    priority_queue<Node>pq;
    dis[u]=a[u];
    pq.push({u,dis[u]});
    while(!pq.empty()){
        LL v=pq.top().v;pq.pop();
        if(vis[v]) continue;
        vis[v]=1;
        for(LL i=0;i<G[v].size();i++){
            u=G[v][i].v;
            if(!vis[u]&&dis[v]+G[v][i].d<dis[u]){
                dis[u]=dis[v]+G[v][i].d+a[u];
                pq.push({u,dis[u]});
            }
        }
    }

}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>m>>n>>d>>q;
    for(LL i=1;i<=n;i++) scanf("%lld",&w[i]);
    for(LL i=1;i<=m;i++){
        LL k;
        scanf("%lld",&k);
        for(LL j=1;j<=k;j++){
            LL u,t;
            scanf("%lld %lld",&u,&t);
            if(i!=u){
                G[i].push_back({u,t});
                G[u].push_back({i,t});
            }
            else a[u]=t;
        }
    }

    while(q--){
        LL u,v;
        scanf("%lld %lld",&u,&v);
        djs(u);
        printf("%lld\n",dis[v]+w[u]+w[v]-a[v]);
    }
    return 0;
}
