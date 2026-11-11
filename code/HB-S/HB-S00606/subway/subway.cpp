#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[501010];
struct pp
{
    int to,w;
};
vector<pp> G[501010];
int b[501010],cnt=0;
struct node
{
    int id;
    long long dis;
    bool operator<(const node&x)const
    {
        return x.dis<dis;
    }
};
priority_queue<node> Q;
long long dd[510][510];
long long dis[501010];
bool vis[501010];
struct nn
{
    int id;
    long long dis;
};
vector<nn> E[500010];
void dij(int s)
{
    for(int i=1;i<=cnt;i++) dis[i]=1e18,vis[i]=0;
    dis[s]=0;
    Q.push({s,0});
    while(Q.size())
    {
        node u=Q.top();
        Q.pop();
        int id=u.id;
        if(vis[id]) continue;
        vis[id]=1;
        for(auto t:G[id])
        {
            int to=t.to;
            long long val=t.w;
            if(dis[to]>dis[id]+val)
            {
                dis[to]=dis[id]+val;
                if(!vis[to]) Q.push({to,dis[to]});
            }
        }
    }
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    cnt=m;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1,k;i<=n;i++)
    {
        cin>>k;
        ++cnt;
        for(int j=1,x,y;j<=k;j++)
        {
            cin>>x>>y;
            E[x].push_back({cnt,y});
            G[cnt].push_back({x,y});
            G[x].push_back({cnt,y});
        }
    }
    for(int i=m+1;i<=cnt;i++)
    {
        dij(i);
        for(int j=m+1;j<=cnt;j++) dd[i-m][j-m]=dis[j];
    }
    for(int i=1,x,y;i<=q;i++)
    {
        cin>>x>>y;
        long long ans=1e18;
        for(auto j:E[x])
        {
            for(auto k:E[y])
            {
                long long d1=j.dis,d2=k.dis;
                ans=min(ans,w[x]+w[y]+d1+d2+dd[j.id-m][k.id-m]);
            }
        }
        cout<<ans<<'\n';
    }
}