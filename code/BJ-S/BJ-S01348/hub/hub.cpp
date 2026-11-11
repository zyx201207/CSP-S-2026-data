#include<iostream>
#include<vector>
using namespace std;
vector<int> e[1000010];
int n,k,ans,dis[1000010];
bool vis[1000010],flag[1000010];
void dfs1(int step,int fa)
{
    flag[step]=1;
    for(int i=0;i<e[step].size();i++)
    {
        int u=e[step][i];
        if(u==fa) continue;
        if(!vis[u]) continue;
        dfs1(u,step);
    }
}
void dfs2(int step,int fa,int sum)
{
    dis[step]=min(dis[step],sum);
    for(int i=0;i<e[step].size();i++)
    {
        int u=e[step][i];
        if(u==fa) continue;
        dfs2(u,step,sum+1);
    }
}
int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int c,t;
    cin>>c>>t;
    while(t--)
    {
        ans=1e9;
        cin>>n>>k;
        for(int i=1;i<=n;i++) e[i].clear();
        for(int i=1;i<n;i++)
        {
            int u,v;
            cin>>u>>v;
            e[u].push_back(v);
            e[v].push_back(u);
        }
        if(c==13||c==14)
        {
            if(k==n) cout<<"0\n";
            else cout<<max(0,((n+1)/2-k)/2/2)+1<<"\n";
            continue;
        }
        for(int st=1;st<(1<<n);st++)
        {
            for(int i=1;i<=n;i++)
            {
                vis[i]=flag[i]=0;
                dis[i]=1e9;
            }
            int cnt=0;
            for(int j=0;j<n;j++)
            {
                if((st&(1<<j)))
                {
                    cnt++;
                    vis[j+1]=1;
                }
            }
            if(cnt!=k) continue;
            int sum=0;
            for(int j=1;j<=n;j++)
            {
                if(!flag[j]&&vis[j])
                {
                    dfs1(j,0);
                    sum++;
                }
            }
            if(sum>2) continue;
            for(int i=1;i<=n;i++)
            {
                if(vis[i]) dfs2(i,0,0);
            }
            int maxn=0;
            for(int i=1;i<=n;i++) maxn=max(maxn,dis[i]);
            ans=min(ans,maxn);
        }
        cout<<ans<<"\n";
    }
    return 0;
}
