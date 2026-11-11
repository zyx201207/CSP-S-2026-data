#include<bits/stdc++.h>
using namespace std;
const int N=15;
int c,t,f[N],d[N][N],ans,n,k;bool vis[N][N],flag[N];vector<int> a[N];
inline int root(int x){return (f[x]==x?x:f[x]=root(f[x]));}
inline void dfs(int cur,int cnt)
{
    if(cnt>k) return;
    if(cur>n)
    {
        if(cnt!=k) return;
        for(int i=1;i<=n;i++) f[i]=i;
        for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) if(flag[i]&&flag[j]&&vis[i][j])
        {
            f[root(i)]=root(j);
        }
        int num=0;
        for(int i=1;i<=n;i++) if(flag[i]&&f[i]==i) num++;
        if(num>2) return;
        int maxx=0;
        for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) if(flag[i]&&flag[j]) maxx=max(maxx,d[i][j]);
        ans=min(ans,maxx);
        return;
    }
    flag[cur]=true;dfs(cur+1,cnt+1);flag[cur]=false;dfs(cur+1,cnt);
}
inline void init(int u,int fa,int rt,int dis)
{
    d[rt][u]=dis;
    for(auto v:a[u]) if(v!=fa) init(v,u,rt,dis+1);
}
int main()
{
    freopen("hub.in","r",stdin);freopen("hub.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>c>>t;
    while(t--)
    {
        cin>>n>>k;ans=INT_MAX;
        for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) vis[i][j]=false,a[i].clear();
        for(int i=1,x,y;i<n;i++) cin>>x>>y,vis[x][y]=true,a[x].push_back(y),a[y].push_back(x);
        for(int i=1;i<=n;i++) init(i,0,i,0);
        dfs(1,0);
        cout<<ans<<"\n";
    }
    return 0;
}