#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
long long n, m, ans;
long long a[N], cha[N];
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) { 
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	cha[1] = a[1];
	for (int i = 2; i <= n; i++) {
		cha[i] = a[i] - a[i - 1];
	}
	ans = 1;
	long long l = n, r = n, cnt = 0;
	while(l <= r) {
		long long it = 1;
		for (int i = l - 1; i >= 1; i--) {
			cnt += (a[r] - a[i]);
			if(cnt > m) {
				it = i + 1;
				cnt -= (a[r] - a[i]);
				break;
			} 
		}
		l = it;
		ans = max(ans, r - l + 1);
		cnt -= (a[r] - a[r - 1]) * (r - l);
		r--;
	}
	cout << ans;
	return 0;
}
