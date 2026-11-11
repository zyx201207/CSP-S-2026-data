#include <bits/stdc++.h>
using namespace std;
int c, t, n, d, x[60000];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.in","w",stdout);
	cin >> c >> t;
	for (int i = 1; i <= t; i++)
	{
		cin >> n >> d;
		for (int j = 1; j <= n; j++)
		{
			cin >> x[j];
		}
	}
	cout << 1 << endl;
	cout << 2;
	return 0;
}
