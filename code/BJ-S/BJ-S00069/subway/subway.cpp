#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=6e5+5;
priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> q;
vector<pair<ll,ll>> e[N],q2[N];
ll c,n,m,w[N],d1,q1;
ll d[N],vis[N],ans[N];
void Dijkstra(int s){
    memset(d,0x3f,sizeof d);
    memset(vis,0,sizeof vis);
    while(!q.empty()) q.pop();
    q.push({0,s});d[s]=0;
    while(!q.empty()){
        ll u=q.top().second; q.pop();
        if(vis[u]) continue;
        vis[u]=1;
        for(auto i : e[u]){
            ll v=i.first,w=i.second;
            if(d[v]>d[u]+w){
                d[v]=d[u]+w;
                q.push({d[v],v});
            }
        }
    }
    return;
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>c>>n>>m>>d1>>q1;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=m+1;i<=m+n;i++){
        int k; cin>>k;
        for(int j=1;j<=k;j++){
            ll v,w; cin>>v>>w;
            e[i].push_back({v,w});
            e[v].push_back({i,w});
        }
    }
    for(int i=1;i<=q1;i++){
        int u,v; cin>>u>>v;
        if(v<u) swap(u,v);
        q2[u].push_back({v,i});
    }
    for(int i=1;i<=m;i++){
        if(q2[i].empty()) continue;
        Dijkstra(i);
        for(auto j : q2[i]){
            ll v=j.first,id=j.second;
            ans[id]=d[v]+w[i]+w[v];
        }
    }
    for(int i=1;i<=q1;i++)
        cout<<ans[i]<<"\n";
    return 0;
}
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/