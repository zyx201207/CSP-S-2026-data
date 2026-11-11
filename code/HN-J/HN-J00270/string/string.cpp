#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	int n; cin >> n;
	long long le = 1, ri = 0, ans = 0;
	
	vector<int> a(n); vector<char> c(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i] >> c[i];
		ri += (long long)a[i];
	}
	
	int i = 0, j = n-1;
	while (i < j && le < ri) {
		if (a[i] > a[j]) {
			if (c[i] != c[j]) ans += a[j];
			a[i] -= a[j];
			le += a[j]; ri -= a[j];
			j--;
		} else if (a[i] < a[j]) {
			if (c[i] != c[j]) ans += a[i];
			a[j] -= a[i];
			le += a[i]; ri -= a[i];
			i++;
		} else {
			if (c[i] != c[j]) ans += a[i];
			le += a[i]; ri -= a[i];
			i++; j--;
		}
	}
	
	cout << ans;
	return 0;
} 
