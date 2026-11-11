#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#define fin freopen("subway.in","r",stdin);
#define fout freopen("subway.out","w",stdout);
using namespace std;
typedef long long lli;
const lli inf=11234567890123456;
int testnum,n,m,maxline,qs;
int walk_ends[500005];
vector<pair<int,int> > lines[500005];
lli g[505][505];
lli dis[505][505];
queue<int> q;
bool inqueue[505];
inline void SPFA(int start)
{
    while(!q.empty())
        q.pop();
    for(int i=1;i<=n;i++)
        inqueue[i]=0;
    lli* dist=dis[start];
    for(int i=1;i<=n;i++)
        dist[i]=inf;
    dist[start]=0;
    q.push(start);
    inqueue[start]=1;
    while(!q.empty())
    {
        int x=q.front();
        q.pop();
        for(register int i=1;i<=n;i++)
            if(dist[i]>dist[x]+g[x][i])
            {
                dist[i]=dist[x]+g[x][i];
                if(!inqueue[i])
                {
                    q.push(i);
                    inqueue[i]=1;
                }
            }
    }
}
int main()
{
    fin
    fout
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> testnum >> n >> m >> maxline >> qs;
    for(int i=1;i<=m;i++)
        cin >> walk_ends[i];
    for(int i=1;i<=n;i++)
    {
        int k,x,y;
        cin >> k;
        for(int j=1;j<=k;j++)
        {
            cin >> x >> y;
            lines[x].push_back(make_pair(i,y));
        }
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            g[i][j]=(i==j?0:inf);
    for(int i=1;i<=m;i++)
    {
        for(pair<int,int> j:lines[i])
            for(pair<int,int> k:lines[i])
                g[j.first][k.first]=min(g[j.first][k.first],lli(j.second)+k.second);
    }
    /*
    cout << "The graph is:\n";
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
            cout << g[i][j] << ' ';
        cout << endl;
    }
    cout << endl;
    //*/
    for(int i=1;i<=n;i++)
        SPFA(i);
    for(int qq=1;qq<=qs;qq++)
    {
        int x,y;
        cin >> x >> y;
        lli anss=inf;
        for(pair<int,int> j:lines[x])
            for(pair<int,int> k:lines[y])
                anss=min(anss,j.second+k.second+dis[j.first][k.first]);
        anss+=walk_ends[x]+walk_ends[y];
        cout << anss << endl;
    }
    return 0;
}
