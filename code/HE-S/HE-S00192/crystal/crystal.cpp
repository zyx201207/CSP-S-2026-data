#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 5;
int n, m;
int a[N];
int sum, ans;
signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		sum += a[i];
	}
	sum += m;
	sum /= n;
	for (int i = 1; i <= n; i++) {
		if (a[i] <= sum) {
			ans++;
		}
	}
	cout << ans;
	return 0;
}
