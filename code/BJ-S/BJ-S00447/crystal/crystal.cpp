#include <bits/stdc++.h>
using namespace std;
#define endl "\n";
#define int long long

int n, k, a[500005], s[500005], d[500005], b[500005], ans;

bool check(int x) {
    int minn = 9e18;
    for (int i = x; i <= n; i++)
        minn = min(minn, s[i] * (x - 1) - d[i - 1] + d[i - x]);
    return minn <= k;
}

signed main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) {
        s[i] = a[i] - a[i - 1];
        //cout << s[i] << " ";
    }
    for (int i = 1; i <= n; i++)
        s[i] += s[i - 1];
    for (int i = 1; i <= n; i++)
        d[i] = d[i - 1] + s[i];
    for (int i = 1; i <= n; i++) {
        b[i] = s[i] * (i - 1) - d[i - 1];
        //cout << b[i] << " ";
    }
    int l = 0, r = n;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (check(mid)) {
            l = mid + 1;
            ans = mid;
        }
        else
            r = mid - 1;
    }
    cout << ans << endl;
    return 0;
}
