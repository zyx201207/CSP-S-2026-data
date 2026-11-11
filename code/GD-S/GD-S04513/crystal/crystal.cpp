#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;

int a[N];
long long sm[N];
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	long long m;
	cin >> n >> m;
	bool key1 = 1, key2 = 1;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] != i) key1 = 0;
		if (i >= 3 && a[i] - a[i - 1] != a[i - 1] - a[i - 2]) key2 = 0;
		sm[i] = sm[i - 1] + a[i];
	}
	sort(a + 1, a + n + 1);
	if (key1 || key2) {
		sort(sm + 1, sm + n + 1);
		cout << upper_bound(sm + 1, sm + n + 1, m) - sm << '\n';
		return 0;
	}
	long long ans = 0;
	for (int i = 1; i <= n; i++) {
		long long sum = 0;
		for (int j = i + 1; j <= n; j++) {
			if (sum == m) {
				ans = max(ans, 1LL * j - i);
				break;
			}
			if (sum < m) {
				sum += (a[j] - a[j - 1]) * (j - i);
			}
			else {
				ans = max(ans, 1LL * j - i - 1);
			}
		}
	}
	cout << ans;
	
	return 0;
}
