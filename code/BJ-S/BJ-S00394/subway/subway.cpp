#include <bits/stdc++.h>
using namespace std;
using std::vector;
typedef long long ll;
#define FASTIO ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
const ll MAXM=510,MAXN=5*1e5+10;
struct node{
    ll v,w;
};
vector<node>adj[MAXN+MAXM];
vector<pair<ll,ll>>can[MAXN];
ll c,n,m,d,q,w[MAXN],adjedge[MAXM][MAXM],dist[MAXM][MAXM];
void add(ll u,ll v,ll w){
    adj[u].push_back({v,w});
    adj[v].push_back({u,w});
}
void add2(ll u,ll v,ll w){
    adjedge[u][v]=w;
}
void floyd(){
    for(ll i=1;i<=n;++i){
        for(ll j=1;j<=n;++j){
            dist[i][j]=adjedge[i][j];
        }
    }
    for(ll k=1;k<=n;++k){
        for(ll i=1;i<=n;++i){
            for(ll j=1;j<=n;++j){
                if(dist[i][k]+dist[k][j]<dist[i][j]){
                    dist[i][j]=dist[i][k]+dist[k][j];
                }
            }
        }
    }
}
/*ll dij(ll s,ll t){
    vector<ll>dist(2*n+5,1e16);
    vector<bool>vis(2*n+1,0);
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>pq;
    vis[s]=1;
    dist[s]=0;
    pq.push({0,s});
    while(!pq.empty()){
        ll u=pq.top().second;
        pq.pop();
        if(vis[u])continue;
        vis[u]=1;
        for(auto [v,w]:adj[u]){
            if(dist[v]>dist[u]+w){
                dist[v]=dist[u]+w;
                pq.push({dist[v],v});
            }
        }
    }
    return dist[t];
}*/
ll ha(ll x){
    return m+x+1;
}
ll reha(ll x){
    return x-m-1;
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    FASTIO;
    cin>>c>>n>>m>>d>>q;
    for(ll i=1;i<=m;++i){
        cin>>w[i];
    }
    for(ll i=1;i<=n;++i){
        ll k;
        cin>>k;
        for(ll j=1;j<=k;++j){
            ll a,t;
            cin>>a>>t;
            add(ha(i),a,t);
            can[a].push_back({i,t});
        }
    }
    memset(dist,sizeof(dist),0x3f);
    for(ll i=1;i<=m;++i){
        ll x=ha(i);
        ll ans=0;
        for(auto [a1,w1]:adj[x]){
            for(auto [a2,w2]:adj[a1]){
                if(a2!=x){
                    ll now=reha(a2);
                    add2(i,now,w1+w2);
                }
            }
        }
    }
    floyd();
    /*for(ll i=1;i<=m;++i){
        for(ll j=1;j<=m;++j){
            cout<<dist[i][j]<<" ";
        }
        cout<<"\n";
    }*/
    for(ll i=1;i<=q;++i){
        ll a,b;
        cin>>a>>b;
        ll ans=1e16;
        for(auto [x,w1]:can[a]){
            for(auto [y,w2]:can[b]){
                ans=min(ans,dist[x][y]+w1+w2);
            }
        }
        cout<<ans+w[a]+w[b]<<"\n";
    }
    return 0;
}
