#include <bits/stdc++.h>
using namespace std;
int n, m, a[200005], sum, maxx, t;
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	cin >> a[1];
	sum = a[1];
	maxx = a[1];
	for (int i = 2; i <= n; i++) {
		cin >> a[i];
		sum &= a[i];
		maxx = max (maxx, a[i]);
	}
	sort(a+1, a+n+1);
	if (m == n) {
		cout << sum;
		return 0;
	}
	if (m == 1) {
		cout << maxx;
		return 0;
	}
	t = a[n];
	for (int i = n-1; i > n-m; i--) t=t&a[i];
	cout << t;
	return 0;
}
