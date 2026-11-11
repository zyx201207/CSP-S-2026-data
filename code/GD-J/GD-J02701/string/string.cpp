#include <bits/stdc++.h>
using namespace std;
int n, ans;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	string s;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int a;
		char c;
		cin >> a >> c;
		while (a--) s += c;
	}
	for (int i = 0; i + i <= s.size(); ++i){
		if (s[i] != s[s.size() - 1 - i]) {
			++ans;
			s[s.size() - 1 - i] = s[i];
		}
	}
	cout << ans;
	return 0;
} 
