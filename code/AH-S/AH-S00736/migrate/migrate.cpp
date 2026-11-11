#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e6 + 5;

ll c, n, dis, d;
ll x[N];

void solve()
{
    cin >> n >> dis;
    for (int i = 1; i <= n; ++i) cin >> x[i];
    d = x[2] - x[1];
    if (d > dis)
    {
        cout << 0 << '\n';
        return;
    }
    int zxb = n - (dis * 2 - 1) / d;
    if (zxb > n || zxb < 0) cout << 0 << '\n';
    else cout << zxb << '\n';
    return;
}

int main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t;
    cin >> c >> t;
    while (t--) solve();
    return 0;
}
