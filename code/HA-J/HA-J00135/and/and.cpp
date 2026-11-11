#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair <int, int>;
const ll mod = 998244353;
const ll P = 1e9 + 7;
const int N = 2e5 + 5;
int n, m, a[N];

bool check (int x) {
	int cnt = 0;
	for (int i = 1; i <= n; i ++)
		if ((a[i] & x) == x)
			cnt ++;
	return cnt >= m;
}

int main () {
	ios :: sync_with_stdio (false);
	cin.tie (nullptr);
	cout.tie (nullptr);

	freopen ("and.in", "r", stdin);
	freopen ("and.out", "w", stdout);

	cin >> n >> m;
	for (int i = 1; i <= n; i ++)
		cin >> a[i];
	
	int ans = 0;
	for (int i = 30; i >= 0; i --)
		if (check (ans + (1 << i)))
			ans += (1 << i);
	cout << ans << "\n";
	return 0;
}
