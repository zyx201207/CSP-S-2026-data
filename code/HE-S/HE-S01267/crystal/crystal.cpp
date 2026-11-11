#include <bits/stdc++.h>
using namespace std;
long long a[100005];
long long xu[100000];
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	long long n;
	long long m;
	cin >> n >> m;
	long long q = m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);
	for (int i = 1; i < n; i++) {
		long long sum = 1;
		for (int j = i - 1; j >= 0; j--) {
			if (m >= a[i] - a[j]) {
				sum++;
				m = m - (a[i] - a[j]);
			}else {
				break;
			}
		}
		m = q;
		xu[i] = sum;
	}
	xu[0] = 1;
	long long ma = 0;
	for (int i = 0; i < n; i++) {
		ma = max(ma, xu[i]);
	}
	cout << ma;
	return 0;
}
