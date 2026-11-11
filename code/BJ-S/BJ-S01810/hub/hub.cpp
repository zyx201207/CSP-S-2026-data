#include<bits/stdc++.h>
#define ll long long
#define faster ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
const int N=15;
int C,T,ans,n,vis[N],f[N],dis[N][N],k;
vector<int> eg[N];
void dfs(int u)
{
    if(vis[u]||f[u]==0)return;
    vis[u]=1;
    for(int v:eg[u])
    {
        dfs(v);
    }
}
void getdis(int u,int fa,int rt,int w)
{
    dis[rt][u]=w;
    for(int v:eg[u])
    {
        if(v==fa)continue;
        getdis(v,u,rt,w+1);
    }
}
int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    faster;
    cin >> C >> T;
    while(T--)
    {
        cin >> n >> k;
        int u,v;
        for(int i=1;i<n;i++)
        {
            cin >> u >> v;
            eg[u].push_back(v);
            eg[v].push_back(u);
        }
        for(int i=1;i<=n;i++)
        {
            getdis(i,0,i,0);
        }
        ans=n;
        for(int s=0;s<(1<<n);s++)
        {
            if(__builtin_popcount(s)!=k)continue;
            int cnt=0,mx=0;
            for(int i=1;i<=n;i++)
            {
                vis[i]=f[i]=0;
                if(s&(1<<i-1))f[i]=1;
            }
            for(int i=1;i<=n;i++)
            {
                if(!f[i])continue;
                if(vis[i])continue;
                dfs(i);
                cnt++;
            }
            if(cnt>2)continue;
            for(int i=1;i<=n;i++)
            {
                int d=n;
                for(int j=1;j<=n;j++)
                {
                    if(f[j])d=min(d,dis[i][j]);
                }
                mx=max(mx,d);
            }
            ans=min(ans,mx);
        }
        cout << ans <<'\n';
        for(int i=1;i<=n;i++)
        {
            eg[i].clear();
        }
    }
    return 0;
}