#include<bits/stdc++.h>
#define int long long
using namespace std;
int read(){
    int x=0,f=1;
    char ch=getchar();
    while(!isdigit(ch)){
        if(ch=='-')f=-1;
        ch=getchar();
    }
    while(isdigit(ch)){
        x=(x<<1)+(x<<3)+(ch^48);
        ch=getchar();
    }
    return x*f;
}
const int N=1e6+10;
vector<int>edge[N];
int c,t,n,k,vis[N];
bool vvis[N];
int f[N][20];
int dep[N];
int ans;
void check(int u){
    vvis[u]=1;
    for(auto i:edge[u]){
        if(vvis[i]||!vis[i])continue;
        check(i);
    }
    return ;
}
void init(int u,int fa){
    dep[u]=dep[fa]+1;
    f[u][0]=fa;
    for(int i=1;i<=20;i++)f[u][i]=f[f[u][i-1]][i-1];
    for(auto i:edge[u]){
        if(i==fa)continue;
        init(i,u);
    }
    return ;
}
int lca(int u,int v){
    if(dep[u]<dep[v])swap(u,v);
    for(int i=20;i>=0;i--)
        if(dep[f[u][i]]>=dep[v])u=f[u][i];
    if(u==v)return u;
    for(int i=20;i>=0;i--)
        if(f[u][i]!=f[v][i]){u=f[u][i];v=f[v][i];}
    return u;
}
void dfs(int depth,int sum){
    if(sum>k)return ;
    if(depth==n+1){
        for(int i=1;i<=n;i++){vvis[i]=0;dep[i]=0;}
        for(int i=1;i<=n;i++)
        for(int j=0;j<=20;j++)f[i][j]=0;
        int cnt=0;
        for(int i=1;i<=n;i++){
            if(vvis[i]||!vis[i])continue;
            check(i);
            cnt++;
        }
        if(sum==k&&cnt<=2){
            init(1,0);
            int sum=0;
            for(int i=1;i<=n;i++){
                if(vis[i])continue;
                int di=1e18;
                for(int j=1;j<=n;j++){
                    if(!vis[j])continue;
                    di=min(di,dep[i]+dep[j]-2*dep[lca(i,j)]-1);
                }
                sum=max(sum,di);
                // cerr<<sum<<"\n";
            }
            ans=min(ans,sum);
        }
        return ;
    }
    vis[depth]=1;
    dfs(depth+1,sum+1);
    vis[depth]=0;
    dfs(depth+1,sum);
    return ;
}
signed main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    c=read();t=read();
    while(t--){
        n=read();k=read();
        for(int i=1;i<n;i++){
            int u=read(),v=read();
            edge[u].push_back(v);
            edge[v].push_back(u);
        }
        ans=1e18;
        dfs(1,0);
        printf("%lld\n",ans+1);
        for(int i=1;i<=n;i++)edge[i].clear();
    }
    return 0;
}
