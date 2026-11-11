#include <bits/stdc++.h>
using namespace std;
long long n, a[200005], pre[200005], ans;
string s;
char c[200005];
int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> c[i];
		for (int j = 1; j <= a[i]; j++)
			s += c[i];
	}	
	long long len = s.size();
	s = " " + s;
	for (long long i = 1; i <= len / 2; i++) {
		if (s[i] != s[len - i + 1])
			ans++;
	}
	cout << ans;
	return 0;
}