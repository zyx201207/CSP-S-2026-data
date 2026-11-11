#include <bits/stdc++.h>
namespace GD00492 {
using namespace std;
typedef long long ll;
#define fi first
#define se second
const int maxn(5e5 + 9);
int n, ans;
ll m, a[maxn], su[maxn];
void init() {}
void mian() {
	init();
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; ++i)
		su[i] = su[i - 1] + a[i];
	ans = 1;
	for (int i = 1, j = 1; i <= n; ++i) {
		while (a[i] * (i - j + 1) - (su[i] - su[j - 1]) > m) ++j;
		ans = max(ans, i - j + 1);
	}
	cout << ans << '\n';
}
} using namespace GD00492;
int main() {
	freopen("crystal.in", "r", stdin),
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false),
	cin.tie(nullptr), cout.tie(nullptr);
	int T = 1;
//	cin >> T;
	while (T--) mian();
	return 0;
}

