#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	
	long long mx = -2147483648LL;
	int n, m;
	cin >> n >> m;
	bool mdengyu1 = false;
	vector<long long> a(n);
	if (m == 1) {
		mdengyu1 = true;
	}
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (mdengyu1) {
			if (mx < a[i]) mx = a[i];
		}
	}
	if (mdengyu1) {
		cout << mx << endl;
		return 0;
	}
	
	if (m == 2) {
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				if ((a[i] & a[j]) > mx) {
					mx = (a[i] & a[j]);
				}
			}
		}
		cout << mx << endl;
	}
	else {
		long long sum = 0LL;
		sum = a[0];
		for (int i = 1; i < n; i++) {
			sum &= a[i];
		}
		cout << sum << endl;
	}
	return 0;
}
