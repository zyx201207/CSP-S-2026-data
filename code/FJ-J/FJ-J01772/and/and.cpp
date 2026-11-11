#include <bits/stdc++.h>
// #define int long long
using namespace std;
int n, m, cnt, ans;
signed main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
	cin >> n >> m;
	vector<int> a(n + 1);
	vector<bool> usd(n + 1, true);
	for(int i = 1; i <= n; ++ i) cin >> a[i];
	for(int i = 29; i >= 0; -- i) {
		cnt = 0;
		for(int j = 1; j <= n; ++ j) {
			if(usd[j])
				cnt += ((a[j] >> i) & 1);
		}
		if(cnt >= m) {
			ans += (1 << i);
			for(int j = 1; j <= n; ++ j)
				if((a[j] >> i) & 1 ^ 1)
				 usd[j] = false;
		}
//		cout << i << ':' << cnt << '\n';
	}
	cout << ans << '\n';
	fclose(stdin);
	fclose(stdout);
	return 0;
}
