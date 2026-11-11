#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using LL = long long;
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n, m;
	cin >> n >> m;
	vector<int> a(n), suma(n);
	for (auto &x : a) cin >> x;
	int ans = 0;
	sort(a.begin(), a.end());
	suma[0] = a[0];
	for (int i = 1; i < n; i++) suma[i] = suma[i - 1] + a[i];
	bool flag = true;
	for (int len = n; len >= 2; len--) {
		for (int p = m; p >= m/* * 0.99999192808032*/; p--) {
			for (int i = 0; i <= n - len; i++) {
//				cout << i << " " << len << " " << p << " " << a[i + len - 1] << endl;
//				cout << suma[i + len - 1] - suma[i] + a[i] + p << endl;
				int cur = suma[i + len - 1] - suma[i] + a[i] + p;
				if (cur % len == 0 && cur / len >= a[i + len - 1]) {
					cout << len;
					return 0;
				} 
			} 
		} 
	} 
}
