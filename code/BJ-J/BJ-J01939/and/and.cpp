#include <bits/stdc++.h>
using namespace std;
#define int long long

int a[200020];
vector<int> g[2];

signed main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        g[1].push_back(a[i]);
    }
    int ans = 0;
    for (int ii = 30; ii >= 0; ii--)
    {
        int p = (1ll << ii), i = (ii & 1), cnt = 0;
        g[i].clear();
        for (auto v : g[i ^ 1])
        {
            if (v >= p)
            {
                cnt++;
            }
        }
        if (cnt >= m)
        {
            for (auto v : g[i ^ 1])
            {
                if (v >= p)
                {
                    g[i].push_back(v - p);
                }
            }
            ans += p;
        }
        else
        {
            for (auto v : g[i ^ 1])
            {
                if (v >= p)
                {
                    g[i].push_back(v - p);
                }
                else
                {
                    g[i].push_back(v);
                }
            }
        }
    }
    cout << ans << '\n';
    return 0;
}
