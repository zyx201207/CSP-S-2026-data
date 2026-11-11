#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen(".in", "r", stdin);
	freopen(".out", "w", stdout);
	int n;
	cin >> n;
	string c;
	long long sum = 0;
	vector <int> a(n);
	for (int i = 0;i < n;i++) {
		cin >> a[i] >> c[i];
		sum += a[i];
	}
	int l = 0, r = n - 1;
	long long ans = 0;
	while (l <= r) {
		if (c[l] != c[r]) ans += min(a[l], a[r]);
		if (a[l] < a[r]) {
			a[r] -= a[l]; l++;
		} else if (a[l] > a[r]) {
			a[l] -= a[r]; r--;
		} else {
			l++; r--;
		}  
	}
	cout << ans << endl;
	return 0; 
}
