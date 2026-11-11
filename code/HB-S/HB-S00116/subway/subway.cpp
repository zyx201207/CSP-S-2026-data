#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,c,d,q,w[500005],s,t,k;vector<vector<pair<ll,ll>>> g;
void dij(){
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> pq;
    vector<ll> dis(n+m+5,LLONG_MAX);dis[s]=0;pq.push({0,s});
    while(pq.size()){
        auto p=pq.top();pq.pop();
        if(p.first>dis[p.second]) continue;
        for(auto x:g[p.second]){
            if(dis[x.first]>dis[p.second]+x.second){
                dis[x.first]=dis[p.second]+x.second;
                pq.push({dis[x.first],x.first});
            }
        }
    }
    cout<<dis[t]+w[s]+w[t]<<'\n';
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;g.resize(m+n+5);
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++){
        cin>>k;
        for(int j=1,v,w;j<=k;j++){
            cin>>v>>w;
            g[m+i].push_back({v,w});
            g[v].push_back({m+i,w});
        }
    }
    while(q--){
        cin>>s>>t;
        dij();
    }
    return 0;
}
