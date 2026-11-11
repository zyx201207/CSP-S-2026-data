#include <bits/stdc++.h>
using namespace std;
void quickio()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio();
    cin.tie(NULL);
}
using PII = pair<int, int>;
int c, n, m, d, q;
vector<int> w;
vector<vector<int>> edge; // zhan -> zhantai linjie
void dijkstra(int x, int y)
{

    int ans = w[x] + edge[x][x];
    priority_queue<PII, vector<PII>, greater<PII>> q;
    vector<int> dis(m + 1, INT_MAX);
    dis[x] = 0;
    q.push(make_pair(0, x));
    while (!q.empty())
    {
        auto now = q.top();
        q.pop();
        if (now.first > dis[now.second])
        {
            continue;
        }
        if (now.second == y)
        {
            continue;
        }
        for (int j = 1; j <= m; j++)
        {
            if (edge[now.second][j] != 0)
            {
                if (j != y)
                {
                    int newdistance = now.first + edge[now.second][j] + edge[j][j];
                    if (dis[j] > newdistance)
                    {
                        dis[j] = newdistance;
                    }
                    q.push(make_pair(newdistance, j));
                }
                else
                {
                    int newdistance = now.first + edge[now.second][j] + w[j];
                    if (dis[y] > newdistance)
                    {
                        dis[y] = newdistance;
                    }
                    q.push(make_pair(newdistance, j));
                }
            }
        }
    }
    cout << ans + dis[y] << '\n';
    // cout << "QQQ";
    // for(int i = 1; i <= m; i ++)
    // {
    //     cout << dis[i] << ' ';
    // }
    // cout << '\n';
    for (int j = 1; j <= m; j++)
    {
        edge[x][j] = dis[j];
    }
}
int main()
{
    quickio();
    cin >> c >> n >> m >> d >> q;
    w.resize(m + 1);
    edge.resize(m + 1, vector<int>(m + 1));
    for (int i = 1; i <= m; i++)
    {
        cin >> w[i]; // kou -> zhan
    }
    for (int i = 1; i <= n; i++)
    {
        int k;
        cin >> k;
        while (k--)
        {
            int a, t;
            cin >> a >> t;
            edge[i][a] = t;
        }
    }
    while (q--)
    {
        int x, y;
        cin >> x >> y;
        // cout << "qqq\n";
        dijkstra(x, y);
    }

    return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

Q * nlogn
*/