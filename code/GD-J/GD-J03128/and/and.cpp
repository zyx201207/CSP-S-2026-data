#include <bits/stdc++.h>
using namespace std;
int n, m;
long long a[200005], s[200005];
int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i ++) cin >> a[i];
	for(int i = 1; i <= n; i ++) {
		s[i] = s[i - 1] & a[i];
	}
	if(m == 1) {
		sort(a + 1, a + 1 + n, greater<long long>());
		cout << a[1];
	}
	else if(m == n - 1) {
		long long max_ = 0;
		for(int i = 1; i <= n; i ++) {
			max_ = max(max_, s[n] & a[i]);
		}
		cout << max_;
	}
	else if(m == 2) {
		sort(a + 1, a + 1 + n, greater<long long>());
		long long t = a[1] & a[2];
		cout << t;
	}else{
		sort(a + 1, a + 1 + n, greater<long long>());
		long long sum = a[1];
		for(int i = 1; i <= m; i ++) sum &= a[i];
		cout << sum;
	}
	return 0;
}
