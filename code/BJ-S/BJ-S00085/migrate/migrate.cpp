#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e6 + 5;
const int inf = 1061109567;
int c, t, n;
ll x[N], d, ans;
vector<int> e[N];
int dis[N], cnt[N];
void bfs(int s)
{
    memset(dis, 0x3f, sizeof(dis));
    memset(cnt, 0, sizeof(cnt));
    queue<int> q;
    dis[s] = 0;
    cnt[s] = 1;
    q.push(s);
    while (!q.empty())
    {
        int x = q.front();
        // cout << x << "/" << dis[x] << endl;
        q.pop();
        for (int y : e[x])
        {
            if (dis[y] != inf)
            {
                if (dis[y] == dis[x] + 1) ++ cnt[y];
                continue;
            }
            dis[y] = dis[x] + 1;
            cnt[y] = cnt[x];
            q.push(y);
        }
    }
}
void solve()
{
    ans = 0;
    cin >> n >> d;
    for (int i = 1; i <= n; i ++)
        cin >> x[i];
    if (c == 11 || c == 12)
    {
        int val = abs(x[2] - x[1]);
        if (d >= 2 * val && d < 3 * val) cout << n - 3 << endl;
        else cout << 0 << endl;
        return;
    }
    for (int i = 1; i <= n; i ++)
    {
        e[i].clear();
        for (int j = 1; j <= n; j ++)
            if (i != j && abs(x[i] - x[j]) <= d)
                e[i].push_back(j);
    }
    for (int i = 1; i <= n; i ++)
    {
        bfs(i);
        for (int j = 1; j <= n; j ++)
            if (cnt[j] == 2) ++ ans;
    }
    cout << ans / 2 << endl;
}
int main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    cin >> c >> t;
    while (t --) solve();
    return 0;
}