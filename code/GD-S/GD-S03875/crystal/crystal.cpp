#include <bits/stdc++.h>
using namespace std;

long long a[500003];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin.tie(nullptr)->sync_with_stdio(false);
	int n; long long m;
	cin >> n >> m;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	sort(a+1, a+n+1);
	int ans = 1;
	long long tot = 0, sum = 0;
	for(int L = 1, R = 1; R < n; ++R) {
		tot += (a[R+1]-a[R])*(R-L+1);
		sum += a[R+1]-a[R];
		for(; tot > m; ++L) {
			tot -= sum;
			sum -= a[L+1]-a[L];
		}
		ans = max(ans, R-L+2);
	}
	cout << ans << endl;
	return 0;
}