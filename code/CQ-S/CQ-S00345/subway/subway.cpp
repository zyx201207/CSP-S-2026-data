#include<bits/stdc++.h>
using namespace std;
// #define int long long
int w[500005],k[505],x[500005],y[500005];
vector<pair<int,int>>G[10000000];
priority_queue<pair<int,int>>q;
int v[500005],d[500005];
void dijkstra(int s){
    memset(v,0,sizeof v);
    memset(d,0x3f,sizeof d);
    d[s]=0;
    q.push({0,s});
    while(q.size()){
        int x=q.top().second;
        q.pop();
        if(v[x])continue;
        v[x]=1;
        for(auto num:G[x]){
            int y=num.first,z=num.second;
            if(d[x]+z<d[y]){
                d[y]=d[x]+z;
                q.push({-d[y],y});
            }
        }
    }
}
signed main(){
    ios::sync_with_stdio(false),cin.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,dd,q;
    cin>>c>>n>>m>>dd>>q;
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            int x,y;
            cin>>x>>y;
            G[x*(n+1)+i].push_back({i,0}),G[i].push_back({x*(n+1)+i,0});
            G[x*(n+1)+i].push_back({x*(n+1),y}),G[x*(n+1)].push_back({x*(n+1)+i,y});
        }
    }
    for(int i=1;i<=q;i++)cin>>x[i]>>y[i];
    for(int i=1;i<=q;i++){
        dijkstra(x[i]*(n+1));
        cout<<d[y[i]*(n+1)]+w[x[i]]+w[y[i]]<<"\n";
    }
    return 0;
}