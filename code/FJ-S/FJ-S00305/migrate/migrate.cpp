#include<bits/stdc++.h>
#define LL long long
#define fi first
#define se second
#define gc getchar
using namespace std;

const int N=2e6+10;
int tid,T,n,dep[N],t[N],idx,fa[N],D,tt,dis[N],cnt[N];
LL m,a[N];
bool vis[N];
vector<int>e[N],g[N],p[N];

LL rd(){
    int f=1;
    LL x=0;char ch=gc();
    while(!isdigit(ch))f=(ch=='-'?-f:f),ch=gc();
    while(isdigit(ch))x=x*10+ch-'0',ch=gc();
    return x*f;
}

// void dfs(int u,int k){
//     int w=0;
//     vis[u]=1;
//     p.push_back(u);
//     for(int v:e[u]){
//         g[v].push_back(u);
//         if(k)g[v].push_back(k);
//         if(w)g[w].push_back(v);
//         dfs(v,w);
//         w=v;
//     }
// }
void bfs(int st){
    queue<int>q;
    // printf("%d\n",st);
    dis[st]=cnt[st]=1;q.push(st);
    while(q.size()){
        int u=q.front();q.pop();
        // printf("%d ",u);
        for(int v:g[u])
            if(!dis[v])dis[v]=dis[u]+1,cnt[v]=1,q.push(v);
            else if(dis[v]==dis[u]+1)cnt[v]=min(3,cnt[v]+cnt[u]);
    }
}

void solve(){
    scanf("%d%lld",&n,&m);
    for(int i=1;i<=n;i++)a[i]=rd(),e[i].clear(),g[i].clear(),vis[i]=0;
    for(int i=1;i<=n;i++){
        int j=upper_bound(a+1,a+n+1,a[i]+m)-a-1;
        if(j!=i)e[j].push_back(i),fa[i]=j;
        for(int k=i+1;k<=j;k++)g[i].push_back(k);
    }
    LL ans=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)dis[j]=0,cnt[j]=0;
        bfs(i);
        for(int j=1;j<=n;j++)if(cnt[j]==2)ans++;
    }
    
    // for(int i=n;i>=1;i--)if(!vis[i]){
    //     p.clear();dfs(i,0);
    //     for(int u:p){
    //         for(int v:p)dis[v]=0,cnt[v]=0;
    //         bfs(u);
    //         for(int v:p)if(cnt[v]==2)ans++;
    //     }
    // }
    // for(int i=1;i<=n;i++){
    //     printf("%d: ",i);
    //     for(int j:g[i])printf("%d ",j);puts("");
    // }
    printf("%lld\n",ans);
}

signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%d%d",&tid,&T);
    while(T--)solve();
    return 0;
}