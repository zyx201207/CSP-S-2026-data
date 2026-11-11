#include <bits/stdc++.h>
using namespace std;
int t[2000005];
vector<int> v[2000005];
int dis[2000005];
bool vis[2000005];
int cnt[2000005];
int n, d;
struct node
{
    int w, v;
};
int bfs(int cc)
{
    queue<node> q;
    memset(dis, 0x3f, sizeof(dis));
    memset(vis, 0, sizeof(vis));
    q.push({cc, 0});
    vis[cc] = 1;
    dis[cc] = 0;
    while (!q.empty())
    {
        node k = q.front();
        q.pop();
        for (int i:v[k.w])
        {
            if (!vis[i])
            {
                q.push({i, k.v + 1});
                dis[i] = k.v + 1;
                vis[i] = 1;
                cnt[i] = 1;
            }
            else if(vis[i] && k.v + 1 == dis[i])
            {
                cnt[i] ++;
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (cnt[i] == 2)
            ans ++;
    }
    return ans;
}
int main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    int C, T;
    cin >> C >> T;
    while (T --)
    {
        cin >> n >> d;
        if (C <= 10)
        {
            memset(t, 0, sizeof(t));
            for (int i = 1; i <= n; i++)
            {
                v[i].clear();
            }
            for (int i = 1; i <= n; i++)
            {
                cin >> t[i];
            }
            sort(t + 1, t + n + 1);
            for (int i = 1; i < n; i++)
            {
                for (int j = i + 1; j <= n; j++)
                {
                    if (t[j] - t[i] <= d)
                    {
                        v[i].push_back(j);
                    }
                }
            }
            long long sum = 0;
            for (int i = 1; i <= n; i++)
            {
                sum += bfs(i);
            }
            cout << sum << endl;
        }
    }
    return 0;
}
