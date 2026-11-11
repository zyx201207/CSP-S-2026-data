#include <bits/stdc++.h>
using namespace std;
long long a[100005];

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n = 0, m = 0;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	int ans = a[m];
	for (int i = n - 1; i >= n - m + 1; i--) {
		ans &= a[i];
	}
	cout << ans;
	return 0;
}

