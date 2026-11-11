#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pil pair<int,ll>
#define pli pair<ll,int>
const int N=5e5+10;
const ll M=10000000000000000;
int c,n,m,f,q;
ll w[N],ans,dis[1010][1010];
vector<vector<pil>> g(N);
void djl(int s){
    priority_queue<pli,vector<pli>,greater<pli>> p;
    dis[s][s]=0;
    p.push({0,s});
    while(!p.empty()){
        ll d=p.top().first;
        int u=p.top().second;
        p.pop();
        if(d>dis[s][u])continue;
        for(int i=0;i<g[u].size();i++){
            auto it=g[u][i];
            int v=it.first;
            ll t=it.second;
            if(t+d<dis[s][v]){
                dis[s][v]=t+d;
                p.push({dis[s][v],v});
            }
        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>f>>q;
    for(int i=1;i<=m;i++)cin>>w[i];
    if(c<=6){
        for(int i=1;i<=m;i++)
            for(int j=1;j<=n+m;j++)dis[i][j]=M;
        for(int i=m+1;i<=m+n;i++){
            int k;
            cin>>k;
            for(int j=1;j<=k;j++){
                int v;
                ll t;
                cin>>v>>t;
                g[i].push_back({v,t});
                g[v].push_back({i,t});
            }
        }
        for(int i=1;i<=m;i++)djl(i);
        while(q--){
            int x,y;
            cin>>x>>y;
            ans=w[x]+w[y]+dis[x][y];
            cout<<ans<<endl;
        }
        return 0;
    }
    if(c>=7&&c<=11){
        for(int i=1;i<=m;i++)
            for(int j=1;j<=m;j++)dis[i][j]=M;
        for(int i=1;i<=n;i++){
            int k;
            cin>>k;
            if(k==1){
                int v1;
                ll t1;
                cin>>v1>>t1;
                continue;
            }
            int v1,v2;
            ll t1,t2;
            cin>>v1>>t1>>v2>>t2;
            g[v1].push_back({v2,t1+t2});
            g[v2].push_back({v1,t1+t2});
        }
        for(int i=1;i<=m;i++)djl(i);
        while(q--){
            int x,y;
            cin>>x>>y;
            ans=w[x]+w[y]+dis[x][y];
            cout<<ans<<endl;
        }
        return 0;
    }
    /*

    return 0;
    */
}
