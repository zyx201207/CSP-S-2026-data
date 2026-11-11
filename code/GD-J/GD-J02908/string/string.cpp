#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10;
long long a[N];
char c[N];

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) 
		cin >> a[i] >> c[i];
	int l = 1, r = n;
	long long ans = 0;
	while (l < r) {
		int t = min(a[l], a[r]);
		if (c[l] != c[r]) 
			ans += t; 
		a[l] -= t;
		a[r] -= t;
		if (a[l] == 0) l++;
		if (a[r] == 0) r--;
	} cout << ans << '\n';
	return 0;
}
