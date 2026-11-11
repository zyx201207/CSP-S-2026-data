#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500005],dist[500505];
vector<pair<int,int>> g[500505];
vector<int> dists[500505];
int dijkstra(int s,int t){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    memset(dist,0x3f,sizeof dist);
    dist[s]=0;
    pq.push({dist[s],s});
    while(!pq.empty()){
        auto u=pq.top();
        pq.pop();
        for(auto v:g[u.second]){
            if(dist[u.second]+v.second<dist[v.first]){
                dist[v.first]=dist[u.second]+v.second;
                pq.push({dist[v.first],v.first});
            }
        }
    }
    for(int i=1;i<=n+m;i++){
        dists[s].push_back(dist[i]);
    }
    return dist[t];
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        int k,a,t;
        cin>>k;
        for(int j=1;j<=k;j++){
            cin>>a>>t;
            g[m+i].push_back({a,t});
            g[a].push_back({m+i,t});
        }
    }
    while(q--){
        int s,t;
        cin>>s>>t;
        if(dists[s].size()) cout<<w[s]+dists[s][t-1]+w[t]<<'\n';
        else cout<<w[s]+dijkstra(s,t)+w[t]<<'\n';
    }
    return 0;
}
