#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5,M=1005;
int c,T,n,k,ret,l[M][M];
vector<int> e[N];
int dep[N],far[N][21];
void dfs(int u,int fa){
    dep[u]=dep[fa]+1,far[u][0]=fa;
    for(int i=1;i<=20;i++) far[u][i]=far[far[u][i-1]][i-1];
    for(int v:e[u])
        if(v!=fa) dfs(v,u);
}
int lca(int u,int v){
    if(u==v) return u;
    if(dep[u]<dep[v]) swap(u,v);
    for(int i=20;i>=0;i--)
        if(dep[far[u][i]]>=dep[v]) u=far[u][i];
    if(u==v) return u;
    for(int i=20;i>=0;i--)
        if(far[u][i]!=far[v][i]) u=far[u][i],v=far[v][i];
    return far[u][0];
}
bool used[N],vis[N];
void dfs_2(int u){
    vis[u]=true;
    for(int v:e[u])
        if(!vis[v]&&used[v]) dfs_2(v);
}
void dfs_1(int cur,int k){
    if(cur==k+1){
        int sum(0);
        for(int i=1;i<=n;i++) vis[i]=false;
        for(int i=1;i<=n;i++)
            if(used[i]&&!vis[i]) sum++,dfs_2(i);
        if(sum>2) return;
        int res=0;
        for(int i=1;i<=n;i++){
            int ans=1e9;
            for(int j=1;j<=n;j++)
                if(used[j]) ans=min(ans,dep[i]+dep[j]-2*dep[lca(i,j)]);
            res=max(res,ans);
        }
        ret=min(ret,res);
        return;
    }
    for(int i=1;i<=n;i++){
        if(used[i]) continue;
        used[i]=true,dfs_1(cur+1,k),used[i]=false;
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>T;
    while(T--){
        cin>>n>>k;
        for(int i=1;i<=n;i++) e[i].clear();
        for(int i=1,u,v;i<n;i++) cin>>u>>v,e[u].push_back(v),e[v].push_back(u);
        dep[0]=1,dfs(1,0);
        if(c==1||c==2){
            ret=1e9;
            for(int i=1;i<=n;i++) used[i]=false;
            dfs_1(1,k);
            cout<<ret<<'\n';
            continue;
        }
        if(c==7){
            int res;
            ret=1e9;
            for(int i=1;i<=n;i++)
                for(int j=1;j<=n;j++) l[i][j]=lca(i,j);
            for(int i=1;i<=n;i++)
                for(int j=i+1;j<=n;j++){
                    res=0;
                    for(int k=1;k<=n;k++)
                        res=max(res,min(dep[i]+dep[k]-2*dep[l[i][k]],dep[j]+dep[k]-2*dep[l[j][k]]));
                    ret=min(ret,res);
                }
            cout<<ret<<'\n';
            continue;
        }
    }
}