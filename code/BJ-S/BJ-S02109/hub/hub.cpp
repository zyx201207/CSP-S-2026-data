#include<bits/stdc++.h>
using namespace std;
#define int long long
int C,t,n,k,b[200001],vis[200001],dis[200001],ans;
vector<int>g[200001];
void dfs1(int u,int fa){
    vis[u]=1;
    for(int v:g[u])if(v!=fa&&b[v])dfs1(v,u);
}
void dfs2(int u,int fa,int c){
    vis[u]=1,dis[u]=c;
    for(int v:g[u])if(v!=fa&&b[v])dfs2(v,u,c+1);
}
int f(){
    int cnt=0;
    for(int i=1;i<=n;i++)vis[i]=0;
    for(int i=1;i<=n;i++){
        if(!vis[i]&&b[i]){
            dfs1(i,0);
            cnt++;
        }
        if(cnt>2)return 0;
    }
    return 1;
}
void dfs(int x,int c){
    if(c>k)return;
    if(x>n){
        if(c==k&&f()){
            int s=0;
            for(int i=1;i<=n;i++){
                int d=1e18;
                for(int j=1;j<=n;j++)dis[j]=0;
                dfs2(i,0,0);
                for(int j=1;j<=n;j++)if(b[j]&&j!=i)d=min(d,dis[j]);
                s=max(s,d);
            }
            ans=min(ans,s);

        }
        return;
    }
    b[x]=0,dfs(x+1,c),b[x]=1,dfs(x+1,c+1);
}
signed main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>C>>t;
    while(t--){
        cin>>n>>k;
        for(int i=1,u,v;i<n;i++)cin>>u>>v,g[u].push_back(v),g[v].push_back(u);
        ans=1e18;
        dfs(1,0);
        cout<<ans<<"\n";
        for(int i=1;i<=n;i++)g[i].clear();
    }
    return 0;
}
