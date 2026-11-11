//T4:15pts
#include<bits/stdc++.h>
using namespace std;
constexpr int N = 30 + 10;
int c,T,n,k,ans=INT_MAX,vis[N],f[N][N],F[N];
vector<int> sta,e[N];
void dfs1(int u,int fa){
    vis[u]=1;for(auto v:e[u]) if(v!=fa && F[v]) dfs1(v,u);
}
void dfs(int now,int cnt){
    if(cnt>k) return ;
    if(now>n){
        if(cnt!=k) return ;
        int CNT=0;
        memset(vis,0,sizeof(vis));
        for(auto i:sta) if(!vis[i]) dfs1(i,0),CNT++;
        if(CNT>2) return ;CNT=0;
        // for(auto i:sta) cout<<i<<' ';cout<<'\n';
        for(auto i:sta) for(auto j:sta) CNT=max(CNT,f[i][j]);
        // cout<<CNT<<'\n';
        ans=min(ans,CNT);
        return ;
    }
    dfs(now+1,cnt);
    sta.push_back(now),F[now]=1;
    dfs(now+1,cnt+1);
    sta.pop_back(),F[now]=0;
}
signed main(){
    ios::sync_with_stdio(false),cin.tie(0);
    freopen("hub.in","r",stdin),freopen("hub.out","w",stdout);
    cin>>c>>T;
    while(T--){
        memset(f,0x3f,sizeof(f));
        for(int i=1;i<=n;++i) e[i].clear();
        cin>>n>>k;
        for(int i=1,u,v;i<n;++i) cin>>u>>v,e[u].push_back(v),e[v].push_back(u),f[u][v]=f[v][u]=1;
        for(int i=1;i<=n;++i) f[i][i]=0;
        for(int k=1;k<=n;++k){
            for(int j=1;j<=n;++j){
                for(int i=1;i<=n;++i){
                    f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
                }
            }
        }     
        // for(int i=1;i<=n;++i){
        //     for(int j=1;j<=n;++j){
        //         cout<<f[i][j]<<' ';
        //     }
        //     cout<<'\n';
        // }   
        ans=INT_MAX;
        dfs(1,0);
        cout<<ans<<'\n';
    }
    return 0;
}