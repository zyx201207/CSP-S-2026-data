#include <bits/stdc++.h>
using namespace std;
long long a[500005], sum, maxn = -1e13;
int n;
unsigned long long m;
bool check(int x) {
	int s = 0, i;
	for (i = x; i >= 1; i--) {
		s += a[x] - a[i];
		if (s > m) {
			break;
		}
	}
	if (x - i >= maxn) {
		maxn = x - i;
		return true;
	}
	if (x - i < maxn) {
		return false;
	}
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios_base::sync_with_stdio();
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		sum += a[i];
	}
	sort (a, a + n + 1);
	long long l = 1, r = n;
	while (l <= r) {
		long long mid = l + (r - l + 1) / 2;
		if (check(mid)) {
			l = mid + 1;
		}
		else r = mid - 1;
	}
	cout << maxn;
	return 0;
} 
