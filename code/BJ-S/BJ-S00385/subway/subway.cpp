#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll N=5e5+5+500;
ll c,n,m,d,q,w[N],k[N],dis[N];
bool vis[N];
struct node{
    ll v,w;
    friend bool operator<(node x,node y){
        return x.w>y.w;
    }
};
vector<node>g[N];
void dij(ll s){
    priority_queue<node>pq;
    memset(vis,0,sizeof vis);
    memset(dis,0x3f,sizeof dis);
    pq.push({s,0});dis[s]=0;
    while(pq.size()){
        ll u=pq.top().v;pq.pop();
        if(vis[u])continue;
        vis[u]=1;
        for(auto e:g[u]){
            ll v=e.v,ww=e.w;
            if(!vis[v]&&dis[u]+ww<dis[v]){
                dis[v]=dis[u]+ww;
                pq.push({v,dis[v]});
            }
        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0),cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(ll i=n+1;i<=n+m;i++)cin>>w[i];
    for(ll i=1;i<=n;i++){
        cin>>k[i];
        for(ll j=1,a,t;j<=k[i];j++){
            cin>>a>>t;
            g[i].push_back({a+n,t});
            g[a+n].push_back({i,t});
        }
    }
    for(ll i=1,x,y;i<=q;i++){
        cin>>x>>y;
        x+=n,y+=n;
        dij(x);
        // for(ll j=n+1;j<=n+m;j++)cout<<dis[j]<<" ";
        // cout<<'\n';
        cout<<w[x]+dis[y]+w[y]<<'\n';
    }
    return 0;
}