#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 5e5 + 5;
int n;
ll m, a[N];
bool check(int x) {
	ll tot = 0;
	for(int i = 1; i <= x; i++) 
		tot += a[x] - a[i];
	if(tot <= m) return 1;
	for(int i = 1; i <= n - x; i++) {
		tot -= a[i + x - 1] - a[i];
		tot += (x - 1) * (a[i + x] - a[i + x - 1]);
		if(tot <= m) return 1;
	}
	return 0;
}
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) 
		cin >> a[i];
	sort(a + 1, a + n + 1);
	int l = 1, r = n, ans = 0;
	while(l + 1 <= r) {
		int mid = (l + r) / 2;
		if(check(mid)) {
			ans = mid;
			l = mid + 1;
		} else r = mid;
	}
	cout << ans;
	return 0;
}