#include <bits/stdc++.h>
using namespace std;
int a[200005], n, L, cnt;
char c[200005];
string s = "";
bool check(string s) {
	string s1 = s;
	reverse(s.begin(), s.end());
	if (s == s1) {
		return 1;
	} else {
		return 0;
	}
}
int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> c[i];
		for (int j = 1; j <= a[i]; j++) {
			s.push_back(c[i]);
			L++;
		}
	}
	if (check(s)) {
		cout << "0";
		return 0;
	} else {
		string s1 = s;
		reverse(s.begin(), s.end());
		for (int i = 0; i < s.size(); i++) {
			if (s[i] != s1[i]) {
				cnt++;
			}
		}
	}
	cout << cnt / 2;
	return 0;
}
