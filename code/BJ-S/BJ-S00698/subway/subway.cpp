#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int cs, n, m, d, q;
const int N = 505, M = 500005;

int ww[N], le[M]; //le biao_shi i-th subway guan_li_de qu_jian zuo_duan_dian
vector<pair<int, int>> g[3*M];
//1 M, zhan_ting; N+1 N+M, zhan_tai; N+M N+M+M, di_tei

ll dis[3*M];
ll ans[N][N];
bool vis[3*M];
priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;

int read()
{
    int x = 0;
    int f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        x = (x << 3) + (x << 1) + ch - '0';
        ch = getchar();
    }
    return f * x;
}

void dijkstra(int st)
{
    for (int i = 1; i <= 1000; i++)
        dis[i] = 1ll << 60, vis[i] = false;
    for (int i = M; i <= M+1000; i++)
        dis[i] = 1ll << 60, vis[i] = false;
    for (int i = M+M; i <= M+M+500; i++)
        dis[i] = 1ll << 60, vis[i] = false;
    while (!pq.empty()) pq.pop();
    dis[st] = 0, pq.push({0, st});
    while (!pq.empty())
    {
        ll du = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        if (vis[u]) continue;
        vis[u] = true;
        for (auto& ed : g[u])
        {
            int v = ed.first;
            if (du + ed.second < dis[v])
            {
                dis[v] = du + ed.second;
                pq.push({dis[v], v});
            }
        }
    }
}

void solve()
{
    cs = read(), n = read(), m = read(), d = read(), q = read();
    for (int i = 1; i <= m; i++)
        cin >> ww[i];
    for (int i = 1; i <= n; i++)
    {
        int k = read();
        if (i > 1) le[i] = le[i - 1] + k;
        else le[i] = M + 1;
        for (int j = 1; j <= k; j++)
        {
            int ai = read(), ti = read();
            g[ai].push_back({le[i] + j - 1, ti});
            g[le[i] + j - 1].push_back({ai, ti});
            g[M + M + i].push_back({le[i] + j - 1, 0});
            g[le[i] + j - 1].push_back({M + M + i, 0});
        }
    }
    for (int i = 1; i <= n; i++)
    {
        dijkstra(i);
        for (int j = 1; j <= n; j++)
            ans[i][j] = dis[j];
    }
    while (q-- > 0)
    {
        int x = read(), y = read();
        printf("%lld\n", ans[x][y] + ww[x] + ww[y]);
    }
}

int main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    solve();
    return 0;
}
//case1-11, 44pts
