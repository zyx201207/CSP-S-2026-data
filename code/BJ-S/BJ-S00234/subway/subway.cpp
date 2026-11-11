#include <bits/stdc++.h>
using namespace std;
int n, m, d, w[500005], dis[500005], a[505][1005], t[505][1005], ch[1005][505];
struct dat
{
    int x, w;
};
bool operator <(dat x, dat y)
{
    return x.w > y.w;
}
vector<dat> edge[500005];
vector<dat> G[500005];
int op(int x, int y)
{
    return x + m * (y - 1);
}
void dijsktra(int s)
{
    for (int i = 1; i <= m * n; i++) dis[i] = 1e9;
    priority_queue<dat> q;
    q.push({s, 0});
    dis[s] = 0;
    while (!q.empty())
    {
        dat tmp = q.top();
        q.pop();
        int x = tmp.x, w = tmp.w;
        if (dis[x] != w) continue;
        for (dat i: G[x])
        {
            if (dis[i.x] > dis[x] + i.w)
            {
                dis[i.x] = dis[x] + i.w;
                //cout << i.x << " " << x << " " << dis[x] + i.w << endl;
                q.push({i.x, dis[i.x]});
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    int c, q;
    cin >> c >> n >> m >> d >> q;
    //cout << m << endl;
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
            cin >> a[i][j] >> t[i][j];
            ch[a[i][j]][i] = t[i][j];
            edge[a[i][j]].push_back({i, t[i][j]});
            if (j > 1)
            {
                //cout << op(a[i][j], i) << " " << op(a[i][j - 1], i) << endl;
                G[op(a[i][j], i)].push_back({op(a[i][j - 1], i), 0});
                G[op(a[i][j - 1], i)].push_back({op(a[i][j], i), 0});
            }
        }
    }
    for (int i = 1; i <= m; i++)
    {
        for (int j = 0; j < edge[i].size(); j++)
        {
            for (int k = 0; k < edge[i].size(); k++)
            {
                if (j == k) continue;
                //cout << op(i, edge[i][j].x) << " " << op(i, edge[i][k].x) << endl;
                G[op(i, edge[i][j].x)].push_back({op(i, edge[i][k].x), edge[i][j].w + edge[i][k].w});
            }
        }
    }
    for (int i = 1; i <= q; i++)
    {
        int l, r;
        cin >> l >> r;
        int ans = 1e9;
        for (int j = 0; j < edge[l].size(); j++)
        {
            dijsktra(op(l, edge[l][j].x));
            for (int k = 0; k < edge[r].size(); k++)
            {
                //cout << op(r, edge[r][k].x) << " ";
                ans = min(ans, dis[op(r, edge[r][k].x)] + w[l] + w[r] + ch[l][edge[l][j].x] + ch[r][edge[r][k].x]);
            }
        }
        cout << ans << endl;
    }
    return 0;
}