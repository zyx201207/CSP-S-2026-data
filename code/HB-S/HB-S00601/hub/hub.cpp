#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+5;
int c,T,n,k,fa[N],ans=1e18;
bool f[N],vis[N];
vector<int>tu[N];
int fi(int x){return fa[x]==x?x:fa[x]=fi(fa[x]);}
int dfsss(int x,int deep)
{
    if(f[x])
        return deep;
    for(int i:tu[x])
    {
        if(vis[i])
            continue;
        vis[i]=1;
        return dfsss(i,deep+1);
    }
}
void dfss(int x)
{
    for(int i:tu[x])
        if(f[i]&&!vis[i])
        {
            fa[i]=x;
            vis[i]=1;
            dfss(i);
        }
    return ;
}
void dfs(int x)
{
    if(x==n+1)
    {
        int sum=0;
        for(int i=1;i<=n;i++)
            sum+=f[i];
        if(sum!=k)
            return ;
        memset(fa,0,sizeof(fa));
        memset(vis,0,sizeof(vis));
        for(int i=1;i<=n;i++)
            if(f[i]&&!vis[i])
            {
                vis[i]=1;
                fa[i]=i;
                dfss(i);
            }
        int cnt=0;
        memset(vis,0,sizeof(vis));
        for(int i=1;i<=n;i++)
            if(f[i]&&!vis[fi(i)])
            {
                cnt++;
                vis[fi(i)]=1;
            }
        if(cnt>2)
            return ;
        int maxn=0;
        for(int i=1;i<=n;i++)
        {
            memset(vis,0,sizeof(vis));
            vis[i]=1;
            maxn=max(maxn,dfsss(i,0));
        }
        ans=min(ans,maxn);
        return ;
    }
    dfs(x+1);
    f[x]=1;
    dfs(x+1);
    return ;
}
signed main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>T;
    while(T--)
    {
        cin>>n>>k;
        for(int i=1;i<n;i++)
        {
            int x,y;
            cin>>x>>y;
            tu[x].push_back(y);
            tu[y].push_back(x);
        }
        ans=1e18;
        memset(f,0,sizeof(f));
        dfs(1);
        cout<<ans<<'\n';
    }
    return 0;
}
