#include <bits/stdc++.h>
using namespace std;
int c, t, n, m;
int main()
{
	srand(time(0));
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while (t--)
	{
		cin >> n >> m;
		for (int i = 1, x; i <= n; i++) cin >> x;
		cout << rand() << '\n';
	}
	return 0;
}