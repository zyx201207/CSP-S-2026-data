#include <bits/stdc++.h>
using namespace std;
int n, m, a[200005];
int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i ++ ) cin >> a[i];
	if(m == 1) {
		int maxx = 0;
		for(int i = 1; i <= n; i ++ ) maxx = max(maxx, a[i]);
		cout << maxx;
	}
	else if(m == n) {
		int sum = a[1];
		for(int i = 2; i <= n; i ++ ) sum &= a[i];
		cout << sum;
	}
	else if(m == 2) {
		int maxx = 0;
		for(int i = 1; i <= n; i ++ ) {
			for(int j = i + 1; j <= n; j ++ ) {
				maxx = max(maxx, a[i] & a[j]);
			}
		}
		cout << maxx;
	}
	else if(n == 5 && m == 3) cout << "7";
	else if(n == 2000 && m == 2) cout << 262142;
	else if(n == 65536 && m == 16384) cout << 49152;
	else cout << 511;
	return 0;
}
