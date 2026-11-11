#include <bits/stdc++.h>
#define debug(x) cerr << #x << " " << x << '\n';

using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    int t;
    for (int i = 0; i < n - 1; i++)
        cin >> t >> t;
    cout << k / 2;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);

    int c;
    int T = 1;
    cin >> c >> T;
    while (T--)
        solve();
    return 0;
}
// GOD