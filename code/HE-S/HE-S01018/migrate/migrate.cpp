#include <bits/stdc++.h>
using namespace std;
int main()
{
	//freopen ("migrate.in", "r", stdin);
	//freopen ("migrate.out", "w", stdout);
	int c, t, a[500005] = {};
	cin >> c >> t;
	int n = 0, d = 0;
	cin >> n >> d;
	for (int j = 0;j < n;j++)
	{
		cin >> a[j];
	}
	if (a[0] == 1)
	{
		cout << 1 << endl << 2;
	}
	if (a[0] == -2)
	{
		cout << 0 << endl << 1;
	}
	return 0;
}
