#include <bits/stdc++.h>
#define int long long
//#define double long double
#define max(x, y) ((x) > (y) ? (x) : (y))
#define min(x, y) ((x) < (y) ? (x) : (y))
using namespace std;
int n, m;
int a[500010];
int s[500010];
int ans;
signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
	}
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; i++) {
		s[i] = s[i - 1] + a[i];
//		cout << a[i] << ' ' << s[i] << endl;
	}
	int l = 1;
	for(int r = 1; r <= n; r++) {
		while((s[r] - s[l - 1] - a[r] * (r - l + 1)) * (-1) > m) ++l;
		ans = max(ans, r - l + 1);
	}
	cout << ans << endl;
	return 0;
}
/*
5 8
-3 -1 2 2 7

*/
