#include<bits/stdc++.h>
using namespace std;
const int N=110,inf=0x3f3f3f3f;
int n,k;
int dis[N],is[N],col[N],cnt;
vector<int>g[N];
void dfs(int now)
{
    for(auto i:g[now])
    {
        if(col[now]==cnt&&is[i]) col[i]=cnt,dis[i]=min(dis[i],dis[now]);
        else dis[i]=min(dis[i],dis[now]+1);
        dfs(i); 
    }
}
void work()
{
    cin>>n>>k;
    int u,v;
    for(int i=1;i<n;i++)
    {
        cin>>u>>v;
        u--,v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int ans=inf;
    for(int i=0;i<(1<<n);i++)
    {
        if(__builtin_popcount(i)!=k) continue;
        for(int j=0;j<n;j++) 
        {
            is[j]=(i>>j)&1;
            if(is[j]) dis[j]=0;
            else dis[j]=inf;
            col[j]=-1;
        }
        cnt=0;
        
        for(int j=0;j<n;j++)
        {
            if(is[j]&&-1!=col[j]) 
            {
                ++cnt;
                if(cnt>2) break;
                col[j]=cnt;
                dfs(j);
            }
        }
        int mx=0;
        for(int j=0;j<n;j++) mx=max(mx,dis[j]);
        ans=min(ans,mx);
    }
    cout<<ans<<"\n";
    for(int i=0;i<n;i++) g[i].clear();
}
int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--)
    {
        work();
    }
}