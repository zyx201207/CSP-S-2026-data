#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q,x,y,w[500010],k[510],dis[600010],vis[600010];
struct node{
    int v,c;
};
vector<node> e[600010];
struct Node{
    int u,dis;
    bool operator<(const Node&x)const{
        return dis>x.dis;
    }
};
priority_queue<Node> pq;
void dijkstra(int r){
    for(int i=1;i<=n+m;i++){
        dis[i]=9e18;
        vis[i]=0;
    }
    dis[r]=0;
    pq.push({r,0});
    while(!pq.empty()){
        int u=pq.top().u;
        pq.pop();
        if(vis[u]){
            continue;
        }
        vis[u]=1;
        for(int i=0;i<e[u].size();i++){
            int v=e[u][i].v,c=e[u][i].c;
            if(dis[v]>dis[u]+c){
                dis[v]=dis[u]+c;
                pq.push({v,dis[v]});
            }
        }
    }
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            int v,c;
            cin>>v>>c;
            e[m+i].push_back({v,c});
            e[v].push_back({m+i,c});
        }
    }
    while(q--){
        int x,y;
        cin>>x>>y;
        dijkstra(x);
        cout<<dis[y]+w[x]+w[y]<<"\n";
    }
    return 0;
}
