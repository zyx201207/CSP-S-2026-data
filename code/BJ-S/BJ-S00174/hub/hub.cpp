#include <bits/stdc++.h>
#define N 2000002
#define ll long long
using namespace std;
const int inf=0x3f3f3f3f;
int c,T,n,k,dep[N],f[N][3][2],g[3][2],fa[N][22];
bool vis[N],flg[N];
vector<int> e[N];
struct node{int u,d;};
bool operator <(node a,node b){return a.d<b.d;}
priority_queue<node> q;
void dfs(int u,int f){
    dep[u]=dep[f]+1,fa[u][0]=f;
    for(int v:e[u]){
        if(v==f)  continue;
        dfs(v,u);
    }
}
void dfs2(int u,int x,int f){
    if(x<0)  return;
    vis[u]=1;
    for(int v:e[u]){
        if(v==f)  continue;
        dfs2(v,x-1,u);
    }
}
// f[u][i][j]: u 为根子树，连通块个数为 i，u 选 / 不选
void dfs3(int u,int fa){
    f[u][1][1]=1,f[u][1][0]=f[u][2][0]=f[u][2][1]=f[u][0][1]=inf;
    if(flg[u])  f[u][0][0]=inf;
    for(int v:e[u]){
        if(v==fa)  continue;
        dfs3(v,u);
        g[0][0]=g[0][1]=g[1][0]=g[2][0]=g[1][1]=g[2][1]=inf;
        for(int i=0;i<=2;i++){
            for(int j=0;j<=2;j++){
                for(int k=0;k<2;k++){  // f[v][j][k]
                    int c=i+j-(k==1);
                    if(c>=0&&c<=2)  g[c][1]=min(g[c][1],f[v][j][k]+f[u][i][1]);
                    if(!flg[u]&&i+j<=2)  g[i+j][0]=min(g[i+j][0],f[v][j][k]+f[u][i][0]);
                }
            }
        }
        for(int i=0;i<=2;i++)  for(int j=0;j<2;j++)  f[u][i][j]=g[i][j];
    }
    // cout<<u<<": ";
    // for(int i=0;i<=2;i++)  for(int j=0;j<2;j++)  cout<<f[u][i][j]<<" ";
    // cout<<"\n";
}
void init(){
    for(int i=1;i<=n;i++)  dep[i]=0,e[i].clear();
    for(int i=1;i<=n;i++)  for(int j=1;j<=20;j++)  fa[i][j]=0;
}
bool check(int x){
    for(int i=1;i<=n;i++)  vis[i]=flg[i]=0,q.push({i,dep[i]}),f[i][0][0]=f[i][0][1]=f[i][1][0]=f[i][1][1]=f[i][2][0]=f[i][2][1]=0;
    while(!q.empty()){
        int u=q.top().u;q.pop();
        if(vis[u])  continue;
        int p=u;for(int i=20;i>=0;i--)  if((x>>i)&1)  p=fa[p][i];
        if(!p)  p=1;
        flg[p]=1;
        dfs2(p,x,0);
    }
    dfs3(1,0);
    int res=min(min(f[1][1][0],f[1][1][1]),min(f[1][2][0],f[1][2][1]));
    // cerr<<x<<" "<<res<<" "<<k<<"\n";
    return res<=k;
}
void solve(){
    cin>>n>>k;
    init();
    for(int i=1;i<n;i++){
        int u,v;cin>>u>>v;
        e[u].push_back(v),e[v].push_back(u);
    }
    dfs(1,0);
    for(int i=1;i<=20;i++)  for(int j=1;j<=n;j++)  fa[j][i]=fa[fa[j][i-1]][i-1];
    int l=0,r=n;
    while(l<=r){
        int mid=(l+r)>>1;
        if(check(mid))  r=mid-1;
        else  l=mid+1;
    }
    cout<<r+1<<"\n";
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);
    cin>>c>>T;
    while(T--)  solve();
    return 0;
}