#include <bits/stdc++.h>
#define pii pair<int, int>
#define pli pair<long long, int>
#define mkp make_pair
#define fi first
#define se second
using namespace std;
int n, m, c, d, q;
int out[500010];
vector <pii>e[500510];
int cst[500010][2];

long long bfs(int x, int y)
{
    long long dist[500510];
    memset(dist, -1, sizeof dist);
    dist[x] = 0;
    queue<int> q;
    q.push(x);
    while (!q.empty())
    {
        int k = q.front();
        q.pop();
        if (k == y)
        {
            return dist[k];
        }
        for (auto i : e[k])
        {
            if (dist[i.fi] != -1)
            {
                continue;
            }
            dist[i.fi] = dist[k] + i.se;
            q.push(i.fi);
        }
    }
    return -1;
}

long long dijsktra(int s, int t)
{
    long long dist[500510];
    memset(dist, 0x3f, sizeof dist);
    priority_queue<pli, vector<pli>, greater<pli>> pq;
    pq.push(mkp(0, s));
    dist[s] = 0;
    while (!pq.empty())
    {
        int dis = pq.top().fi, id = pq.top().se;
        // cout << dis << " " << id << endl;
        pq.pop();
        if (id == t)
        {
            return dis;
        }
        for (auto i : e[id])
        {
            if (dist[i.fi] > dis + i.se)
            {
                dist[i.fi] = dis + i.se;
                pq.push(mkp(dist[i.fi], i.fi));
            }
        }
    }
    return -1;
}

int main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; i++)
    {
        scanf("%d", &out[i]);
    }
    if (12 <= c && c <= 19)
    {
        for (int i = 1; i <= n; i++)
        {
            int k;
            scanf("%d", &k);
            for (int j = 1; j <= k; j++)
            {
                int a, t;
                scanf("%d%d", &a, &t);
                e[i+m].push_back(mkp(a, t));
                e[a].push_back(mkp(i + m, t));
            }
        }
        for (int i = 1; i <= q; i ++)
        {
            int x, y;
            scanf("%d%d", &x, &y);
            printf("%lld\n", bfs(x, y) + out[x] + out[y]);
        }
    }
    else
    {
        for (int i = 1; i <= n; i++)
        {
            int k;
            scanf("%d", &k);
            for (int j = 1; j <= k; j++)
            {
                int a, t;
                scanf("%d%d", &a, &t);
                e[i+m].push_back(mkp(a, t));
                e[a].push_back(mkp(i + m, t));
            }
        }
        for (int i = 1; i <= q; i ++)
        {
            int x, y;
            scanf("%d%d", &x, &y);
            printf("%lld\n", dijsktra(x, y) + out[x] + out[y]);
        }
    }
}