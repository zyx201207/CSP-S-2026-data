#include <bits/stdc++.h>
#define debug(x) cerr << #x << " " << x << '\n';

using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<array<int, 32>> a(n);
    for (auto& x : a) {
        int y;
        cin >> y;
        int cnt = -1;
        while (y) {
            x[++cnt] = y & 1;
            y /= 2;
        }
    }
    vector<bool> ok(n);
    bool flg = 0;
    int ans = 0;
    for (int j = 31; j >= 0; j--) {
        if (!flg) {
            int cnt = 0;
            for (int i = 0; i < n; i++) {
                cnt += a[i][j];
            }
            if (cnt >= m) {
                flg = true;
                for (int i = 0; i < n; i++) {
                    if (a[i][j])
                        ok[i] = true;
                }
                ans += (1 << j);
            }
        } else {
            int cnt = 0;
            for (int i = 0; i < n; i++) {
                cnt += (ok[i] && a[i][j]);
            }
            if (cnt >= m) {
                ans += (1 << j);
                for (int i = 0; i < n; i++) {
                    if (ok[i] && !a[i][j])
                        ok[i] = false;
                }
            }
        }
    }
    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);

    int T = 1;
    // cin >> T;
    while (T--)
        solve();
    return 0;
}