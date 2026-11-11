#include<iostream>
#include<vector>
#define int long long
using namespace std;
const int N = 5e5 + 10,M = 500 + 10,inf = 1e18;
int c,n,m,d,q,W[N + 1],dis[M + 1][M + 1];
struct node{
    int v,w;
};
vector<node> g[N + 1];
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i = 1;i <= m;i++) cin>>W[i];
    for(int i = 1;i <= n;i++){
        int k;
        cin>>k;
        for(int j = 1;j <= k;j++){
            int v,w;
            cin>>v>>w;
            g[i + m].push_back({v,w});
            g[v].push_back({i + m,w});
        }
    }
    for(int i = 1;i <= n;i++)
        for(int j = 1;j <= n;j++)
            if(i != j) dis[i][j] = inf;
    for(int i = 1;i <= m;i++)
        for(node tmp : g[i])
            for(node tmp2 : g[i]){
                int u = tmp.v - m,v = tmp2.v - m,w = tmp.w + tmp2.w;
                if(u == v) continue;
                dis[u][v] = min(dis[u][v],w);
                dis[v][u] = min(dis[v][u],w);
            }
    for(int k = 1;k <= n;k++)
        for(int i = 1;i <= n;i++)
            for(int j = 1;j <= n;j++)
                dis[i][j] = min(dis[i][j],dis[i][k] + dis[k][j]);
    while(q--){
        int x,y;
        cin>>x>>y;
        int ans = inf;
        for(node tmp : g[x])
            for(node tmp2 : g[y]){
                int u = tmp.v - m,v = tmp2.v - m,w = tmp.w + tmp2.w;
                ans = min(ans,dis[u][v] + w);
            }
        cout<<ans + W[x] + W[y]<<"\n";
    }
}
