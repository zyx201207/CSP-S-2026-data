

#include <iostream>
#include <algorithm>

#define int long long

using namespace std;

const int MAXI = 5e5 + 9;
int n, m;
int a[MAXI];
int sum[MAXI];

bool Check (int l, int r) {
    int cost = (r - l + 1) * a[r] - (sum[r] - sum[l - 1]);
    return cost <= m;
}

signed main () {

    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);

    for (int i = 1; i <= n; i++) {
        sum[i] = sum[i - 1] + a[i];
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int j = i + 1;

        int l = 1, r = i;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (Check(mid, i)) j = mid, r = mid - 1;
            else l = mid + 1;
        }

        ans = max(ans, i - j + 1);
    }
    cout << ans << '\n';

    return 0;
}
