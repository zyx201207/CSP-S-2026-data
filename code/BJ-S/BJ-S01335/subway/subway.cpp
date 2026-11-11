#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q,cnt;
long long w[500005];
int k[505];
int a[500005];
long long t[500005];
//i=地铁口,i+m=站厅，i+2m+x=站台
vector<pair<int,int>> g[500005];
long long dis[500005];
bool vis[500005];
void dijkstra(int s)
{
    memset(dis,0x3f,sizeof dis);
    memset(vis,false,sizeof vis);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
    q.push({0,s});
    dis[s]=0;
    while(!q.empty())
    {
        pair<int,int> _=q.top();
        q.pop();
        long long d=_.first,u=_.second;
        if (vis[u])continue;
        vis[u]=true;
        for (pair<int,int> __:g[u])
        {
            int v=__.first,w=__.second;
            if (d+w<dis[v])
            {
                dis[v]=d+w;
                q.push({dis[v],v});
            }
        }
    }
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    bool flag=(m*q<=1000000&&3*m<=500000);
    for (int i=1;i<=m;++i)
    {
        cin>>w[i];
        if (flag)
        {
            g[i].push_back({i+m,w[i]});
            g[i+m].push_back({i,w[i]});
        }
    }
    int sumk=0;
    for (int i=1;i<=n;++i)
    {
        cin>>k[i];
        for (int j=1;j<=k[i];++j)
        {
            cin>>a[sumk+j]>>t[sumk+j];
            if (flag)
            {
                ++cnt;
                g[a[sumk+j]+m].push_back({2*m+cnt,t[sumk+j]});
                g[2*m+cnt].push_back({a[sumk+j]+m,t[sumk+j]});
                if (j>1)
                {
                    g[2*m+cnt].push_back({2*m+cnt-1,0});
                    g[2*m+cnt-1].push_back({2*m+cnt,0});
                }
            }
        }
        sumk+=k[i];
    }
    while(q--)
    {
        int x,y;
        cin>>x>>y;
        if (flag)
        {
            dijkstra(x);
            cout<<dis[y]<<endl;
        }
    }
    return 0;
}