#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c,n,m,d,q,w[500010],k[510],a[500010],t[500010],x,y;
ll G[510][510],dis[510],vis[510],pre[510];
void djs(ll x){
    dis[x]=0;
    priority_queue<ll> pq;
    pq.push(0);
    ll id=1;
    for(ll i=1;i<=n;i++){
        ll u=id;
        for(ll j=0;j<pq.size();j++) pq.pop();
        vis[u]=1;
        for(ll j=1;j<=m;j++){
            if(j==u) continue;
            if(dis[u]+G[u][j]<dis[j]&&!vis[j]) dis[j]=dis[u]+G[u][j];
            pq.push(dis[j]);
            if(dis[j]==pq.top()) id=j;
        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    memset(G,0x3f,sizeof(G));
    cin>>c>>n>>m>>d>>q;
    for(ll i=1;i<=m;i++) scanf("%lld",&w[i]);
    for(ll i=1;i<=n;i++){
        scanf("%lld",&k[i]);
        for(ll j=1;j<=k[i];j++){
            scanf("%lld %lld",&a[j],&t[j]);
            if(j!=1&&j!=k[i]){
                G[a[j-1]][a[j]]=min(G[a[j-1]][a[j]],ll(t[j-1]+t[j]));
                G[a[j]][a[j-1]]=G[a[j-1]][a[j]];
            }else if(j==1) G[0][a[j]]=t[j];
            else G[a[j]][0]=t[j];
        }
    }djs(1);
    while(q--){
        scanf("%lld %lld",&x,&y);
        printf("%lld",dis[y]-dis[x]+w[x]+w[y]);
    }return 0;
}
