#include<bits/stdc++.h>
using namespace std;
const int inf=1e9+7;
struct Fat_Catt
{
    int id,dis;
    bool operator <(const Fat_Catt &x)const
    {
        return dis>x.dis;
    }
};
struct edge
{
    int to,cost;
};
vector<vector<int>> e;
vector<vector<edge>> g;
int c,n,m,d,q;
vector<int> w;
vector<int> dis;
vector<bool> inq;
void mkms_dijstra(int s)
{
    dis.clear();
    dis.resize(m+1,inf);
    inq.clear();
    inq.resize(m+1,0);
    dis[s]=0;
    priority_queue<Fat_Catt> q;
    q.push({s,0});
    while(!q.empty())
    {
        int u=q.top().id;
        q.pop();
        for(edge ewe:g[u])
        {
            int v=ewe.to,w=ewe.cost;
            if(dis[u]+w<dis[v])
            {
                if(!inq[v])q.push({v,dis[u]+w});
                dis[v]=dis[u]+w;
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin >> c >> n >> m >> d >> q;
    e.resize(m+1,vector<int>(m+1,inf));
    w.resize(m+1);
    for(int i=1; i<=m; i++)
    {
        cin >> w[i];
    }
    for(int i=1; i<=n; i++)
    {
        int k;
        cin >>k;
        vector<int> a(k+1),t(k+1);
        for(int j=1; j<=k; j++)cin >> a[j] >> t[j];
        for(int x=1; x<=k; x++)
        {
            for(int y=x+1; y<=k; y++)
            {
                int u=a[x],v=a[y],tmp=t[x]+t[y];
                e[v][u]=e[u][v]=min(e[u][v],tmp);
            }
        }
    }
    g.resize(m+1);
    for(int i=1; i<=m; i++)
    {
        for(int j=i+1; j<=m; j++)
        {
            if(e[i][j]!=inf)
            {
                g[i].push_back({j,e[i][j]});
                g[j].push_back({i,e[i][j]});
            }
        }
    }
    e.clear();
    for(int r=1; r<=q; r++)
    {
        int a,b;
        cin >> a >> b;
        mkms_dijstra(a);
        cout << w[a]+w[b]+dis[b] << endl;
    }
    return 0;
}
