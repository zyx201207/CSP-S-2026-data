#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2000005,INF=1e18;
int c,t,n,m,d,ans,x[N],dis[N],num[N];
bool vis[N];
struct Edge{
    int u,w;
};
struct Side{
    int u,Dis;
    bool operator<(const Side &oth)const{
        return Dis>oth.Dis;
    }
};
vector<Edge>con[N];
priority_queue<Side>Q;
void GetData()
{
    cin>>n>>d;
    ans=0;
    for(int i=1;i<=n;i++) cin>>x[i];
    for(int i=1;i<=n;i++) con[i].clear();
}
void Init(int s)
{
    for(int i=s;i<=n;i++)
    {
        vis[i]=0,num[i]=0,dis[i]=INF;
        if(i!=s&&x[i]-x[s]<=d)
        {
            con[i].push_back({s,1});
            con[s].push_back({i,1});
        }
    }
    dis[s]=0,num[s]=1;
    Q.push({s,0});
}
void Dij(int s)
{
    Init(s);
    while(!Q.empty())
    {
        int u=Q.top().u,Dis=Q.top().Dis;
        Q.pop();
        if(!vis[u])
        {
            vis[u]=1;
            for(Edge v:con[u])
            {
                if(dis[v.u]>dis[u]+v.w)
                {
                    dis[v.u]=dis[u]+v.w,num[v.u]=num[u];
                    if(!vis[v.u]) Q.push({v.u,dis[v.u]});
                }
                else if(dis[v.u]==dis[u]+v.w) num[v.u]+=num[u];
            }
        }
    }
    for(int i=s;i<=n;i++)
        if(dis[i]!=INF&&num[i]==2) ans++;
}
signed main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>c>>t;
    while(t--)
    {
        GetData();
        for(int i=n;i>=1;i--) Dij(i);
        cout<<ans<<'\n';
    }
}
