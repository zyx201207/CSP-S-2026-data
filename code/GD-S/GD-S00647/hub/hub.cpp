#include<bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
typedef long long ll;
const int N = 5e5+6,M=21;
struct Edge{
    int to,nxt;
}e[N<<2];
int head[N],Ecnt;
void add(int u,int v){e[++Ecnt] = {v,head[u]};head[u] = Ecnt;}
int dep[N],fat[M][N],vis[N],ccnt;
int dfs(int u,int fa,int stat,bool is){
    if((stat>>u)&1) vis[u] = (is?ccnt:++ccnt);
    dep[u] = dep[fa] + 1;
    fat[0][u] = fa;
    for(int i = 1;i<M;i++) fat[i][u] = fat[i-1][fat[i-1][u]];
    for(int i=head[u];i;i=e[i].nxt){
        int v=e[i].to;
        if(v == fa) continue;
        dfs(v,u,stat,(stat>>u)&1);
    }
}
int lca(int u,int v){
    if(dep[u] < dep[v]) swap(u,v);
    for(int i= M-1;~i;i--){
        if(dep[fat[i][u]]>=dep[v]) u = fat[i][u];
    }
    if(u == v) return u;
    for(int i = M-1;~i;i--){
        if(fat[i][u] != fat[i][v]) u = fat[i][u],v=fat[i][v];
    }
    return fat[0][u];
}
int dist(int u,int v){
    int l = lca(u,v);
    return abs(dep[l]-dep[u]) + abs(dep[l] - dep[v]);
}
void sol(){
    int n,k;
    cin>>n>>k;
    Ecnt = 0;
    for(int i=1;i<=n;i++)head[i]=0;
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        add(u,v);
        add(v,u);
    }
    int ans = 2e9;
    for(int sta=0;sta<(1<<n);sta++){
        ccnt = 0;
        for(int i=1;i<=n;i++) vis[i] = 0;
        dfs(1,0,sta,0);
        if(ccnt <= 2){
            
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++) if(i!=j){
                    if(((sta>>i)&1)^((sta>>j)&1)){
                        ans = min(ans,dist(i,j));
                    }
                }
            }
        }
    }
    cout<<ans<<'\n';
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
     freopen("hub.in","r",stdin);
     freopen("hub.out","w",stdout);
    int C,T;
    cin>>C>>T;
    while(T--) sol();
    return 0;
}
//0pts
