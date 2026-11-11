#include<bits/stdc++.h>
using namespace std;
const long long N = 2 * 1e6 + 5;
long long n, d;
long long a[N];
long long x[N];
bool bo[N];
void solve() {
	cin >> n >> d;
	for (long long i = 1; i <= n; i++) {
		cin >> a[i];
	}
	long long ans = 0;
	for (long long i = 1; i < n; i++) {
		memset(x, 0, sizeof(x));
		memset(bo, false, sizeof(bo));
		x[i] = 1;
		priority_queue<long long> q;
		q.push(i);
		while (!q.empty()) {
			auto tem = q;
			while (!q.empty()) q.pop();
			while (!tem.empty()) {
				long long t = tem.top();
				tem.pop();
				for (long long k = t + 1; k <= n && a[k] - a[t] <= d; k++) {
					if (x[k] == 0) q.push(k);
					x[k] += x[t];
				}
				x[t] = 0;
//				cout << "\n";
			}
			for (long long k = i; k <= n; k++) {
//				cout << x[k] << " ";
				if (x[k] == 2 && bo[k] == false) ans++;//, cout << i << " " << k << "\n";
				if (x[k] >= 1) bo[k] = true; 
			}
//			cout << "\n";
		}
//		cout << "\n";
	}
	cout << ans << "\n";
}
int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	long long c, t;
	cin >> c >> t;
	while (t--) {
		solve();
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/
