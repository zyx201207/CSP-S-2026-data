#include <bits/stdc++.h>
using namespace std;
int s(int n) {
	for (int i = 1; i <= n; i *= 2) {
		if (i == n) {
			return 1;
		}
	}
	return 0;
}
int a[1000010];
int main () {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	int sum = 0, sum2 = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (s(a[i] + 1) == 0) {
			sum = 1;
		}
		if (a[i] != i - 1 && i >= 1) {
			sum2 = 1;
		}
	}
	int mx = -1;
	if (sum == 0 || m == 1) {
		for (int i = 0; i < n; i++) {
			mx = max(mx, a[i]);
		}
		cout << mx << endl;
		return 0;
	}
	if (sum2 == 0 && s(n) == 1) {
		cout << 0;
		return 0;
	}
	sum = -1;
	sum2 = 0;
	if (m == n) {
		sum = a[0];
		for (int i = 1; i < n; i++) {
			sum = sum & a[i];
		}
	}else {
		for (int i = 0; i < n - 1; i++) {
			sum2 = a[i];
			for (int j = i + 1; j < n; j++) {
				sum2 = sum2 & a[j];
				sum = max(sum2, sum);
				sum = a[i];
			}
		}
	}
	cout << sum;
	return 0;
}
