#include <iostream>
#include <queue>
#include <vector>
#include <string.h>
#include <fstream>

using namespace std;

const int MAXM = 500001;

struct Edge
{
    //bool type; //0zhantai 1xianlu
    int v, t;

    const bool operator < (Edge o) const
    {
        return t > o.t;
    }
};

int c, n, m, d, q;
int w[500001], k[501];
long long dist[1001][1001];
long long ldist[501];
bool vis[MAXM + 500];
vector<Edge> gra[MAXM + 500];

int main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; i++)
        cin >> w[i];
    for (int i = 1; i <= n; i++)
    {
        cin >> k[i];
        for (int j = 1; j <= k[i]; j++)
        {
            int a, t;
            cin >> a >> t;
            int linenum = MAXM + i;
            gra[linenum].push_back({a, t});
            gra[a].push_back({linenum, t});
        }
    }
    memset(dist, 0x3f3f, sizeof(dist));
    for (int i = 1; i <= m; i++)
    {
        memset(vis, 0, sizeof(vis));
        memset(ldist, 0x3f3f, sizeof(ldist));
        priority_queue<Edge> pq;
        dist[i][i] = w[i];
        pq.push({i, w[i]});
        while (!pq.empty())
        {
            int u = pq.top().v;
            pq.pop();
            if (vis[u])
                continue;

            vis[u] = 1;
            long long udist;
            int wu;
            if (u <= MAXM)
            {
                udist = dist[i][u];
                wu = w[u];
            }
            else
            {
                udist = ldist[u - MAXM];
                wu = 0;
            }
            for (int j = 0; j < gra[u].size(); j++)
            {
                int v = gra[u][j].v;
                int t = gra[u][j].t;
                if (v <= MAXM)
                {
                    dist[i][v] = min(dist[i][v], udist - wu + t + w[v]);
                    pq.push({v, dist[i][v]});
                }
                else
                {
                    ldist[v - MAXM] = min(ldist[v - MAXM], udist - wu + t);
                    pq.push({v, ldist[v - MAXM]});
                }
            }
        }
    }
    while (q--)
    {
        int x, y;
        cin >> x >> y;
        cout << dist[x][y] + w[x] << '\n';
    }
    return 0;
}
