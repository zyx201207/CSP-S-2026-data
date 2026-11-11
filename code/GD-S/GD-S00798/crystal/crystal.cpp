// difficulty: yellow / *1500
// tags: two pointers
#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, m, a[500010], ans;
int sum[500010], cnt[500010];
signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) cnt[i]++, sum[i] += a[i];
	for (int i = 1; i <= n; i++) cnt[i] += cnt[i - 1], sum[i] += sum[i - 1];
	int l = 1;
	for (int r = 1; r <= n; r++) {
		while (l < r) {
			int hi_sum = (cnt[r] - cnt[l - 1]) * a[r];
			int lo_sum = sum[r] - sum[l - 1];
			if (hi_sum - lo_sum > m) l++;
			else break;
		}
		ans = max(ans, cnt[r] - cnt[l - 1]);
	}
	cout << ans;
	return 0;
}
