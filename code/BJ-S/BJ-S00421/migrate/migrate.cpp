#include <bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long node[N];
struct edge
{
    int v,w;
};
vector <edge> a[N];
int w[600],cntnode;
bool vis[N];
long long dis[N];
int cnt[N];
priority_queue <pair<long long,int> > pq;
void dijkstra(int s)
{
    memset(dis,2e18,sizeof(dis));
    memset(cnt,0,sizeof(cnt));
    while(!pq.empty())
    {
        pq.pop();
    }
    memset(vis,false,sizeof(vis));
    dis[s]=0;
    vis[s]=true;
    pq.push({0,s});
    while(!pq.empty())
    {
        auto x=pq.top();
        pq.pop();
        for(edge e:a[x.second])
        {
            int y=e.v,w=e.w;
            if(dis[y]==dis[x.second]+w)
            {
                cnt[y]++;
            }
            if(!vis[y])
            {
                vis[y]=true;
                dis[y]=dis[x.second]+w;
                cnt[y]=1;
                pq.push({-dis[x.second]-w,y});
            }
        }
    }
    return ;
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int c,T;
    cin>>c>>T;
    while(T--)
    {
        int n,d;
        cin>>n>>d;
        for(int i=1;i<=n;i++)
        {
            cin>>node[i];
        }
        sort(node+1,node+n+1);
        for(int i=1;i<=n;i++)
        {
            a[i].clear();
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                if(node[j]-node[i]>d)
                {
                    break;
                }
                a[i].push_back({j,1});
                a[j].push_back({i,1});
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            dijkstra(i);
            for(int j=i+1;j<=n;j++)
            {
                if(cnt[j]==2)
                {
                    ans++;
                    //cout<<i<<' '<<j<<'\n';
                }
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
