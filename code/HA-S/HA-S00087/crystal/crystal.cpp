#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair <int, int>;
const ll mod = 998244353;
const ll P = 1e9 + 7;
const int N = 5e5 + 5;
ll a[N], sum[N], m;
int n;

bool check (int x) {
	for (int r = x; r <= n; r ++)
		if (x * a[r] <= m + sum[r] - sum[r - x])
			return true;
	return false;
}

int main () {
	ios :: sync_with_stdio (false);
	cin.tie (nullptr);
	cout.tie (nullptr);

	freopen ("crystal.in", "r", stdin);
	freopen ("crystal.out", "w", stdout);

	cin >> n >> m;
	for (int i = 1; i <= n; i ++)
		cin >> a[i];
		
	sort (a + 1, a + n + 1);
	
	for (int i = 1; i <= n; i ++)
		sum[i] = sum[i - 1] + a[i];
	int l = 1, r = n;
	while (l < r) {
		int mid = (l + r + 1) >> 1;
		if (check (mid))
			l = mid;
		else
			r = mid - 1;
	}
	cout << l << "\n";
	return 0;
}

