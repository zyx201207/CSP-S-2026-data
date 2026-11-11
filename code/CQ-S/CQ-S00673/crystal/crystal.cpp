//done*
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define u unsigned
signed main()
{
    ifstream cin("crystal.in");
    ofstream cout("crystal.out");
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    u int n, m;
    cin >> n >> m;
    vector<int> a(n + 1, 0);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a.begin() + 1, a.end());
    for (int i = n; i >= 1; i--)
        a[i] -= a[i - 1];
    u int ans = 1;
    for (u int i = n; i > ans; i--)
    {
        u int cost = a[i];
        for (u int j = i - 1; j > 0; j--)
        {
            cost += cost + a[j];
            if (cost > m)
            {
                if (i - j + 1 > ans)
                    ans = i - j + 1;
                break;
            }
        }
        if (cost <= m)
            ans = max(ans, i + 1);
    }
    cout << ans << '\n';

    return 0;
}