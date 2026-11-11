//?
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define u unsigned
constexpr u int C = 26, N = 501, M = 5e5 + 1, D = 21, Q = 1e5 + 1;
signed main()
{
    ifstream cin("subway.in");
    ofstream cout("subway.out");
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    u int c, n, m, d, q;
    cin >> c >> n >> m >> d >> q;
    vector<u int> w(m);
    for (int i = 0; i < m; i++)
        cin >> w[i];
    vector<vector<u int>> mp(m, vector<u int>(m, ULLONG_MAX));
    for (u int i = 0; i < n; i++)
    {
        u int k;
        cin >> k;
        vector<u int> a, t;
        for (u int j = 0; j < k; j++)
        {
            u int ai;
            cin >> ai;
            ai--;
            a.push_back(ai);
            u int ti;
            cin >> ti;
            t.push_back(ti);
            for (u int comp = 0; comp < a.size() - 1; comp++)
            {
                mp[a[comp]][ai] = min(mp[a[comp]][ai], ti + t[comp]);
                mp[ai][a[comp]] = mp[a[comp]][ai];
            }
        }
    }
    for (u int i = 0; i < m - 2; i++)
        for (u int j = i + 1; j < m; j++)
            if (mp[i][j] == ULLONG_MAX)
                for (u int alpha = 0; alpha < m; alpha++)
                    for (u int beta = 0; beta < m; beta++)
                        if (mp[i][alpha] != ULLONG_MAX && mp[j][beta] != ULLONG_MAX)
                        {
                            mp[i][j] = min(mp[i][j], mp[i][alpha] + mp[i][beta]);
                            mp[j][i] = mp[i][j];
                        }
    for (u int i = 0; i < q; i++)
    {
        int x, y;
        cin >> x >> y;
        cout << w[x - 1] + w[y - 1] + mp[x - 1][y - 1] << '\n';
    }

    return 0;
}