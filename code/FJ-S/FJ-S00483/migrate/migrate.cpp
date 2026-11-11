#include<bits/stdc++.h>
using namespace std;
vector<long long> a, b;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int c, t;
	cin >> c >> t;
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	for (int i = 0; i < t; i++) {
		long long n, d, num = 0;
		cin >> n >> d;
		for (long long j = 0; j < n; j++) {
			long long x;
			cin >> x;
			a.push_back(x);
			if (j) b.push_back(x - a[j - 1]);
		}
		for (long long j = 0; j < n; j++) {
			if (b[j] > d || j == n - 1) {
				num += j % 2 == 1 ? (j + 1) / d / d : ((j + 1) / d / d) * 2;
			}
		}
		cout << num << '\n';
	}
	return 0;
}
