#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const int maxn = 5e5 + 5;

ll n, m, a[maxn], pre[maxn], ans = 1;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i ++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	ll l = 1, r = 1, cha = 0;
	while(r <= n) {
		while(cha > m) {
			cha -= (a[r] - a[l]);
			l ++;
		}
		ans = max(ans, r - l + 1);
		if(r == n)
			break;
		cha += (a[r + 1] - a[r]) * (r - l + 1);
		r ++;
	}
	cout << ans << '\n';
	return 0;
} 
