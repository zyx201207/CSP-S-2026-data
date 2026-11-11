#include <bits/stdc++.h>
using namespace std;
string int_bin(int x) {
	string a = "";
	while (x) {
		a = char(x % 2 + '0') + a;
		x /= 2;
	} return a;
}
int n, m, a[200010]; string s[200010];
bool pan(string a, int len) {
	int len1 = len;
	for (int i = 1; i <= n; i++) {
		for (int i = 1; i <= len; i++) {
			if (s[i][len] == a[len]) a[i]++, len1--;
		}
	}
	if (len1 > 0) return 0;
	else return 1;
}
int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		int x; cin >> x; s[i] = int_bin(x);
	}
	int minl = 10000000;
	for (int i = 1; i <= n; i++) {
		minl = min(minl, s[i].length());
	}
	cout << 0;
	return 0;
}
