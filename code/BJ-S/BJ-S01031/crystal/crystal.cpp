#include <bits/stdc++.h>
#define int long long
using namespace std;

int tmp, n, m, a[500010], pre[500010], sum;

int need(int x) {return x * a[x];}

signed main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    pre[0] = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n; ++i) {
        pre[i] = pre[i - 1] + a[i];
    }
    int maxi = 0, maxj = 0, maxan = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = i; j <= n; ++j) {
            int tmp = need(j) - i * a[j] - pre[j - 1] + pre[i - 1];
            if (j - i + 1 > maxan && tmp <= m) {
                maxan = j - i + 1;
            }
        }
    }
    cout << maxan << '\n';
    return 0;
}
