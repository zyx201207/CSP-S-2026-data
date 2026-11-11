#include <bits/stdc++.h>
#define ll unsigned long long
using namespace std;
bool ish(string s) {
	bool flag = 1;
	for (int i = 0, j = s.size() - 1; i < s.size(); i++, j--) {
		if (s[i] != s[j]) {
			flag = 0;
		}
	}
	return flag;
}
int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	ll a[n];
	char c[n];
	string s = "";
	for (int i = 0; i < n; i++) {
		cin >> a[i] >> c[i];
		if (a[i] > 1000000000) {
			cout << 0;
			return 0;
		}
		while (a[i]--) s += c[i];
	}
	int si = s.size();
	if (ish(s)) {
		cout << 0;
		return 0;
	}
	int ans = 100002;
	string ss = s;
	for (int i = 1; i <= n; i++) {
		int temp = 0;
		for (int j = si - 1; j >= 0; j--) {
			ss[j] = ss[si - j - 1];
			temp++;
			if (ish(ss)) break;
		}
		if (!ish(ss)) continue;
		else {
			ans = min(ans, temp);
		}
		ss = s;
	}
	cout << ans;
	return 0;
}
//I love luogu!
//I love luogu!
//I love luogu!
//I love kkksc24!
//I love kkksc24!
//I love kkksc24!
//I love chen_zhe!
//I love chen_zhe!
//I love chen_zhe!
//I love 一扶苏一!
//I love 一扶苏一!
//I love 一扶苏一!
