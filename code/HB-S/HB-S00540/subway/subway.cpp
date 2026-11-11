#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=5e5+5;
int c,n,m,d,q;
ll w[N];
ll dis[N],g[1005][1005];
int id[N];
vector<pair<int,int>> e[N];
void dij(int st){
    for(int i=1;i<=m;i++) dis[i]=1e18;
    dis[st]=0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> q;
    q.push({0,st});
    while(!q.empty()){
        int u=q.top().second;
        ll d=q.top().first;
        q.pop();
        if(d>dis[u]) continue;
        for(auto p:e[u]){
            int v=p.first;
            ll w=p.second;
            if(d+w<dis[v]){
                dis[v]=d+w;
                q.push({dis[v],v});
            }
        }
    }
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    memset(g,0,sizeof(g));
    for(int i=1;i<=n;i++){
        cin>>id[i];
        for(int j=1;j<=id[i];j++){
            int u;
            ll t;
            cin>>u>>t;
            g[i][u]=t;
        }
    }
    for(int j=1;j<=m;j++){
        for(int k=1;k<=n;k++){
            for(int i=1;i<=n;i++){
                if(g[i][j]>0&&g[k][j]>0){
                    e[j].push_back({j+1,g[i][j]+g[k][j]});
                }
            }
        }
    }
        
    while(q--){
        int x,y;
        cin>>x>>y;
        ll val=w[x]+w[y];
        dij(x);
        cout<<val+dis[y]<<'\n';
    }
    return 0;
}