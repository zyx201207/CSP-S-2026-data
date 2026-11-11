#include<bits/stdc++.h>
using namespace std;
const int N = 500010;
long long c[N], diff[N], pre[N];
int n, m;
bool check(int mid) {
	long long sum = 0;
	for (int i = 1; i < mid; i++) {
		sum += pre[mid] - pre[i];
	}
	if (sum <= m) {
		return true;
	}
	for (int start = 2; start + mid <= n; start++) {
		sum -= pre[start + mid - 2] - pre[start - 1];
		sum += (mid - 1) * diff[start + mid - 1];
		if (sum <= m) {
			return true;
		}
	}
	return false;
}
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
	}
	sort(c + 1, c + n + 1);
	for (int i = 2; i <= n; i++) {
		diff[i] = c[i] - c[i - 1];
	}
	pre[1] = 0;
	for (int i = 2; i <= n; i++) {
		pre[i] = diff[i] + pre[i - 1];
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
	if (l == 1) {
		cout << 0 << endl;
		return 0;
	}
	cout << l << endl;
	return 0;
}

