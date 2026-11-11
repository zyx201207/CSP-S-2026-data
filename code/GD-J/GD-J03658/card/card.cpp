#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 5e5 + 5e4;
int n, m, a[N], l[N], ans[N];

signed main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = n; i >= 1; i--) if (l[a[i]] == 0) l[a[i]] = i;
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			j = l[a[j]];
			ans[a[j]]++;
		}
	}
	for (int i = 1; i <= m; i++) cout << ans[i] << " ";
	return 0;
}
/*
4 3
1 2 1 3

10 3
3 1 2 1 3 2 3 1 2 1 
*/
