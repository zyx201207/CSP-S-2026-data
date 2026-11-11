#include <bits/stdc++.h>
using namespace std;
int t[500005];
struct node
{
    int w, vv;
};
vector<node> v[500005];
int qd, zd;
bool operator <(const node &x, const node &y)
{
    return x.vv > y.vv;
}
bool vis[500005];
int dis[500005];
int c, n, m, d, q;
void dij()
{
    priority_queue<node> q;
    q.push({qd, 0});
    memset(dis, 0x3f, sizeof(dis));
    memset(vis, 0, sizeof(vis));
    dis[qd] = 0;
    vis[qd] = 1;
    while (!q.empty())
    {
        node x = q.top();
        q.pop();
        vis[x.w] = 1;
        for (node i:v[x.w])
        {
            dis[i.w] = min(dis[i.w], dis[x.w] + i.vv);
            if (!vis[i.w])
            {
                q.push({i.w, dis[i.w]});
            }
        }
    }
}
int main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; i++)
    {
        cin >> t[i];
    }
    for (int i = 1; i <= n; i++)
    {
        int a;
        cin >> a;
        int last = 0, last2 = 0;
        for (int j = 1; j <= a; j++)
        {
            int b, c;
            cin >> b >> c;
            if (j != 1)
            {
                v[last].push_back({b, c + last2});
                v[b].push_back({last, c + last2});
            }
            else
            {
                last = b;
                last2 = c;
            }
        }
    }
    for (int i = 1; i <= q; i++)
    {
        cin >> qd >> zd;
        dij();
        cout << dis[zd] + t[qd] + t[zd] << endl;
    }
    return 0;
}
