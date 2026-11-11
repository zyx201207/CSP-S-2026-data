#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN = 5010;
int a[MAXN];
signed main() {
//	freopen(".in", "r", stdin);
	freopen("migrate7.in", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cout << "0 1\n";
	int n = 5000;
	cout << n << ' ' << rand() * rand() << '\n';
	for (int i = 1; i <= n; i++) a[i] = rand() * rand();
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) cout << a[i] << ' ';
	return 0;
}
