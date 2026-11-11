#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inin zjdtz
// int dxt[500][500005];
// int nums[500005];
// int mp[500][500];
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("crystal.in", "r", stdin);
    // freopen("crystal.out", "w", stdout);
    int c, n, m, d, q;
    cin >> c >> n >> m >> d >> q;
    int zjdtz[m];
    for (int i = 0; i < m; i++)
    {
        cin >> inin[i];
    }
    int ki = 0;
    int minn[n] = {0};
    vector<vector<int>> mp(n);
    // vector<vector<int>> dxt(n);
    vector<vector<pair<int, int>>> dxt(n);
    for (int i = 0; i < n; i++)
    {
        minn[i] = INT_MAX;
        cin >> ki;
        for (int j = 0; j <= ki; j++)
        {
            int a, b;
            cin >> a >> b;
            minn[j] = min(minn[j], inin[j] + b);
            for (auto aut : dxt[i])
            {
                mp[aut.first].push_back(aut.second + b);
                // mp[aut.first][i] = (aut.second + b);
                cout << i << ' ' << j << ' ' << aut.first << ' ' << aut.second << endl;
            }
            dxt[i].push_back({a, b});
            // cout << dxt[i][a];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (auto aut : mp[i])
        {
            cout << i << ' ' << aut << endl;
        }
    }
}
