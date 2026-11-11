#include <bits/stdc++.h>
// #define int long long
using namespace std;
int n, m;
signed main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
	cin >> n >> m;
	vector<int> a(n + 1), ans(m + 1), lst(m + 1);
	bool flagA = true;
	for(int i = 1; i <= n; ++ i) {
		cin >> a[i];
		lst[a[i]] = i;
		if(a[i] < a[i - 1]) flagA = false;
	}
	
	if(m == 1) {
		cout << n << '\n';
		return 0;
	}
	if(m == 2) {
		int cnt = 0;
		for(int i = 1; i <= n; ++ i)
			cnt += (a[i] != a[n]);
		if(a[n] == 1) {
			cout << n << ' ' << cnt << '\n';
		}
		else {
			cout << cnt << ' ' << n << '\n';
		}
		return 0;
	}
	
	/* te shu xing zhi A */
	if(flagA) {
		for(int i = n; i >= 1; -- i)
			ans[a[i]] = max(ans[a[i]], i);
		for(int i = 1; i <= m; ++ i)
			cout << ans[i] << " \n"[i == m];
		return 0;
	}
	
	/* subtask1 */
	vector<bool> st(m + 1);
	for(int i = 1; i <= n; ++ i) {
		for(int j = i; j <= n; ++ j) {
			st[a[j]] = true;
			if(lst[a[j]]) j = lst[a[j]];
		}
		for(int j = 1; j <= m; ++ j) {
			ans[j] += st[j];
			st[j] = false;
		}
	}
	for(int i = 1; i <= m; ++ i)
		cout << ans[i] << " \n"[i == m];
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
