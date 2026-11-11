#include <bits/stdc++.h>
using namespace std;
int n, ans = 0;
string s = "";
bool check(string s) {
	for (int i = 0, j = s.size() - 1; i < s.size(), j >= 0; i ++, j --) {
		if (s[i] != s[j]) {
			return 0;
		} 
	} 
	return 1;
}
int main () {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	while (n--) {
		int x; char y;
		cin >> x >> y;
		for (int i = 0; i < x; i ++) {
			s += y;
		}
	} if (check(s)) {
		cout << '0';
		return 0;
	} else {
		for (int i = 0, j = s.size() - 1; i < s.size() / 2, j > s.size() / 2; i ++, j --) {
			if (s[i] != s[j]) {
				ans ++;
			} 
	    } cout << ans;
	} return 0;
}
