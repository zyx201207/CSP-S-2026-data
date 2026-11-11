#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n, m, tot, ans, a[N], b[N];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i ++) {
		cin >> a[i];
	}
	for(int j = 29; ~j; j --) {
		tot = 0;
		for(int i = 1; i <= n; i ++) {
			if((a[i] >> j) & 1) b[++tot] = a[i];
		}
		if(tot >= m) {
			ans ^= (1 << j);
			for(int i = 1; i <= tot; i ++) a[i] = b[i];
			n = tot;
		}
	}
	cout << ans << '\n';
	return 0;
}
