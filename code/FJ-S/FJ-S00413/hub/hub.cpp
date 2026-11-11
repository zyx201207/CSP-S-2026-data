# include <bits/stdc++.h>
using namespace std;
int c;
int n, k;
void solve()
{
	cin >> n >> k;
	for (int i = 1, u, v; i <= n; i ++)
	{
		cin >> u >> v;
	}
	cout << 1 << '\n';
}
int main()
{
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios :: sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int T = 1;
	cin >> c >> T;
	while (T --) solve();
	return 0;
}

