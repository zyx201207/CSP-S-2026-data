#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN = 2e5 + 7;
struct node {
	int a;
	char c;
} w[MAXN];
int n, l, r, ans;
signed main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> w[i].a >> w[i].c;
	l = 1, r = n;
	while (l <= r) {
		if (l == r) break;
		int tot = min(w[l].a, w[r].a);
		if (w[l].c != w[r].c) ans += tot;
		w[l].a -= tot;
		w[r].a -= tot;
		if (w[l].a <= 0) l++;
		if (w[r].a <= 0) r--;
	}
	cout << ans << "\n";
	return 0;
}
