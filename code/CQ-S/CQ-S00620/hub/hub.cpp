#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define fi first
#define se second
#define m_p make_pair
#define p_b push_back
#define mid ((l+r)>>1)
#define ls k<<1
#define rs k<<1|1
#define lowbit(x) (x&(-x))
#define ALL(x) (x).begin(),(x).end()
using namespace std;

int rd(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-') f*=-1;ch=getchar();}
    while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch-'0'),ch=getchar();
    return x*f;
}
const int N=12,INF=0x3f3f3f3f;
int n,m,vis[N],col[N],dis[N][N];
vector<int> G[N];
void dfs(int u){
    vis[u]=1;
    for(auto v : G[u]) if(!vis[v]&&col[v]) dfs(v);
}
void solve(){
    n=rd(),m=rd();
    for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)dis[i][j]=INF;
    for(int i=1;i<=n;i++)G[i].clear(),dis[i][i]=0;
    for(int i=1,u,v;i<n;i++){
        u=rd(),v=rd();
        G[u].p_b(v),G[v].p_b(u);
        dis[u][v]=dis[v][u]=1;
    }
    for(int k=1;k<=n;k++)for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
    int ans=n;
    for(int s=1;s<(1<<n);s++)if(__builtin_popcount(s)==m){
        for(int i=0;i<n;i++)col[i+1]=((s>>i)&1),vis[i+1]=0;
        int cnt=0;
        for(int i=1;i<=n;i++)if(col[i]&&!vis[i])cnt++,dfs(i);
        if(cnt>2) continue;
        int mx=0;
        for(int i=1;i<=n;i++){
            int tmp=n;
            for(int j=1;j<=n;j++) if(col[j]) tmp=min(tmp,dis[i][j]);
            mx=max(mx,tmp);
        }ans=min(ans,mx);
    }printf("%d\n",ans);
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int cas=rd(),T=rd();if(cas>3) return 0;
    while(T--)solve();
    return 0;
}