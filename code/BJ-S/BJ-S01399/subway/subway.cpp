#include <bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q;
struct edge{
    int to,cost;
};
vector<edge> v[510005];
vector<int> ans[510005];
int dis[510005],vis[510005],w[510005];

bool operator<(edge a,edge b){
    return a.cost > b.cost;
}

void solve(int st){
    for(int i=1;i<=m+n;i++){
        dis[i] = 1e15;
        vis[i] = 0;
    }
    dis[st] = 0;
    priority_queue<edge> pq;
    pq.push({st,0});
    while(!pq.empty()){
        edge t = pq.top();
        pq.pop();
        if(vis[t.to]){
            continue;
        }
        vis[t.to] = 1;
        for(int i=0;i<v[t.to].size();i++){
            edge vi = v[t.to][i];
            if(dis[vi.to] > dis[t.to] + vi.cost){
                dis[vi.to] = dis[t.to] + vi.cost;
                pq.push({vi.to,dis[vi.to]});
            }
        }
    }
    for(int i=1;i<=m;i++){
        ans[st].push_back(dis[i]);
    }
}

signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=1;j<=k;j++){
            int a,t;
            cin>>a>>t;
            v[m+i].push_back({a,t});
            v[a].push_back({m+i,t});
        }
    }
    for(int i=1;i<=q;i++){
        int x,y;
        cin>>x>>y;
        if(!ans[x].empty()){
            cout<<ans[x][y-1]+w[x]+w[y]<<'\n';
        } else if(!ans[y].empty()){
            cout<<ans[y][x-1]+w[x]+w[y]<<'\n';
        } else {
            solve(x);
            cout<<ans[x][y-1]+w[x]+w[y]<<'\n';
        }
    }
}