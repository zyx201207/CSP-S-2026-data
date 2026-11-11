#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int MAXN=2e6+5;
const int INF=0x3f3f3f3f;
int c,T,n,d;
LL x[MAXN],dis[MAXN],dp[MAXN],ans;
bool vis[MAXN];
vector<int> adj[MAXN];

void dijkstra(int s)
{
    for(int i=1;i<=n;i++)dp[i]=0,dis[i]=INF,vis[i]=0;
    priority_queue<pair<int,int>> pq;
    dis[s]=0;
    dp[s]=1;
    pq.push({-dis[s],s});
    while(!pq.empty())
    {
        int u=pq.top().second;
        pq.pop();
        if(vis[u])continue;
        vis[u]=1;
        for(int v:adj[u])
        {
            if(dis[v]>dis[u]+1)
            {
                dis[v]=dis[u]+1;
                pq.push({-dis[v],v});
                dp[v]=dp[u];
            }
            else if(dis[v]==dis[u]+1)
            {
                dp[v]++;
            }
        }
    }
}

int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>c>>T;
    while(T--)
    {
        ans=0;
        cin>>n>>d;
        if(n==1)
        {
            cout<<"0\n";
            continue;
        }
        for(int i=1;i<=n;i++)
        {
            cin>>x[i];
            adj[i].clear();
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                if(x[j]-x[i]>d)break;
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
        for(int i=1;i<n;i++)
        {
            dijkstra(i);
            for(int j=i+1;j<=n;j++)
            {
                if(dp[j]==2)ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
