#include <bits/stdc++.h>
using namespace std;

long long JHabs(long long st) {
	if (st >= 0) return st;
	else return (0 - st);
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	long long n, m;
	cin >> n >> m;
	bool A = true, B = true;
	long long r;
	vector<long long> a(n);
	for (long long i = 0; i < n; i++) {
		cin >> a[i];
		if (i == 1) {
			r = JHabs(a[1] - a[0]);
		}
		if (i != 0) {
			if (JHabs(a[i] - a[i - 1]) != 1) {
				A = false;
			}
			if (JHabs(a[i] - a[i - 1]) != r) {
				B = false;
			}
		}
	}
	
	long long sum = 0LL;
	if (A) {
		while (m - sum >= 0) {
			sum++;
			m -= sum;
		}
		if (m == 0) {
			sum++;
		}
		cout << sum << endl;
	}
	else if (B) {
		while (m - sum * r >= 0) {
			sum++;
			m -= sum * r;
		}
		if (m == 0) {
			sum++;
		}
		cout << sum << endl;
	}
	return 0;
}
