#include <bits/stdc++.h>
using namespace std;
#define int long long
struct Node
{
    int id, w;
};
int w[500005], c, n, m, d, q, dis[500005];
vector<Node> a[500005];
vector<Node> b[500005];
int bfs(int s, int t)
{
    memset(dis, 0x3f, sizeof dis);
    queue<int> q;
    dis[s] = w[s];
    q.push(s);
    while (!q.empty())
    {
        int f = q.front();
        if (f == t) return dis[t] + w[t];
        q.pop();
        for (auto k : b[f])
        {
            int g = k.w;
            for (auto i : a[k.id])
            {
                if (dis[i.id] > dis[f] + i.w + g)
                {
                    dis[i.id] = dis[f] + i.w + g;
                    q.push(i.id);
                }
            }
        }
    }
    return dis[t] + w[t];
}
signed main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; i++)
    {
        cin >> w[i];
    }
    for (int i = 1; i <= n; i++)
    {
        int k;
        cin >> k;
        for (int j = 1; j <= k; j++)
        {
            int t1, t2;
            cin >> t1 >> t2;
            a[i].push_back({t1, t2});
            b[t1].push_back({i, t2});
        }
    }
    for (int i = 1; i <= q; i++)
    {
        int s, t;
        cin >> s >> t;
        cout << bfs(s, t) << endl;
    }
    return 0;
}
