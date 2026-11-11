#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	int n; cin >> n;
	vector<i64> a(n); vector<char> c(n);
	i64 len = 0; 
	for (int i = 0; i < n; i++) {
		cin >> a[i] >> c[i], len += a[i];
	}
	int ti = 0, tj = 0;
	i64 pi = 0, pj = 0, now = 0, ans = 0;
	while (now < len / 2) {
		i64 ri = a[ti] - pi, rj = a[n - tj - 1] - pj;
		i64 step = min({ri, rj, len / 2 - now});
		ans += step * (c[ti] != c[n - tj - 1]);
		now += step, pi += step, pj += step;
		if (pi == a[ti]) ti++, pi = 0;
		if (pj == a[n - tj - 1]) tj++, pj = 0;
	}
	cout << ans;
	
	/*string s = "";
	for (int i = 0; i < n; i++) s += string(a[i], c[i]);
	
	int ans = 0;
	for (int i = 0; i < s.size() / 2; i++)
		ans += s[i] != s[s.size() - i - 1];
	cout << ans;*/
	return 0;
}

/*
3
2 a
2 b
1 c
*/

