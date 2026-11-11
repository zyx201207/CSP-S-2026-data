#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios::sync_with_stdio(false); cin.tie(0)
#define FILE(x) freopen(x ".in", "r", stdin); freopen(x ".out", "w", stdout)
const int N = 5e5 + 10;
int n;
ll m, a[N];
bool check(int x) {
	ll res = 0;
	for (int i = 1; i < x; i++) {
		res += a[x] - a[i];
	}
	res += a[x - 1];
	res -= (a[x] - a[x - 1]) * (x - 1);
	for (int i = x; i <= n; i++) {
		res -= a[i - 1] - a[i - x];
		res += (a[i] - a[i - 1]) * (x - 1);
		if (res <= m) {
			return true;
		}
	}
	return false;
}
int main() {
	IOS; 
	FILE("crystal");
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	int l = 1, r = n;
	while (l < r) {
		int mid = (l + r + 1) >> 1;
		if (check(mid)) {
			l = mid;
		} else {
			r = mid - 1;
		}
	}
	cout << l << "\n";
	return 0;
}

