#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=510;
const int M=500010;
int c,m,n,d,q,w[M],dis[N*3][N*3];
struct node{
    int v,w;
    bool operator <(const node &x) const{return x.w<w;};
};
vector<node>ve[M+N];
void dij(int s){
    int vis[1510];
    for(int i=1;i<=n+m;i++){vis[i]=0;}
    priority_queue<node>q;
    q.push({s,0});
    dis[s][s]=0;
    while(q.size()){
        int u=q.top().v;
        q.pop();
        if(vis[u]) continue;
        vis[u]=1;
        for(auto x:ve[u]){
            int v=x.v,w=x.w;
            if(dis[s][v]>dis[s][u]+w){
                dis[s][v]=dis[s][u]+w;
                q.push({v,dis[s][v]});
            }
        }
    }
    return;
}
int bfs(int s,int t){
    int di[20510],vis[20510];
    for(int i=1;i<=n+m;i++) vis[i]=0;
    queue<int>q;
    q.push(s);
    vis[s]=1;
    di[s]=0;
    while(q.size()){
        int u=q.front();
        q.pop();
        if(u==t) return di[u];
        for(auto x:ve[u]){
            int v=x.v,w=x.w;
            if(!vis[v]){
                q.push(v);
                vis[v]=1;
                di[v]=di[u]+w;
            }
        }
    }
}
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        while(k--){
            int a,t;
            cin>>a>>t;
            ve[n+a].push_back({i,t});
            ve[i].push_back({n+a,t});
        }
    }
    if(c<=11&&c>=1){
        for(int i=1;i<=n+m;i++){
            for(int j=1;j<=n+m;j++){dis[i][j]=1e18;}
        }
        for(int i=1;i<=n+m;i++){dij(i);}
        while(q--){
            int x,y;
            cin>>x>>y;
            cout<<dis[x+n][y+n]+w[x]+w[y]<<'\n';
        }
    }
    else if(c>=12&&c<=15){
        while(q--){
            int x,y;
            cin>>x>>y;
            cout<<w[x]+w[y]+bfs(x+n,y+n)<<'\n';
        }
    }
    else{
        while(q--){cout<<0<<'\n';}
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
