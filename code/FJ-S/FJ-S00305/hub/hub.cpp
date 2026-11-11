#include<bits/stdc++.h>
#define LL long long
#define fi first
#define se second
#define gc getchar
using namespace std;

const int N=1e6+10;
int n,m,dep[N],fa[N],pos,tid,T;
vector<int>e[N];
bool flg,vis[N];

int rd(){
    int x=0;char ch=gc();
    while(!isdigit(ch))ch=gc();
    while(isdigit(ch))x=x*10+ch-'0',ch=gc();
    return x;
}

void dfs(int u,int fat){
    dep[u]=dep[fat]+1;
    if(dep[u]>=dep[pos])pos=u;
    if(flg)fa[u]=fat;
    for(int v:e[u])if(v!=fat&&!vis[v])dfs(v,u);
}
void solve(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)e[i].clear();
    for(int i=1,x,y;i<n;i++)x=rd(),y=rd(),e[x].push_back(y),e[y].push_back(x);
    flg=1;dfs(1,0);flg=0;
    int ans=n;
    for(int i=2;i<=n;i++){
        dep[fa[i]]=0;pos=0;dfs(i,fa[i]);
        int x=pos,dx=dep[pos];
        dep[i]=0;pos=0;dfs(fa[i],i);
        int y=pos,dy=dep[pos];
        vis[fa[i]]=vis[i]=1;
        pos=0;dfs(x,0);dx=max(dx,dep[pos]);
        pos=0;dfs(y,0);dy=max(dy,dep[pos]);
        ans=min(ans,max(dx>>1,dy>>1));
        vis[fa[i]]=vis[i]=0;
    }
    printf("%d\n",ans);
}

signed main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    scanf("%d%d",&tid,&T);
    while(T--)solve();
    return 0;
}