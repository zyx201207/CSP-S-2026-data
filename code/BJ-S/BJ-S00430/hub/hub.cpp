#include<bits/stdc++.h>
using namespace std;
const int N=114514;
int c,t,n,k,tot,head[N],nxt[N],ver[N];
bool vis[N];
void add(int u,int v){
    tot++;
    ver[tot]=v;
    nxt[tot]=head[u];
    head[u]=tot;
    return ;
}
int dfs(int x,int fa,int dis){
    if(vis[x]) return dis;
    int ans=1e9;
    for(int i=head[x];i;i=nxt[i]){
        int v=ver[i];
        if(v==fa) continue;
        ans=min(ans,dfs(v,x,dis+1));
    }
    return ans;
}
int solve(int d,int m){
    if(d>n&&m<=k){
        int ans=0;
        for(int i=1;i<=n;i++){
            ans=max(ans,dfs(i,0,0));
        }
        return ans;
    }
    int ans=1e9;
    if(m<k){
        vis[d]=1;
         ans=solve(d+1,m+1);
        vis[d]=0;
    }
    return min(ans,solve(d+1,m));
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>t;
    while(t--){
        memset(head,0,sizeof(head));
        memset(nxt,0,sizeof(nxt));
        cin>>n>>k;
        for(int i=1,u,v;i<n;i++){
            cin>>u>>v;
            add(u,v);
            add(v,u);
        }
        cout<<solve(1,0)<<endl;
    }
}

