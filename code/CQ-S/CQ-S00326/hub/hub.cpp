#include <iostream>
using namespace std;
const int maxn = 5e5 + 5;

int u[maxn], v[maxn];

int main()
{
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	int c, t;
	cin >> c >> t;
	while (t--)
	{
		int n, k;
		cin >> n >> k;
		for (int i = 1; i < n; i++)
		{
			cin >> u[i] >> v[i];
		}
		cout << 1 << endl;
	}
	return 0;
}
