#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
const int N = 2e5 + 10;
int n, m, a[N];
signed main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin.tie(nullptr) -> ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) 
		cin >> a[i];
	sort(a + 1, a + 1 + n);
	int ans = 0, st = 1;
	for (int j = 30; ~j; j--) {
		ans += (1 << j); 
		int cnt = 0, nst = 0;
		for (int i = st; i <= n; i++)
			if (a[i] & (1 << j)) {
				if (!nst) nst = i;
				cnt++;
			}
		if (cnt < m) {
			ans -= (1 << j);
			continue;
		}
		st = nst;
	} 
	cout << ans << endl;
	return 0;
}

