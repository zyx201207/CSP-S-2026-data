// 100

#include <bits/stdc++.h>

using namespace std;

#define int long long

const int kM = 4e5 + 7;

int n, m, a[kM], ans = -1, lon[40], lm = -1;
string s[kM];

bool cmp1(string x, string y) {
	if (x.size() != y.size()) {
		return x.size() > y.size();
	}
	return x > y;
}

int to_in(string s) {
	int cnt = 0, ret = 0;
	int t = s.size() - 1;
	while (t >= 0) {
		if (s[t] == '1') {
			ret += (1 << cnt);
		}
		t--;
		cnt++;
	}
	return ret;
}

signed main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		int k = a[i];
		while (k > 0) {
			s[i] += to_string(k & 1);
			k >>= 1;
		} 
		reverse(s[i].begin(), s[i].end());
		lon[s[i].size()]++;
	}
	for (int i = 1; i <= 30; i++) {
		if (lon[i] >= 2) {
			lm = i;
		}
	}
	sort(s + 1, s + n + 1, cmp1);
	int f = 1;
	while (s[f].size() > lm) f++;
//	if (f == 1) {
//		
//	}
//	reverse(s + 1, s + n + 1);
//	for (int i = 1; i <= n; i++) {
//		cout << s[i] << "\n";
//	}
//	cout << "f = " << f << "\n";
	if (n - m - f + 1 >= 0) {
		for (int i = f; i < m + f; i++) {
			int x = to_in(s[i]);
			if (ans == -1) ans = x;
			else ans = ans & x;
		}
	} else {
		for (int i = 1; i <= m; i++) {
			int x = to_in(s[i]);
			if (ans == -1) ans = x;
			else ans = ans & x;
		}
	}
//	if (m > n - f + 1) {
//		for (int i = 1; i <= m; i++) {
//			int x = to_in(s[i]);
//			if (ans == -1) ans = x;
//			else ans = ans & x;
//		}
//	} else {
//		for (int i = f; i <= m + f; i++) {
//			int x = to_in(s[i]);
//			if (ans == -1) ans = x;
//			else ans = ans & x;
//		}
//	}
//	cout << to_in("11");
	cout << ans;
	return 0;
}

/*
4 2
3 15 12 12

5 3
1 2 3 4 5

3 2
2 2 4

*/
