#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 5 * 114514;
int n, m, x, a[N], s[N], c[N];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	cin >> n >> m;
	
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	
	sort(a + 1, a + n + 1);
	
	for (int i = 1; i <= n; i++)
		s[i] = s[i - 1] + a[i];
	
	for (int i = 2; i <= n; i++) {
		c[i] = a[i] * (i - 1) - s[i - 1];
		if (c[i] > m) {
			cout << i - 1 << "\n";
			return 0;
		}
	}
	
	cout << n << "\n";
	
	return 0; 
}

//Password: Oct31==Dec25?
