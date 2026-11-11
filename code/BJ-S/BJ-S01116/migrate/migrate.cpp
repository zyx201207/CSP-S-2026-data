#include <iostream>
#include <cstdio>
#include <vector>
#include <bitset>
#include <queue>
#define int long long
using namespace std;

int x[2000005], dis[2000005], cnt[2000005];
bitset<2000005> vis;
vector<int> e[2000005];
queue<pair<int, int> > q;

void slove(int cases)
{
    int n, d;
    cin >> n >> d;
    for (int i = 1; i <= n; i++)
        cin >> x[i];
    if (11 <= cases && cases <= 12)
    {
        int step = d / (x[n] - x[n - 1]);
        if (step <= 1 || step + step - 1 >= n)
            cout << "0\n";
        else
            cout << n - (step + step - 1) << '\n';
        return ;
    }
    for (int i = 1; i <= n; i++)
        e[i].clear();
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            if (x[j] - x[i] <= d)
            {
                e[i].push_back(j);
                e[j].push_back(i);
            }
        }
    }
    int nas = 0;
    for (int i = 1; i <= n; i++)
    {
        vis.reset();
        for (int j = 1; j <= n; j++)
            dis[j] = 4e18, cnt[j] = 0;
        dis[i] = 0, cnt[i] = 1;
        q.push({dis[i], i});
        while (!q.empty())
        {
            int u = q.front().second;
            q.pop();
            if (vis[u])
                continue;
            vis[u] = true;
            for (int v : e[u])
            {
                if (dis[u] + 1 < dis[v])
                    dis[v] = dis[u] + 1, cnt[v] = cnt[u];
                else if (dis[v] == dis[u] + 1)
                    cnt[v] += cnt[u];
                q.push({dis[u] + 1, v});
            }
        }
        // for (int j = 1; j <= n; j++)
        //     cerr << dis[j] << ' ' << cnt[j] << '\n';
        // cerr << '\n';
        for (int j = 1; j <= n; j++)
            if (cnt[j] == 2)
                nas++;
    }
    cout << nas / 2 << '\n';
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    int c, T;
    cin >> c >> T;
    while (T--)
        slove(c);
    return 0;
}