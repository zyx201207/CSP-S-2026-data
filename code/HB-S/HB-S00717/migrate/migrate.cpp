#include <bits/stdc++.h>
using namespace std;
int c, n, t, cnt;
long long d;
long long x[2000010];
vector <int> e[2000010];

void bfs(int s)
{
    int dist[100010], vis[100010];
    memset(dist, -1, sizeof dist);
    memset(vis, -1, sizeof vis);
    dist[s] = 0;
    vis[s] = 1;
    queue<int> q;
    q.push(s);
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        for (auto i : e[x])
        {
            if (dist[i] == -1)
            {
                dist[i] = dist[x] + 1;
                q.push(i);
                vis[i] = vis[x];
                // cout << x << " " << vis[x] << "\n";
            }
            else if (dist[i] == dist[x] + 1)
            {
                // cout << x << " " << s << " " << i << " " << vis[x] << "%\n";
                vis[i] += vis[x];
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (vis[i] == 2)
        {
            cnt++;
            // cout << s << " " << i << "\n";
        }
    }
}

int main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    cin >> c >> t;
    if (c == 11 || c == 12)
    {
        for (int i = 1; i <= t; i++)
        {
            scanf("%d%lld", &n, &d);
            for (int i = 1; i <= n; i++)
            {
                scanf("%lld", &x[i]);
            }
            long long m = x[2] - x[1];
            // cout << d*2 << " " << m << "\n";
            if (d < m * 2)
            {
                printf("0\n");
            }
            else
            {
                printf("%lld\n", max(0ll, n - d/m*2 + 1));
            }
        }
    }
    else
    {
        for (int i = 1; i <= t; i ++)
        {
            scanf("%d%lld", &n, &d);
            cnt = 0;
            for (int i = 1; i <= n; i++)
            {
                e[i].clear();
                scanf("%lld", &x[i]);
                for (int j = 1; j < i; j++)
                {
                    if (abs(x[i]-x[j]) <= d)
                    {
                        e[i].push_back(j);
                        e[j].push_back(i);
                        // cout << i << " " << j << "#\n";
                    }
                }
            }
            for (int i = 1; i <= n; i++)
            {
                bfs(i);
            }
            printf("%d\n", cnt/2);
        }
    }
}