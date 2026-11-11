#include<bits/stdc++.h>
using namespace std;
#define int long long
int w[500050],n,m,d,qq;
vector<int> vv[500050],tt[500050];
int g[550][550],dis[550][550],dd[550];
queue<int> q;
void spfa(int s)
{
    memset(dis[s],0x3f,sizeof(dis[s]));
    while(q.size()) q.pop();
    dis[s][s]=0;
    q.push(s);
    while(q.size())
    {
        int x=q.front();
        q.pop();
        for (int i=1;i<=n;i++)
        {
            if(dis[s][i]>dis[s][x]+g[x][i])
            {
                dis[s][i]=dis[s][x]+g[x][i];
                q.push(i);
            }
        }
    }
}
signed main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >>n>>n>>m>>d>>qq;
    for (int i=1;i<=m;i++) cin >>w[i];
    memset(g,0x3f,sizeof(g));
    for (int i=1;i<=n;i++)
    {
        int l;
        cin >>l;
        for (int j=1;j<=l;j++)
        {
            int v,t;
            cin >>v>>t;
            for (int k=0;k<vv[v].size();k++) g[vv[v][k]][i]=g[i][vv[v][k]]=min(g[vv[v][k]][i],t+tt[v][k]);
            vv[v].push_back(i);
            tt[v].push_back(t);
        }
    }
    for (int i=1;i<=n;i++) spfa(i);
    while(qq--)
    {
        memset(dd,0x3f,sizeof(dd));
        int u,v,minn=1e18;
        cin >>u>>v;
        for (int k1=0;k1<vv[u].size();k1++)
        {
            for (int k2=0;k2<vv[v].size();k2++)
            {
                int y=vv[u][k1],t1=tt[u][k1],z=vv[v][k2],t2=tt[v][k2];
                minn=min(minn,dis[y][z]+t1+t2);
            }
        }
        cout<<minn+w[u]+w[v]<<"\n";
    }
    return 0;
}
