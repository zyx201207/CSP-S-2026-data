#include<bits/stdc++.h>
using namespace std;
const int N=300005;
int c,t,n,k,fa[N],dep[N];
vector<int> g[N];
int sz[N],mxsz[N],cen,res,now;
int vis[N];
int dfs(int x,int f)
{
    sz[x]++;
    for(int y:g[x])
    {
        if(y==f)    continue;
        dfs(y,x);
        mxsz[x]=max(sz[y],mxsz[x]);
        sz[x]+=sz[y];
    }
    if(max(n-sz[x],mxsz[x])<=n/2)
        cen=x;
}
int calc(int u,int f,int v,int now)
{
    if(u==v)
    {
        res=min(now,res);
        return;
    }
    for(int y:g[u])
    {
        if(y==f)    continue;
        now++;
        calc(y,u,v,now);
        now--;
    }
}
int bfs(int rt,int k1)
{
    for(int i=0;i<=n;i++)
        vis[i]=0;
    queue<pair<int,int>>q;
    q.push({rt,0});
    int cnt=0;
    while(!q.empty())
    {
        int u=q.front().first;
        int s=q.front().second;
        if(vis[u])  continue;
        cnt++;
        vis[u]=s;
        if(cnt==k1)
        {
            int ans=0;
            for(int i=1;i<=n;i++)
            {
                res=0;
                for(int j=1;j<=n;j++)
                    if(vis[i])  calc(i,0,j,0);
                ans=max(ans,res);
            }
            return ans;
        }
        for(int v:g[u])
        {
            if(!vis[v])
                q.push({v,s+1});
        }
    }
    return -1;
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>t;
    while(t--)
    {
        memset(fa,0,sizeof(fa));
        memset(dep,0,sizeof(dep));
        cin>>n>>k;
        for(int i=1;i<=n;i++)
            g[i].clear();
        for(int i=1;i<n;i++)
        {
            int a,b;
            cin>>a>>b;
            g[a].push_back(b);
            g[b].push_back(a);
        }
        memset(sz,0,sizeof(sz));
        memset(mxsz,0,sizeof(mxsz));
        dfs(1,0);
        int mx1=0,mx2=0;
        for(int i:g[cen])
        {
            if(sz[i]>sz[cen])   sz[i]=n-sz[cen];
            if(!mx1)    mx1=i;
            else if(sz[i]>sz[mx1])  mx2=mx1,mx1=i;
            else if(sz[i]>sz[mx2])  mx2=i;
        }
        int ans=min(bfs(mx1,k/2)+bfs(mx2,(k+1)/2),bfs(mx1,(k+1)/2),bfs(mx2,k/2));
        cout<<ans<<'\n';
    }
    return 0;
}