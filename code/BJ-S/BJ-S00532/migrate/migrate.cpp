#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<int> g[1000005];
int cnt[1000005];
int dis[1000005];
int a[1000005];
int n, d;

void bfs(int s)
{
    queue<int> q;
    q.push(s);
    dis[s] = 0;
    cnt[s] = 1;
    while(q.size())
    {
        int x = q.front();
        q.pop();
        for(int y : g[x])
        {
            if(dis[y] > dis[x] + 1)
            {
                dis[y] = dis[x] + 1;
                cnt[y] = cnt[x];
                q.push(y);
            }
            else if(dis[y] == dis[x] + 1)
            {
                cnt[y]++;
            }
        }
    }
}

signed main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int c, t;
    cin >> c >> t;
    while(t--)
    {
        cin >> n >> d;
        for(int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        for(int i = 1; i <= n; i++)
        {
            g[i].clear();
            for(int j = 1; j <= n; j++)
            {
                if(a[j] - a[i] <= d)
                {
                    g[i].push_back(j);
                }
            }
        }
        int ans = 0;
        for(int i = 1; i <= n; i++)
        {
            for(int j = i; j <= n; j++)
            {
                cnt[j] = 0;
                dis[j] = 1e9;
            }
            bfs(i);
            for(int j = 1; j <= n; j++)
            {
                if(cnt[j] == 2)
                {
                    ans++;
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
