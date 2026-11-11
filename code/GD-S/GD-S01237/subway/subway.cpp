#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+10;
int a[510][100010],t[510][100010];
int w[maxn];
int n,m,T;    
struct Node{
    int x,s;
};
vector<Node>e[maxn];
int d[maxn][510];
bool vis[maxn][510];
bool v[maxn];
void dijkstra(int s){
    queue<int>q;
    q.push(s);
    memset(d,0x3f,sizeof(d));
    memset(v,0,sizeof(v));
    for(int i=1;i<=n;i++)if(vis[s][i])d[s][i]=0;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        if(v[u])continue;
        v[u]=true;
        for(auto v:e[u]){
            for(int i=1;i<=n;i++){
                if(v.s==i)d[v.x][v.s]=d[u][i],q.push(v.x);
                else if(d[v.x][v.s]>d[u][i]+T)d[v.x][v.s]=d[u][i]+T,q.push(v.x);
            }
        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,D,q;
    cin>>c>>n>>m>>D>>q;
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=1;j<=k;j++)cin>>a[i][j]>>t[i][j],e[a[i][j]].push_back({a[i][j-1],i}),e[a[i][j-1]].push_back({a[i][j],i}),vis[a[i][j]][i]=true;
    }
    T=t[1][1];
    while(q--){
        int u,v;
        cin>>u>>v;
        dijkstra(u);
        int ans=0x3f3f3f3f;
        for(int i=1;i<=n;i++)ans=min(ans,d[v][i]);
        cout<<ans<<"\n";
    }
    return 0;
}