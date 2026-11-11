#include <bits/stdc++.h>

using namespace std;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	
	int n;
	cin >> n;
	vector<int> a(n);
	vector<char> c(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i] >> c[i];
	}
	int i = 0, j = n - 1;
	long long ans = 0;
	while (i < j) {
		if (a[i] < a[j]) {
			ans += (c[i] != c[j]) * a[i];
			a[j] -= a[i++];
		} else {
			ans += (c[i] != c[j]) * a[j];
			a[i] -= a[j--];
		}
	}
	cout << ans << '\n';
	
//	cerr << clock() * 1000.0 / CLOCKS_PER_SEC << "ms\n";
	return 0;
}

/*

*/
