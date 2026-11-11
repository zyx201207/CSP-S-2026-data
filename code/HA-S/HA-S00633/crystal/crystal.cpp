#include <bits/stdc++.h>
using namespace std;
long long n,m,res;
long long a[500010];
long long ton[1000010];
long long func(long long n) {
	long long ans = 0;
	for (long long i = 1; n >= 0; i++) {
		n -= i;
		ans++;
	}
	return ans;
}
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for (long long i = 1; i <= n; i++) {
		cin >> a[i];
	}
	bool flag = true;
	for (long long i = 1; i <= n; i++) {
		if (i != a[i]) {
			flag = false;
			break;
		}
	}
	if (flag) {
		cout << func(m);
		return 0;
	}
	while (m--) {
		sort(a+1,a+n+1);
		a[1]++;
	}
	for (long long i = 1; i <= n; i++) {
		if (a[i] <= 1e6) ton[a[i]]++;
	}
	for (long long i = 1; i <= 1e6; i++) {
		res = max(res,ton[i]);
	}
	cout << res;
	return 0;
}

