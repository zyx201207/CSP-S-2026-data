#include <bits/stdc++.h>
using namespace std;

int n;
int a[200001];
char c[200001];
string s;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		
		cin >> a[i] >> c[i];
	}
	for (int i = 1; i <= n; i++) {
		string ss;
		for (int j = 1; j <= a[i]; j++) {
			ss.push_back(c[i]);
		}
		s += ss;
	}
	int l = 0, r = s.size() - 1;
	int ans = 0;
	while(l + 1 != r && l != r) {
		if (s[l] == s[r]) {
			l++, r--;
		}
		if (s[l] != s[r]) {
			s[r] = s[l];
			ans++, l++, r--;
		}
	}
	cout << ans;
	return 0;
}
