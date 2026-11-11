#include <bits/stdc++.h>
using namespace std;
const int N = 200001;
int n, a[N];
char c[N];
long long ans = 0;
int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i] >> c[i];
	int l = 1, r = n;
	while (l < r) {
		int minn = min(a[l], a[r]);
		if (c[l] != c[r]) ans += minn;
		a[l] -= minn, a[r] -= minn;
		if (a[l] == 0) l++;
		if (a[r] == 0) r--;
	}
	cout << ans;
	return 0;
}
