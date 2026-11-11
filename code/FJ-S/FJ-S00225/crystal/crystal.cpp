#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 5e5 + 5;

int n;
ll m;
ll a[N];
ll sum[N];

bool check(int x) {
	for (int i = 1; i <= n - x + 1; ++i) {
		int r = i + x - 1;
		ll q = sum[r] - sum[i - 1];
		if ((q + m) / x >= a[r]) return true;
	}
	return false;
} 

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; ++i) {
		sum[i] = sum[i - 1] + a[i];
	}
	int l = 1, r = n;
	while (l < r) {
		int mid = (l + r + 1) / 2;
		if (check(mid)) {
			l = mid;
		} else {
			r = mid - 1;
		}
	}
	cout << l << '\n';
	return 0;
} 
