#include <bits/stdc++.h>
using namespace std;
long long n, sum, ans; string c;
int main() {
	freopen("string1.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int m; char x; cin >> m >> x; sum += m;
		for (int j = 1; j <= m; j++) c += x;
	}
	for (long long i = 0; i <= sum / 2; i++) {
		if (c[i] != c[sum - i]) ans++;
	} cout << ans;
	return 0;
}
