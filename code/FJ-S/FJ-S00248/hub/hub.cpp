#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
inline void solve(int c)
{
	int n, k; cin >> n >> k;
	for (int i = 1, u, v; i < n; i++) cin >> u >> v;
	if (n == k) cout << "0\n"; else cout << "1\n";
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	int c, t; cin >> c >> t;
	while (t--) solve(c);
	return 0;
}
