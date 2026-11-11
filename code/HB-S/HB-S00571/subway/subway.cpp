#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,int> pii;
#define il inline
#define mk make_pair
#define gc() getchar()
il ll read(){
    ll x=0,f=1;char ch=gc();
    while(!isdigit(ch)){
        if(ch=='-') f=-1;
        ch=gc();
    }
    while(isdigit(ch)){
        x=(x<<3)+(x<<1)+(ch^48);
        ch=gc();
    }
    return x*f;
}
const int M=5e5+5;
ll w[M];
const int N=505;
const ll inf=1e18;
ll k[N];
vector<pii> G[M+N];
ll dis[M+N];
bool vis[N];
int c,n,m,d,q;
il void dij(int s,int t){
    for(int i=1;i<=m+n;++i) dis[i]=inf,vis[i]=0;
    dis[s]=0;
    priority_queue<pii,vector<pii>,greater<pii> > pq;
    pq.emplace(dis[s],s);
    while(!pq.empty()){
        pii u=pq.top();
        pq.pop();
        int uid=u.second;
        if(vis[uid]) continue;
        vis[uid]=1;
        for(pii v:G[uid]){
            int vid=v.second,vd=v.first;
            if(vis[vid]) continue;
            if(dis[vid]<=dis[uid]+vd) continue;
            dis[vid]=dis[uid]+vd;
            pq.emplace(dis[vid],vid);
        }
        if(vis[t]) return ;
    }
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    c=read(),n=read(),m=read(),d=read(),q=read();
    for(int i=1;i<=m;++i) w[i]=read();
    for(int i=1;i<=n;++i){
        k[i]=read();
        int id=m+i;
        for(int j=1;j<=k[i];++j){
            int a=read(),t=read();
            G[id].push_back(mk(t,a));
            G[a].push_back(mk(t,id));
        }
    }
    for(int i=1;i<=q;++i){
        int x=read(),y=read();
        ll ans=w[x]+w[y];
        dij(x,y);
        ans+=dis[y];
        printf("%lld\n",ans);
    }
    return 0;
}
