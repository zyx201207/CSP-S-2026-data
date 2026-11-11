#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

const int N = 5e5+5;

int n, m, a[N], sum[N];

bool check(int w) {
    // 固定了长度为 w
    for (int i = w; i <= n; ++i) {
        // 看 [i - w + 1, i] 能不能合成为 a[i]
        int l = i - w + 1, r = i;
        if (a[i] * w - (sum[r] - sum[l - 1]) <= m)
            return true;
    }
    return false;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    // 选定一个数字作为基准，找到比他小的数字，看能加多少。我会了吗？
    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n; ++i)
        sum[i] = sum[i - 1] + a[i];
    int l = 1, r = n, ans = 1;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (check(mid)) {
            l = mid + 1;
            ans = mid;
        } else
            r = mid - 1;
        // cout << l << ' ' << r << endl;
    }
    cout << ans << endl;
    return 0;
}

// T1 简单？大样例都过了，用了 39 minutes