#include<bits/stdc++.h>
using namespace std;
const int N=1e6+6;
int n,k,c,T,u,v,dp[N],hc[N],cd[N],ml,f[N][25],lg[N],dep[N],ans,a[N],ff[N],vis[N];
vector<int>tr[N];
void dfs(int x,int fa){
    f[x][0]=fa;
    dep[x]=dep[fa]+1;
    for(int y:tr[x]){
        if(y==fa)continue;
        dfs(y,x);
        if(dp[hc[x]]<dp[y])hc[x]=y;
    }
    dp[x]=dp[hc[x]]+1;
    for(int y:tr[x]){
        if(y==fa||y==hc[x])continue;
        cd[x]=max(cd[x],dp[y]);
    }
    ml=max(ml,cd[x]+dp[x]);
    return;
}
int lca(int x,int y){
    if(dep[y]>dep[x])swap(x,y);
    for(int i=lg[n];~i;i--)
        if(dep[f[x][i]]>=dep[y])x=f[x][i];
    if(x==y)return x;
    for(int i=lg[n];~i;i--)
        if(f[x][i]!=f[y][i])x=f[x][i],y=f[y][i];
    return f[x][0];
}
void ddd(int x){
    vis[x]=-1;
    for(int y:tr[x])
        if(vis[y]>0)ddd(y);
    return;
}
void sss(int nk,int lst){
    if(nk==0){
        v=0;
        for(int i=1;i<=n;i++){
            u=n;
            ff[i]=i;
            for(int j=1;j<=k;j++){
                c=lca(i,a[j]);
                u=min(u,dep[i]+dep[a[j]]-dep[c]*2);
            }
            v=max(u,v);
        }
        u=0;
        for(int i=1;i<=k;i++){
            if(vis[a[i]]>0){
                u++;
                ddd(a[i]);
            }
        }
        for(int i=1;i<=n;i++)if(vis[i])vis[i]=1;
        if(u<=2)ans=min(ans,v);
        return;
    }
    for(int i=lst+1;i<=n;i++){
        a[nk]=i;
        vis[i]=1;
        sss(nk-1,i);
        vis[i]=0;
    }
    return;
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>c>>T;
    while(T--){
        cin>>n>>k;
        for(int i=1;i<=n;i++){
            tr[i].clear();
            lg[i]=lg[i>>1]+1;
            cd[i]=hc[i]=dep[i]=0;
        }
        for(int i=1;i<n;i++){
            cin>>u>>v;
            tr[u].push_back(v);
            tr[v].push_back(u);
        }
        ml=0;
        dfs(1,1);
        for(int i=1;i<=lg[n];i++)
            for(int j=1;j<=n;j++)
                f[j][i]=f[f[j][i-1]][i-1];
        ans=n;
        sss(k,0);
        cout<<ans<<'\n';
    }
    return 0;
}