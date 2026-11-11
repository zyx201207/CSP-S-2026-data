#include <bits/stdc++.h>
using namespace std;
#define ll  long long
string fan(string s) {
	string ss = "";
	for (int i = s.size() - 1; i >= 0; i--) {
		ss += s[i];
	}
	return ss;
}
string ttt(int x) {
	string s = "";
	while (x > 0) {
		s += ((x % 2) + '0');
		x /= 2;
	}
	return fan(s);
}
int ttte(string s) {
	int ans = 0;
	s = fan(s);
	for (int i = 0; i < s.size(); i++) {
		ans += (s[i] - '0') * pow(2, i);
	}
	return ans;
}
string andx(string a, string b) {
	int as = a.size(), bs = b.size();
	int ss = max(as, bs);
	string ans = "";
	if (as < ss) {
		a = fan(a);
		while (as != ss) {
			a += '0';
			as++;
		}
		a = fan(a);
	}
	else if (bs < ss) {
		b = fan(b);
		while (bs != ss) {
			b += '0';
			bs++;
		}
		b = fan(b);
	}
	for (int i = 0; i < ss; i++) {
		if (b[i] == a[i] && a[i] == '1') ans += '1';
		else ans += '0';
	}
	return ans;
}
int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;
	int a[n];
	string s[n];
	int maxn = -114514;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		maxn = max(maxn, a[i]);
		s[i] = ttt(a[i]);
	}
	
	string sss = s[0];
	if (m == n) {
		for (int i = 1; i < n; i++) {
			sss = andx(sss, s[i]);
		}
		cout << ttte(sss);
	} else if (m == 1) {
		cout << maxn;
	} else if (m == 2) {
		maxn = -114514;
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				string ss = andx(s[j], s[i]);
				maxn = max(maxn, ttte(ss));
			}
		}
		cout << maxn;
	} else {
		cout << maxn;
	}
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
