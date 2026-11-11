#include<bits/stdc++.h>
using namespace std;
#define LL long long
const int N = 505,M = 1005;
int c,n,m,d,Q,x,y,w[M],k[M],a[N][M],t[N][M];
bool vis[N][M],v[N*M];
LL dis[N*M];
struct Edge
{
    int v,w;
};
vector <Edge> e[N*M];
void add(int x,int y,int z)
{
    e[x].push_back({y,z});
}
struct Node
{
    int x,dis;
    bool operator <(const Node &b) const
    {
        return dis > b.dis;
    }
};
priority_queue <Node> q;
LL dijkstra(int s,int t)
{
    memset(v,0,sizeof v);
    memset(dis,0x3f,sizeof dis);
    for(int i = 0;i<n;i++)
    {
        dis[i*m+s] = 0;
        q.push({i*m+s,0});
    }
    while(q.size())
    {
        int x = q.top().x;
        q.pop();
        if(v[x]) continue;
        v[x] = 1;
        for(auto tt:e[x])
        {
            int y = tt.v,w = tt.w;
            if(dis[y] > dis[x] + w)
            {
                dis[y] = dis[x] + w;
                q.push({y,dis[y]});
            }
        }
    }
    LL res = 1e18;
    for(int i = 0;i<n;i++) res = min(res,dis[t+i*m]);
    return res;
}

int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>Q;
    for(int i = 0;i<m;i++) cin>>w[i];
    for(int i = 0;i<n;i++)
    {
        cin>>k[i];
        for(int j = 0;j<k[i];j++)
        {
            cin>>a[i][j]>>t[i][j];
            a[i][j]--;
            vis[i][a[i][j]] = 1;
        }
        for(int j = 0;j<k[i];j++)
            for(int l = j+1;l<k[i];l++)
            {
                add(i*m+a[i][j],i*m+a[i][l],t[i][j]+t[i][l]);
                add(i*m+a[i][l],i*m+a[i][j],t[i][j]+t[i][l]);
            }
    }
    // return 0;
    for(int i = 0;i<n;i++)
        for(int j = 0;j<i;j++)
        {
            for(int k = 0;k<m;k++)
                if(vis[i][k] && vis[j][k])
                {
                    add(j*m+k,i*m+k,0);
                    add(i*m+k,j*m+k,0);
                }
        }
    while(Q--)
    {
        cin>>x>>y;
        x--; y--;
        cout << w[x]+w[y]+dijkstra(x,y) << '\n';
    }
    return 0;
}