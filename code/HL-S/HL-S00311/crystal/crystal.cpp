#include <bits/stdc++.h>

using namespace std;

long long n, m;
long long a[500001];
long long dif[500001];
long long cnt[500001];

void init() {
	for (int i = 2; i <= n; i++) {
		dif[i] = a[i] - a[i - 1];
		cnt[i] = cnt[i - 1] + dif[i] * (i - 1);
	}
}

long long query(int l, int r) {
	return cnt[r] - cnt[l - 1] - (a[r] - a[l - 1]) * (l - 1);
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	init();
	long long l = 1, r = n;
	long long ans = 0;
	while (l <= r) {
		long long mid = (l + r) >> 1;
		long long min_cost = 1ll << 60;
		for (int il = 1, ir = mid; ir <= n; il++, ir++) {
			min_cost = min(min_cost, query(il, ir));
		}
		if (min_cost <= m) {
			l = mid + 1;
			ans = max(ans, mid);
		} else {
			r = mid - 1;
		}
	}
	cout << ans;
	return 0;
}
