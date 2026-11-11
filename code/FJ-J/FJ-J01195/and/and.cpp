#include <bits/stdc++.h>
using namespace std;
const int N = 200010;
long long n, a[N], m, vis[N], ans;
int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i ++)
		cin >> a[i], vis[i] = 1;
	for (int i = 30; ~i; i --) {
		long long res = 0;
		for (int j = 1; j <= n; j ++)
			if (a[j] >> i & 1)
				res += vis[j];
		if (res >= m) {
			ans |= 1 << i;
			for (int j = 1; j <= n; j ++)
				if (!(a[j] >> i & 1))
					vis[j] = 0;
		}
	}
	cout << ans;
	return 0;
}

