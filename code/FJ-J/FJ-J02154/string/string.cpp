#include<bits/stdc++.h>
#define int long long
using namespace std;
int n, l, ans;
string s;
signed main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a;
		char c;
		cin >> a >> c;
		l += a;
		for(int j = 0; j < a; j++) s += c;
	}
	for (int i = 0; i < n; i++)
		if (s[i] != s[l - 1 - i]) ans++;
	cout << ans;
	return 0;
}
