#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N 5010
int _,T,n,d;
int x[N];
vector<int> g[N];
int dis[N],cnt[N],ans;
bool vis[N];
void bfs(int s)
{
    queue<int> q;
    q.push(s);
    dis[s]=0;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        if(vis[u]) continue;
        vis[u]=true;
        for(auto v:g[u])
        {
            if(dis[v]==dis[u]+1) cnt[v]++;
            if(dis[v]>dis[u]+1)
            {
                dis[v]=dis[u]+1;
                q.push(v);
            }
        }
    }
}
void solve()
{
    cin>>n>>d;
    for(int i=1;i<=n;i++) cin>>x[i],g[i].clear();
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(abs(x[i]-x[j])<=d)
                g[i].push_back(j);
    ans=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++) dis[j]=1e9,cnt[j]=0,vis[j]=false;
        bfs(i);
        for(int j=1;j<=n;j++)
            if(cnt[j]==1) ans++;
    }
    cout<<ans/2<<"\n";
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>_>>T;
    while(T--) solve();
    return 0;
}