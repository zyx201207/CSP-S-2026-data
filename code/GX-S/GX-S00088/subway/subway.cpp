#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
const int MAXN = 500050;
int c,n,m,d,q,fa[MAXN],dis[MAXN],fast[505][MAXN];
vector <pair <int,int>> t[MAXN * 4];
int dij(int s,int e)
{
    priority_queue <pair <int,int>> q;
    q.push({s,0});
    memset(dis,0x3f3f3f3f3f,sizeof(dis));
    memset(fa,-1,sizeof(fa));
    dis[s] = 0;
    while (not q.empty())
    {
        int u = q.top().first;
        q.pop();
        for (int i = 0;i < t[u].size();i++)
        {
            int v = t[u][i].first,w = t[u][i].second;
            if (v == fa[u])
            {
                continue;
            }
            if (w + dis[u] < dis[v])
            {
                dis[v] = w + dis[u];
                fa[v] = u;
                q.push({v,dis[v]});
            }
        }
    }
    for (int i = 1;i <= 2 * m;i++)
    {
        fast[s][i] = dis[i];
    }
    for (int i = 2 * m + 1;i <= 2 * m + n + 1;i++)
    {
        fast[s][i] = dis[i];
    }
    return dis[e];
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    memset(fast,-1,sizeof(fast));
    cin >> c >> n >> m >> d >> q;
    for (int i = 1;i <= m;i++)
    {
        int w;
        cin >> w;
        t[i].push_back({m + i,w});
        t[m + i].push_back({i,w});
    }
    for (int i = 1;i <= n;i++)
    {
        int num;
        cin >> num;
        for (int j = 1;j <= num;j++)
        {
            int v,w;
            cin >> v >> w;
            t[2 * m + i].push_back({m + v,w});
            t[m + v].push_back({2 * m + i,w});
        }
    }
    for (int i = 0;i < q;i++)
    {
        int x,y;
        cin >> x >> y;
        if ((fast[x][y] != -1) and (x <= 505))
        {
            cout << fast[x][y] << endl;
            continue;
        }
        cout << dij(x,y) << endl;

    }
    return 0;
}
