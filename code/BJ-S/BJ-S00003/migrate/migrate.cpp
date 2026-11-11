#include <bits/stdc++.h>
using namespace std;
#define int long long

int vis[5010], dis[5010], cnt[5010], x[2000010], p[2000010];
vector<int> adj[5010];
signed main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int c, _;
    cin >> c >> _;
    while(_--)
    {
        int n, d;
        cin >> n >> d;
        for(int i = 1; i <= n; i++)
            cin >> x[i];
        if(c == 13 || c == 14)
        {
            int ans = 0;
            for(int i = 1; i <= n; i++)
                p[i] = lower_bound(x + 1, x + n + 1, x[i] - d) - x;
            for(int i = 1; i <= n; i++)
            {
                int pos = upper_bound(x + 1, x + n + 1, x[i] + d) - x;
                int l = pos, r = n, cnt = 0, pp = pos - 1;
                while(l <= r)
                {
                    int mid = (l + r) >> 1;
                    cnt = 0;
                    if(mid + 1 <= n && x[mid + 1] - x[i] <= d)
                        cnt++;
                    if(mid + 2 <= n && x[mid + 2] - x[i] <= d)
                        cnt++;
                    if(mid + 3 <= n && x[mid + 3] - x[i] <= d)
                        cnt++;
                    if(i - 1 >= 1 && x[mid] - x[i - 1] <= d)
                        cnt++;
                    if(i - 2 >= 1 && x[mid] - x[i - 2] <= d)
                        cnt++;
                    if(i - 3 >= 1 && x[mid] - x[i - 3] <= d)
                        cnt++;
                    cnt += max(0ll, pos - p[mid]);
                    if(cnt <= 2)
                    {
                        pp = mid;
                        l = mid + 1;
                    }
                    else
                        r = mid - 1;
                }
                ans += pp - pos + 1;
            }
            cout << ans << "\n";
            continue;
        }
        for(int i = 1; i <= n; i++)
            adj[i].clear();
        for(int i = 1; i < n; i++)
        {
            for(int j = i + 1; j <= n; j++)
            {
                if(x[j] - x[i] <= d)
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        int ans = 0;
        for(int i = 1; i <= n; i++)
        {
            queue<int> q;
            for(int j = 1; j <= n; j++)
            {
                vis[j] = 0;
                dis[j] = 1e18;
                cnt[j] = 0;
            }
            q.push(i);
            vis[i] = 1;
            dis[i] = 0;
            cnt[i] = 1;
            while(q.size())
            {
                int u = q.front();
                q.pop();
                for(int j = 0; j < adj[u].size(); j++)
                {
                    int v = adj[u][j];
                    if(dis[u] + 1 < dis[v])
                    {
                        cnt[v] = cnt[u];
                        dis[v] = dis[u] + 1;
                    }
                    else if(dis[u] + 1 == dis[v])
                        cnt[v] += cnt[u];
                    if(vis[v])
                        continue;
                    vis[v] = 1;
                    q.push(v);
                }
            }
            for(int j = i + 1; j <= n; j++)
            {
                if(cnt[j] == 2)
                    ans++;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
//T3 48pts
