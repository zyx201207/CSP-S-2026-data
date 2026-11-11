#include <bits/stdc++.h>
using namespace std;
int main ( ) {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	string s = "";
	long long cnt = 0;
	cin >> n;
	int a;
	char c;
	for (int i = 0; i < n; i++) {
		cin >> a;
		cin >> c;
		for (int j = 1; j <= a; j++) {
			s += c;
		}
	}
	for (int i = 0, j = s.size() - 1; i <= j; i++, j--) {
		if (s[i] != s[j]) {
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}
