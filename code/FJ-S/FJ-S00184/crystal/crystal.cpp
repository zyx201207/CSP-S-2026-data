#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 10;
int n, m, ans = 0;
int a[N], b[N];
signed main() {
//	system("fc crystal4.ans crystal.out");
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	b[0] = 0;
	for (int i = 1, j = 0; i <= n; i++) {
		b[i] = a[i];
		b[i] += b[i - 1];
		while ((i - j) * a[i] - (b[i] - b[j]) > m) j++;
		ans = max(ans, i - j);
	}
	cout << ans;
}
