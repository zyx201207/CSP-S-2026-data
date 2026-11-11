#include <bits/stdc++.h>
using namespace std;

#define int long long
#define N 500010

int n, m, a[N];
signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> m;
	for(int i = 1;i <= n;i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	
	int l = 1, r = 0, num = 0;
	int mx = -1;
	while(l <= n) {
		while(r < l || (r + 1 <= n && num + (a[r + 1] - a[r]) * (r - l + 1) <= m)) {
			num += (a[r + 1] - a[r]) * (r - l + 1);
			r++;
		}
		mx = max(mx, r - l + 1);
		num -= (a[r] - a[l]);
		l++;
	}
	cout << mx << "\n";
	return 0;
} 
