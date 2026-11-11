#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(x,a,b,c) for(int x=a;b;x+=c)
#define rep2(x,a,b,c) for(int x=a;b;x-=c)
#define fop(x) freopen(x".in","r",stdin); freopen(x".out","w",stdout);
const ll INF=INT_MAX,N=5e5+20;
vector<pair<int,ll> > e[N];
ll c,n,m,d,q;
ll w[N],k[N];
vector<ll> dis[N];
vector<ll> dij(int x){
    vector<ll> dis(m+n+20,INF);
    priority_queue<pair<ll,int> ,vector<pair<ll,int> > ,greater<pair<ll,int> > > pq;
    dis[x]=0;
    pq.push({0,x});
    while(!pq.empty()){
        int u=pq.top().second;
        ll w=pq.top().first;
        pq.pop();
        if(dis[u]!=w) continue; 
        for(pair<int,ll> now:e[u]){
            int v=now.first;
            if(dis[v]>dis[u]+now.second){
                dis[v]=dis[u]+now.second;
                pq.push({dis[v],v});
            }
        }
    }
    return dis;
}
int main(){
    fop("subway");
    scanf("%lld %lld %lld %lld %lld",&c,&n,&m,&d,&q);
    rep(i,1,i<=m,1) scanf("%lld",&w[i]);
    rep(i,1,i<=n,1){
        scanf("%lld",&k[i]);
        rep(j,1,j<=k[i],1){
        	int u=0;
            ll W=0;
            scanf("%d %lld",&u,&W);
            e[u].push_back({i+m,W});
            e[i+m].push_back({u,W});
        }
    }
    while(q--){
        int x=0,y=0;
        scanf("%d%d",&x,&y);
        if(dis[x].empty()) dis[x]=dij(x);
        printf("%lld\n",dis[x][y]+w[x]+w[y]);
    }
    return 0;
}