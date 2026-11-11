#include<bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;
const int N=2e6+10;
int c,n,d,ans;
int a[N];
vector<int>edge[N];
int dis[N],dp[N];
int deg[N];
void topu(int s)
{
    queue<int>q;
    q.push(s);
    dp[s]=1; dis[s]=0;
    while(q.size())
    {
        int u=q.front();
        q.pop();
        for(int v:edge[u])
        {
            if(dis[v]>dis[u]+1) dis[v]=dis[u]+1,dp[v]=dp[u];
            else if(dis[v]==dis[u]+1) dp[v]+=dp[u];
            deg[v]--;
            if(!deg[v]) q.push(v);
        }
    }
}
void sub1()
{
    cin>>n>>d; ans=0;
    for(int i=1;i<=n;i++) edge[i].clear();
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n && a[j]-a[i]<=d;j++)
            edge[i].pb(j);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++) deg[j]=dp[j]=0,dis[j]=1e18;
        for(int u=i;u<=n;u++)
            for(int v:edge[u])
                deg[v]++;
        topu(i);
        for(int j=i;j<=n;j++) if(dp[j]==2) ans++;
    }
    cout<<ans<<endl;
}
void run()
{
    if(c<=10) sub1();
    else cout<<0<<endl;
}
signed main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int t;
    cin>>c>>t;
    while(t--) run();
    return 0;
}