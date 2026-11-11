#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c,n,m,d,Q;
ll w[500005];
vector<pair<ll,ll>> bl[500005];
vector<pair<ll,ll>> g[500505];
ll dj(ll s,ll f){
    vector<ll> dis(n+m+5,1e16);
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> q;
    q.push({0ll,s});
    dis[s]=0;
    while(!q.empty()){
        
        pair<ll,ll> e=q.top();
        q.pop();
        if(e.second==f){
            return dis[e.second];
        }
        //if(vis[e.second]) continue;
        if(dis[e.second]<e.first){
            continue;
        }
        for(pair<ll,ll> v:g[e.second]){
            //vis[v.second]=1;
            if(v.second>n&&v.second!=f) continue;
            if(dis[v.second]>dis[e.second]+v.first){
                dis[v.second]=dis[e.second]+v.first;
                q.push({dis[v.second],v.second});
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>Q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        ll k;
        cin>>k;
        while(k--){
            ll a,t;
            cin>>a>>t;
            bl[a].push_back({i,t});
        }
    }
    for(int a=1;a<=m;a++){
        if(bl[a].empty()) continue;
        for(int i=0;i<bl[a].size();i++){
            g[n+a].push_back({w[a]+bl[a][i].second,bl[a][i].first});
            g[bl[a][i].first].push_back({w[a]+bl[a][i].second,n+a});
            if(bl[a].size()==1) continue;
            for(int j=i+1;j<bl[a].size();j++){
                ll u=bl[a][i].first,v=bl[a][j].first,t=bl[a][i].second+bl[a][j].second;
                g[u].push_back({t,v});
                g[v].push_back({t,u});
            }
        }
    }
    while(Q--){
        ll s,f;
        cin>>s>>f;
        cout<<dj(n+s,n+f)<<'\n';
    }
    return 0;
}