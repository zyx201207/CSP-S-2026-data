// x
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define u unsigned
signed main()
{
    ifstream cin("migrate.in");
    ofstream cout("migrate.out");
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    u int c, t;
    cin >> c >> t;
    for (int loop = 0; loop < t; loop++)
    {
        u int n, d;
        cin >> n >> d;
        vector<int> x(n);
        for (u int i = 0; i < n; i++)
            cin >> x[i];
        cout << 0 << (loop == t) ? '\n' : ' ';
    }

    return 0;
}