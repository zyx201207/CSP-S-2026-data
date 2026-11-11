#include <bits/stdc++.h>
using namespace std;
int n, a;
long long ans;
char c;
string s;
int main () {
	 freopen ("string.in", "r", stdin);
	 freopen ("string.out", "w", stdout);
	ios::sync_with_stdio (false);
	cin.tie (0);cout.tie (0);
	cin >> n;
	for (int i = 1; i <= n; i ++) {
		cin >> a >> c;
		for (int j = 1; j <= a; j ++) s += c;
	}
	long long siz = s.size (), x;
	for (long long i = 0; i < s.size () / 2; i ++) {
		x = siz - i - 1;
		if (s[i] == s[x]) continue;
		else ans ++;
	}
	cout << ans;
	return 0;
}
