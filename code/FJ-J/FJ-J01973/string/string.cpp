#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
ull n, a;
char ch;
string s;
int main () {
	//freopen("string.in", "r", stdin);
	//freopen("string.out", "w", stdout);
	cin >> n;
	for (ull i = 1;i <= n;i++) {
		cin >> a >> ch;
		for (int j = 0;j < a;j++) s += ch;
	}
	if (n == 1) {
		cout << 0;
		return 0;
	}
	ull ans = 0, len = s.length();
	if (len % 2 == 0) {
		for (ull l = 0, r = len - 1;l <= floor((l + r) / 2.0), r >= ceil((l + r) / 2.0);l++, r--) {
			if (s[l] != s[r]) ans++;
		}
	} else {
		for (ull l = 0, r = len - 1;l <= (l + r) / 2, r >= (l + r) / 2;l++, r--) {
			if (s[l] != s[r]) ans++;
		}
	}
	cout << ans;
	return 0;
}
