#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e6 + 10;

int dis[N];
bool vis[N];
priority_queue<pair<int, int>> h;
vector<pair<int, int>> E[N];
void dij(int s)
{
    memset(dis, 0x3f, sizeof(dis));
    memset(vis, 0, sizeof(vis));
    dis[s] = 0;
    h.push(make_pair(0, s));
    int u;
    while (!h.empty())
    {
        u = h.top().second;
        h.pop();
        if (vis[u])
            continue;
        vis[u] = 1;
        for (auto &v : E[u])
        {
            if (dis[v.second] > dis[u] + v.first)
            {
                dis[v.second] = dis[u] + v.first;
                h.push(make_pair(dis[v.second], v.second));
            }
        }
    }
}
int w[N], a[N];
const int M = 2e3 + 10;
int ans[M][M];
signed main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int c, n, m, d, q;
    cin >> c >> n >> m >> d >> q;
    int i;
    for (i = 1; i <= m; i++)
    {
        cin >> w[i];
    }
    int k, j, t;
    for (i = 1; i <= n; i++)
    {
        cin >> k;
        for (j = 1; j <= k; j++)
        {
            cin >> a[j] >> t;
            E[a[j]].push_back(make_pair(t, m + i));
            E[m + i].push_back(make_pair(t, a[j]));
        }
    }
    int s;
    if (2 * q <= m)
    {

        while (q--)
        {
            cin >> s >> t;
            dij(s);
            cout << w[s] + w[t] + dis[t] << '\n';
        }
    }
    else
    {
        for (i = 1; i <= m; i++)
        {
            dij(i);
            memcpy(ans[i] + 1, dis + 1, m*sizeof(dis[1]));
        }
        while (q--)
        {
            cin >> s >> t;
            cout << w[s] + w[t] + ans[s][t] << '\n';
        }
    }
    return 0;
}