#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

ll C,N,M,D,Q;
const ll kMax=2e6,Max_val=2e14,kMax2=500;
ll w[kMax+5],counts,k[kMax+5];
vector<ll> t[kMax+5];
vector<ll> ans[kMax2+5];
struct edge{
    ll val,to;
};
vector<edge> g[kMax+5];
ll dis[kMax+5],vis[kMax+5];

void dijkstra(ll st){
    for(ll i=1;i<=counts+1;i++){
        dis[i]=Max_val;
        vis[i]=false;
    }
    dis[st]=0;
    priority_queue<pair<ll,ll>,vector<pair<ll,ll> >,greater<pair<ll,ll> > > q;
    q.push({0,st});
    while(!q.empty()){
        ll idx=q.top().second;
        q.pop();
        if(vis[idx]){
            continue;
        }
        vis[idx]=true;
        for(ll i=0;i<g[idx].size();i++){
            if(dis[g[idx][i].to]>dis[idx]+g[idx][i].val){
                dis[g[idx][i].to]=dis[idx]+g[idx][i].val;
                q.push({dis[g[idx][i].to],g[idx][i].to});
            }
        }
    }
}

int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>C>>N>>M>>D>>Q;
    counts=M;
    for(ll i=1;i<=M;i++){
        cin>>w[i];
        counts++;
        g[i].push_back({w[i],counts});
        g[counts].push_back({w[i],i});
    }
    for(ll i=1;i<=N;i++){
        cin>>k[i];
        counts++;
        for(ll j=1;j<=k[i];j++){
            ll a,s;
            cin>>a>>s;
            g[a+M].push_back({s,counts});
            g[counts].push_back({s,a+M});
        }
    }
    for(ll i=1;i<=N;i++){
        dijkstra(2*M+i);
        for(ll j=1;j<=counts;j++){
            ans[i].push_back(dis[j]);
        }
    }
    for(ll i=1;i<=Q;i++){
        ll x,y;
        cin>>x>>y;
        ll now=Max_val;
        for(ll j=1;j<=N;j++){
            now=min(now,ans[j][x-1]+ans[j][y-1]);
        }
        cout<<now<<endl;
    }
    return 0;
}
