#include <bits/stdc++.h>
using namespace std;
const int N=1005,M=505;
int g[N][N],ng[N][N],vis[N],t[N];
int fa[N];
int find(int x){
    if(fa[x]!=x) fa[x]=find(fa[x]);
    return fa[x];
}
int dfs(int x,int n,int stp){
    if(t[x]==1){
        return stp;
    }
    int dis=1e9;
    vis[x]=1;
    for(int i=1;i<=n;i++){
        if(i==x && !vis[i] && g[x][i]){
            int nkk=dfs(i,n,stp+1);
            dis=min(dis,nkk);
        }
    }
    return dis;
}
int c,T;
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>T;
    while(T--){
        memset(g,0,sizeof g);
        int n,k;
        cin>>n>>k;
        for(int i=1;i<=n;i++){
            int u,v;
            cin>>u>>v;
            g[u][v]=g[v][u]=1;
        }
        int nans=1e9;
        for(int mask=1;mask<(1<<n);mask++){
            memset(t,0,sizeof t);
             for(int j=0;j<n;j++){
                if((mask>>j)&1){
                    t[j+1]=1;
                }
             }
             int ans=0;
             for(int i=1;i<=n;i++){
                memset(vis,0,sizeof vis);
                int nk=dfs(i,n,0);
                ans=max(nk,ans);
             }
             nans=min(ans,nans);
        }
        cout<<nans<<'\n';
    }

}
