#include <bits/stdc++.h>
using namespace std;
string s;
int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		int x;
		char c;
		cin >> x >> c;
		while(x--) {
			s += c;
		}
	}
	int ans = 0;
	for (int i = 0; i * 2 < s.size(); ++i) {
		if (s[i] != s[s.size() - i - 1]) {
			++ans;
		}
	}
	cout << ans << endl;
}
