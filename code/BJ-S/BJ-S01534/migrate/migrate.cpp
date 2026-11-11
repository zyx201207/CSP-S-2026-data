#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, d;
int c, t;
int a[2005];
vector<int> e[2005];
int dis[2005];
int cnt[2005];
int ans = 0;

void solve()
{
    cin >> n >> d;
    for(int i = 1; i <= n; i++)
        e[i].clear();
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            if(abs(a[i] - a[j]) <= d)
                e[i].push_back(j);
    ans = 0;
    for(int i = 1; i <= n; i++)
    {
        memset(dis, 0x3f, sizeof dis);
        memset(cnt, 0, sizeof cnt);
        queue<pair<int, int> > q;
        q.push({i, 0});
        while(q.size())
        {
            pair<int, int> f = q.front();
            q.pop();
            if(dis[f.first] == 0x3f3f3f3f3f3f3f3f)
            {
                dis[f.first] = f.second;
            }
            if(dis[f.first] == f.second)
            {
                cnt[f.first]++;
                for(int i = 0; i < e[f.first].size(); i++)
                    if(dis[e[f.first][i]] >= f.second + 1)
                        q.push({e[f.first][i], f.second + 1});
            }
        }
        for(int j = 1; j <= n; j++)
            if(cnt[j] == 2)
                ans ++;
    }
    cout << ans / 2 << '\n';
}

signed main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    cin >> c >> t;
    while(t--)
    {
        solve();
    }

    return 0;
}