#include <bits/stdc++.h>
using namespace std;

bool cmp(int a, int b) {
	return a > b;
}

int main() {
	freopen(".in", "r", stdin);
	freopen(".out", "w", stdout);
	int n, m;
	cin >> n >> m;
	vector <int> a(n);
	for (int i = 0;i < n;i++) cin >> a[i];
	sort (a.begin(), a.end(), cmp);
	if (m == n) {
		cout << a[n - 1];
		return 0;
	}
	int ans = 0;
	for (int i = 0;i < n;i++) {
		if (a[i] != a[i + 1]) ans++;
		if (ans == m) {
			cout << a[i]; break;
		}
	}
	return 0;
}
