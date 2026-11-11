#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 5e5 + 10;
long long n, m, ans, sum, a[MAX_N], d[MAX_N];
bool check(int l, int r, int mid) {
	sum = 0;
	ans = r - l + 1;
	for (int i = l; i <= r; i++) {
		if (i < mid) {
			sum += a[mid] - a[i];
		} else {
			sum += a[i] - a[mid];
		}
		if (sum > m) {
			return false;
		}
	}
	return true;
}
int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) {
		d[i] = d[i - 1] + a[i] - a[i - 1];
		if (i == 1) {
			d[i] = 0;
		}
	}
	int l = 1, r = n, mid;
	while (l < r) {
		mid = l + (r - l) / 2;
		if (check(l, r, mid)) {
			cout << ans;
			return 0;
		} else {
			if (d[mid] - d[l] > d[r] - d[mid]) {
				l++;
			} else if (d[mid] - d[l] <= d[r] - d[mid]) {
				r--;
			} else {
				if (a[l + 1] - a[l] >= a[r] - a[r - 1]) {
					l++;
				} else {
					r--;
				} 
			}
		}
	}
	cout << ans;
	return 0;
}
