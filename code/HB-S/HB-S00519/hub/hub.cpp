#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,k,ans;
vector<int>G[N];
int f[N],g[N],dp1[N],dp2[N];
int fa[N];
int X;
bool check(int u,int v){
    if(!X)return 0;
    if(fa[u]==v)return u==X;
    return v==X;
}
bool flag;
void dfs1(int x,int fa){
    if(flag)::fa[x]=fa;
    f[x]=0;dp1[x]=0;
    for(int i:G[x])if(i^fa)if(!check(i,x))dfs1(i,x),dp1[x]=max({dp1[x],dp1[i],f[x]+f[i]+1}),f[x]=max(f[x],f[i]+1);
}
void dfs2(int x,int fa){
    int mx1=0,mx2=0,mx3=0,mx4=0,mx5=0;
    for(int i:G[x])if(i^fa)if(!check(i,x)){
        if(mx1<f[i]+1)mx3=mx2,mx2=mx1,mx1=f[i]+1;
        else if(mx2<f[i]+1)mx3=mx2,mx2=f[i]+1;
        else mx3=max(mx3,f[i]+1);
        if(mx4<dp1[i])mx5=mx4,mx4=dp1[i];
        else mx5=max(mx5,dp1[i]);
    }
    for(int i:G[x])if(i^fa)if(!check(i,x)){
        if(mx1==f[i]+1)g[i]=max(g[x]+1,mx2+1),dp2[i]=max({dp2[x],g[x]+mx2,mx2+mx3});
        else if(mx2==f[i]+1)g[i]=max(g[x]+1,mx1+1),dp2[i]=max({dp2[x],g[x]+mx1,mx1+mx3});
        else g[i]=max(g[x]+1,mx1+1),dp2[i]=max({dp2[x],g[x]+mx1,mx1+mx2});
        if(dp1[i]==mx4)dp2[i]=max(dp2[i],mx5);
        else dp2[i]=max(dp2[i],mx4);
        dfs2(i,x);
    }
}
int ct[N];
void dfs3(int x,int fa){
    int mx1=g[x],mx2=0;
    for(int i:G[x])if(i^fa)if(!check(i,x)){
        if(mx1<f[i]+1)mx2=mx1,mx1=f[i]+1;
        else mx2=max(mx2,f[i]+1);
        dfs3(i,x);
    }
    ct[mx2]++;//ans<=x +=y
}
int solve(){
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)G[i].clear();
    for(int i=1,u,v;i<n;i++)scanf("%d%d",&u,&v),G[u].push_back(v),G[v].push_back(u);
    ans=n;
    flag=1;
    dfs1(1,0),dfs2(1,0);
    flag=0;
    for(int i=2;i<=n;i++)ans=min(ans,max(dp1[i]+1>>1,dp2[i]+1>>1));
    if(k==2)return printf("%d\n",ans);
    for(int i=2;i<=n;i++){
        X=i;
        for(int j=0;j<=n;j++)ct[j]=0;
        dfs1(1,0),dfs2(1,0),dfs3(1,0);
        g[i]=dp1[i]=0;
        dfs1(i,0),dfs2(i,0),dfs3(i,0);
        int nw=k;
        int sm=0;
        for(int j=0;j<=n;j++)sm+=ct[j];
        assert(sm==n);
        for(int j=n;j>=0;j--){
            nw-=ct[j];
            if(nw<0){break;}
            ans=min(ans,j);
        }
    }
    X=0;
    printf("%d\n",ans);
    return 0;
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int t;scanf("%*d%d",&t);
    while(t--)solve();
    return 0;
}