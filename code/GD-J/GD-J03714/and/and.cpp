#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 2e5 + 5;
int n, m, a[N], ans, cnt[32];

inline bool cmp(int A, int B) {
	return A > B;
}

inline int calc() {
	int sum = 0;
	for(int j = 0; j < 30; ++j)
	if(cnt[j] >= m) sum += (1 << j);
	return sum;
}

signed main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	
	ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	sort(a + 1, a + n + 1, cmp);
	if(m == 1) {
		cout << a[1];
		return 0;
	}
	if(m == n) {
		ans = a[1];
		for(int i = 2; i <= n; ++i)
			ans &= a[i];
		cout << ans;
		return 0;
	}
	if(m == 2 && n <= 5000) {
		for(int i = 1; i <= n; ++i)
		for(int j = i + 1; j <= n; ++j)
			ans = max(ans, a[i] & a[j]);
		cout << ans;
		return 0;
	}
	if(m == n - 1) {
		for(int i = 1; i <= m; ++i)
		for(int j = 0; j < 30; ++j)
			cnt[j] += ((a[i] >> j)&1);
		int tmp[32];
		for(int i = 1; i <= n; ++i) {
			for(int j = 0; j < 30; ++j)
				tmp[j] = cnt[j];
			for(int j = 0; j < 30; ++j)
				cnt[j] -= ((a[i] >> j)&1);
			ans = max(ans, calc());
			for(int j = 0; j < 30; ++j)
				cnt[j] = tmp[j];
		}
		cout << ans;
		return 0;
	}
	for(int i = 1; i <= m; ++i)
	for(int j = 0; j < 30; ++j)
		cnt[j] += ((a[i] >> j)&1);
	ans = calc();
	for(int i = m + 1; i <= n; ++i) {
		for(int j = 0; j < 30; ++j) {
			cnt[j] -= ((a[i - m] >> j)&1);
			cnt[j] += ((a[i] >> j)&1);
		}
		ans = max(ans, calc());
	}
	cout << ans;
	return 0;
}
/*
5 3
31 3 1 15 7

65 pts
*/
