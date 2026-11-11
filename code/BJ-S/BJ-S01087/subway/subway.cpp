#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

const int N = 5e5 + 5, M = 505;

int a[N], c, n, m, d, qu, k[M];

long long dis[N];

vector<pair<int, int>> g[N];

struct node
{
    int x;
    long long sum;
    bool operator > (node a) const&
    {
        return sum > a.sum;
    }
};

priority_queue<node, vector<node>, greater<node> > q;

long long dij(int u, int v)
{
    for (int i = 1; i <= m; i++) dis[i] = 9e18;
    node t;
    t.x = u;
    t.sum = 0;
    q.push(t);
    dis[u] = 0;
    while (!q.empty())
    {
        int x = q.top().x;
        long long sum = q.top().sum;
        if (x == v)
        {
            while (!q.empty()) q.pop();
            return sum;
        }
        q.pop();
        for (int i = 0; i < g[x].size(); i++)
        {
            int xn = g[x][i].first;
            long long sumn = sum + g[x][i].second;
            if (sumn < dis[xn])
            {
                dis[xn] = sumn;
                node tmp;
                tmp.x = xn;
                tmp.sum = sumn;
                q.push(tmp);
            }
        }
    }
    return 0;
}

void solve1()
{
    while (qu--)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        printf("%lld\n", 1ll * a[u] + 1ll * a[v] + dij(u, v));
    }
}

int main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    scanf("%d%d%d%d%d", &c, &n, &m, &d, &qu);
    for (int i = 1; i <= m; i++)
    {
        scanf("%d", &a[i]);
    }
    if (c <= 11 && c >= 7)
    {
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &k[i]);
            if (k[i] == 1)
            {
                int u, v;
                scanf("%d%d", &u, &v);
                continue;
            }
            else
            {
                int u, v, w1, w2;
                scanf("%d%d%d%d", &u, &v, &w1, &w2);
                pair<int, int> t1, t2;
                t1.first = v;
                t1.second = w1 + w2;
                t2.first = u;
                t2.second = w1 + w2;
                g[u].push_back(t1);
                g[v].push_back(t2);
            }
        }
        solve1();
        return 0;
    }
    else
    {
        
    }
    return 0;
}