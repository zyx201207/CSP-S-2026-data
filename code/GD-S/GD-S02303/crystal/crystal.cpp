#include <bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i, a, b) for (int i = a; i <= b; i ++ )
#define per(i, a, b) for (int i = a; i >= b; i -- )
void _max(int &a, int b) {a = max(a, b); }
void _min(int &a, int b) {a = min(a, b); }

// crystal

const int N = 5e5 + 5;
int n, m, a[N];

void solve() {
	cin >> n >> m;
	rep(i, 1, n) cin >> a[i];
	sort(a + 1, a + n + 1);
	int ans = 1;
	for (int i = 2, j = 1, sum = 0; i <= n; i ++ ) {
		sum += (a[i] - a[i - 1]) * (i - j);
		while (j <= i && sum > m) sum -= a[i] - a[j], j ++ ;
		if (sum <= m) _max(ans, (i - j + 1));
	}
	cout << ans << '\n';
	return ;
}

/*
5 8
-3 -1 2 2 7
*/

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int T = 1;
//	cin >> T;
	while (T -- ) solve();
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}
// 15:13
