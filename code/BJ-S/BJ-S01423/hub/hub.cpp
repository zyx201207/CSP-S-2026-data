#include<bits/stdc++.h>
using namespace std;
int c,t,n,k,p[100],vis[100],ans,d[100],f[100];
vector<int> e[100];
void Dfs(int u,int fa){
    d[u]=d[fa]+1,f[u]=fa;
    for(int x:e[u])
        if(x!=fa)Dfs(x,u);    
}void DFS(int u){
    vis[u]=1;
    for(int x:e[u])
        if(!vis[x]&&p[x])DFS(x);
}int lca(int u,int v){
    if(d[u]<d[v])swap(u,v);
    while(d[u]>d[v])u=f[u];
    while(u!=v)u=f[u],v=f[v];
    return u;    
}void dfs(int s){
    if(s==n+1){
        int cnt=0,tot=0;
        vector<int> a;
        for(int i=1;i<=n;i++)
            cnt+=p[i],vis[i]=0;
        if(cnt!=k)return;
        for(int i=1;i<=n;i++)
            if(p[i])a.push_back(i);
        for(int x:a)if(!vis[x])
            DFS(x),tot++;
        // if(p[1]&&p[4])cout<<tot<<"\n";
        if(tot!=2)return;
        int cur=0;
        for(int i=1;i<=n;i++)
            if(!p[i]){
                int mn=1e9;
                for(int j:a)
                    mn=min(d[j]+d[i]-2*d[lca(i,j)],mn);
                cur=max(cur,mn);
            }
        ans=min(ans,cur);
        return;
    }p[s]=1,dfs(s+1);
    p[s]=0,dfs(s+1);
}int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>k;
        for(int i=1;i<n;i++){
            int u,v;cin>>u>>v;
            e[u].push_back(v);
            e[v].push_back(u);
        }ans=1e9,Dfs(1,0),dfs(1);
        cout<<ans<<"\n";
        for(int i=1;i<=n;i++)e[i].clear();
    }

}