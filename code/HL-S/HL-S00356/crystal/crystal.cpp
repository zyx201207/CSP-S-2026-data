#include <bits/stdc++.h>

using namespace std;

#define int long long

const int N = 1e6 + 10;

int n, m, a[N], s[N];

signed main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
	cin.tie(0)->ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort (a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int l = 1, r = i, res = 0;
        while (l <= r) {
            int mid = (l + r) / 2;
            if ((i - mid + 1) * a[i] - s[i] + s[mid - 1] <= m) r = (res = mid) - 1;
            else l = mid + 1;
        }
        ans = max(ans, i - res + 1);
    }
    cout << ans;
	return 0;
}