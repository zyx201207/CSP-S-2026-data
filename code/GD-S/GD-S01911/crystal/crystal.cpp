#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 5e5 + 5, inf = 1e12;
int n, a[maxn], m;
main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m; int ans = 1, pos = 1, sum = 0;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	for (int i = 2; i <= n; i++){
//		cout << sum << ' ' << pos << ' ' << ans << '\n';
		if (sum + (i - pos) * (a[i] - a[i - 1]) <= m) {
			sum += (i - pos) * (a[i] - a[i - 1]);
			ans = max(ans, i - pos + 1);
		}else {
			while(pos < i && sum + (i - pos) * (a[i] - a[i - 1]) > m)
				sum = max(0ll, sum - (a[i - 1] - a[pos])), ++pos;
			sum += (i - pos) * (a[i] - a[i - 1]);
		}
	}cout << ans;
}
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7
*/
