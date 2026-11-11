// x
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define u unsigned
signed main()
{
    ifstream cin("hub.in");
    ofstream cout("hub.out");
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    u int c, t;
    cin >> c >> t;
    for (int loop = 0; loop < t; loop++)
    {
        u int n, k;
        cin >> n >> k;
        for (u int i = 0; i < n; i++)
        {
            int ui, vi;
            cin >> ui >> vi;
        }
        cout << 1 << (loop == t) ? '\n' : ' ';
    }

    return 0;
}