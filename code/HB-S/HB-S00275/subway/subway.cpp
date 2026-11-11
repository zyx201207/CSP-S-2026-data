#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF=1e18;
int c,n,m,d,q;
ll w[500005],dis[600005];
struct node{
    int v;ll w;
};
vector<node> G[600005];
struct Node{
    int id;ll dist;
};
bool operator<(Node xa,Node ya){
    return xa.dist>ya.dist;
}
void dij(int st,int ed){
    for(int i=1;i<=m+n;i++){
        dis[i]=INF;
    }
    dis[st]=0;
    priority_queue<Node> pq;
    pq.push({st,0});
    while(!pq.empty()){
        auto e=pq.top();pq.pop();
        int u=e.id;ll dist=e.dist;
        if(dis[u]!=dist) continue;
        for(auto ee:G[u]){
            int v=ee.v;ll w=ee.w;
            if(dis[v]>dis[u]+w){
                dis[v]=dis[u]+w;
                pq.push({v,dis[v]});
            }
        }
    }
    ll sum=dis[ed]+w[st]+w[ed];
    cout<<sum<<"\n";
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=1;j<=k;j++){
            int v;ll t;
            cin>>v>>t;
            G[i+m].push_back({v,t});
            G[v].push_back({i+m,t});
        }
    }
    for(int i=1;i<=q;i++){
        int st,ed;
        cin>>st>>ed;
        dij(st,ed);
    }
    return 0;
}