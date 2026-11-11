#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5;
int c,n,m,d,q,s,e,k[N],vis[510],pa[510];
ll w[N],ans,a[510][5010],t[510][5010];
vector<pair<int,int>>g[510];
ll read(){
    ll x=0*1ll,f=1ll;
    char ch=getchar();
    while(ch>'9'||ch<'0'){
        if(ch=='-')f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=x*10*1ll+ch-'0';
        ch=getchar();
    }
    return x*f;
}
void dfs(int u,int fa,int id,ll sum,int tot){
    if(vis[u])return;
    if(u==e){
        ans=min(ans,sum);
        return;
    }
    if(sum>=ans)return;
    vis[u]=1;
    for(auto[v,id1]:g[u]){
        if(v==fa)continue;
        if(fa==0)sum=t[id1][u];
        if(id1==id)dfs(v,u,id,sum,tot+1);
        else dfs(v,u,id,sum+t[id][u]+t[id1][v],tot+1);
    }
    vis[u]=0;
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    c=read(),n=read(),m=read(),d=read(),q=read();
    for(int i=1;i<=m;i++)w[i]=read();
    for(int i=1;i<=n;i++){
        k[i]=read();
        for(int j=1;j<=k[i];j++){
            a[i][j]=read();
            t[i][j]=read();
            if(j==1)continue;
            g[a[i][j]].push_back({a[i][j-1],i});
            g[a[i][j-1]].push_back({a[i][j],i});
        }
    }
    while(q--){
        s=read(),e=read();
        ans=1e18;
        dfs(s,0,0,0,1);
        printf("%lld\n",ans+w[s]+w[e]);
    }
    return 0;
}