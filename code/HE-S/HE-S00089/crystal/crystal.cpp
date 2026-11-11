#include <bits/stdc++.h> 
using namespace std;

long long n, m;

int main () {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> m;
	long long a[n + 1];
	long long ans[n + 1];
	
	for (long long i = 1; i <= n; i++) {
		cin >> a[i];
	}
	
	for (long long i = 1; i <= n; i++) {
		if (i == 1 || i == 2) ans[i] = 1;
		else ans[i] = ans[i - 1] + pow(2, (i - 2)) - 1;
	}
	
	
	for (int i = 1; i <= n; i++) {
		cout << ans[i] << " ";
	}
	cout << endl;
	
	if (m >= ans[n]) cout << n;
	else {
		long long ans1 = n;
		for (long long i = ans[n] - 1; i >= 1; i--) {
			for (long long j = 1; j <= n; j++) {
				if (i == ans[j] - 1) ans1--;
				if (m == i) break;
			}
		}
		cout << ans1 - 1;
	}
	
	return 0;
}
