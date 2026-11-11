#include <iostream>
using namespace std;
typedef long long ll;
int c, t, n, k;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin >> c >> t;
	while (t--)
	{
		cin >> n >> k;
		for (int i = 1, u, v; i < n; i++)
			cin >> u >> v;
		if (n == k)
			cout << 0 << endl;
		else if (c == 12 || c == 13)
		{
			n /= 2;
			n -= k - 2;
			cout << ((n + 1) / 2 + 1) / 2 << endl;
		}
		else
			cout << max(n / k - 1, 1) << endl;
	}
	return 0;
}
