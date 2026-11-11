#include <bits/stdc++.h>
using namespace std;
#define il inline 
#define ll long long 
const int N=1e6+5;
int n,k;
struct edge {
    int v,nxt;
}e[N<<1];
int head[N],et=0;
il void add(int u,int v){e[++et].v=v;e[et].nxt=head[u];head[u]=et;}
il void init() {
    et=0;
    for(int i=1;i<=n;i++)head[i]=0;
}
namespace dsu {
int fa[N],siz[N];
il void init() {for(int i=1;i<=n;i++)fa[i]=i,siz[i]=1;}
il int getf(int x){return x==fa[x]?x:fa[x]=getf(fa[x]);}
il void merge(int u,int v) {
    u=getf(u),v=getf(v);
    if(u!=v) {
        if(siz[u]<siz[v])swap(u,v);
        fa[v]=u;siz[u]+=siz[v];
    }
}
}
namespace A {
int can[N],dis[105][105];
il void dfs(int u,int fa,int s) {
    for(int i=head[u];i;i=e[i].nxt) {
        int v=e[i].v;if(v==fa)continue;
        dis[s][v]=dis[s][u]+1;dfs(v,u,s);
    }
}
il int check() {dsu::init();
    for(int u=1;u<=n;u++) {
        for(int i=head[u];i;i=e[i].nxt) {
            int v=e[i].v;
            if(can[u]&&can[v])dsu::merge(u,v);
        }
    }int cnt=0;
    for(int i=1;i<=n;i++)if(can[i]&&dsu::fa[i]==i)cnt++;
    return cnt>2;
}
il void solve1() {
    for(int i=1;i<=n;i++)dfs(i,0,i);int ans=INT_MAX;
    for(int i=0;i<(1<<n);i++) {int cnt=0;
        for(int j=1;j<=n;j++)can[j]=i&(1<<(j-1))?1:0;
        for(int j=1;j<=n;j++)cnt+=can[j];
        if(cnt!=k||check())continue;
        int now=0;
        for(int j=1;j<=n;j++) {
            if(can[j])continue;
            int res=n;
            for(int k=1;k<=n;k++)if(can[k])res=min(res,dis[j][k]);
            now=max(now,res);
        }ans=min(ans,now);
    }cout<<ans<<'\n';
}    
}

il void solve() {
    cin>>n>>k;init();
    for(int i=1,u,v;i<n;i++) {
        cin>>u>>v;add(u,v),add(v,u);
    }A::solve1();
}
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int cid,T;cin>>cid>>T;while(T--)solve();
    return 0;
}
/*
0 1
5 2
1 2
2 3
3 4
4 5

0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10

*/