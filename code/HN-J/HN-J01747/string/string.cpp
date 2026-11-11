#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int W = 2e5 + 5;
ll n, a[W], ans;
char c[W];
string s;
int main() {
	freopen ("string.in", "r", stdin);
	freopen ("string.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> c[i];
		if (a[i] == 1e9) continue;
		for (int j = 1; j <= a[i]; j++) s += c[i];
	}
	ll L = s.size();
	for (int i = 0; i < (L - 1) / 2; i++) {
		if (s[i] != s[L - 1 - i]) ans++;
	}
	cout << ans;
	return 0;
} 
