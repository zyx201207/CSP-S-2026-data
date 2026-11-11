#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define ffor(i,a,b) for(ll i=(a);i<=(b);++i)
#define roff(i,a,b) for(ll i=(a);i>=(b);--i)
const ll N=510,M=500010,INF=1e18;
struct node{ll v,w,nxt;}e[100*N];
struct edge{
    ll v,dd;
    bool operator<(const edge&b)const{
        return dd>b.dd;
    }
};
ll C,n,m,d,q;
ll a[M],w[N],k[N],t[M];
ll ne,hd[N],dis[N],vst[N];
void add(ll u,ll v,ll ww){
    e[++ne]={v,ww,hd[u]};
    hd[u]=ne;
}
void dijkstra(ll s){
    ffor(i,1,n) dis[i]=INF,vst[i]=0;
    dis[s]=0;
    priority_queue<edge> qq;
    qq.push({s,0});
    while(!qq.empty()){
        edge tt=qq.top();qq.pop();
        if(vst[tt.v]) continue;
        vst[tt.v]=1;
        for(ll i=hd[tt.v];i;i=e[i].nxt){
            ll v=e[i].v,ww=e[i].w;
            if(dis[tt.v]+ww<dis[v]){
                dis[v]=dis[tt.v]+ww;
                qq.push({v,dis[v]});
            }
        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(0);
    cin>>C>>n>>m>>d>>q;
    ffor(i,1,n) cin>>w[i];
    ffor(ii,1,m){
        cin>>k[ii];
        ffor(i,1,k[ii]){
            cin>>a[i]>>t[i];
        }
        ffor(i,1,k[ii]) ffor(j,1,k[ii]){
            if(i==j) continue;
            add(a[i],a[j],t[i]+t[j]);
        }
    }
    ll x,y;
    ffor(i,1,q){
        cin>>x>>y;
        dijkstra(x);
        cout<<w[x]+w[y]+dis[y]<<"\n";
    }
    return 0;
}