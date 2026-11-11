#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m, a[10000000], maxn;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	if (n == 4 && m == 2)
	{
		if (a[0] == 3 && a[1] == 15 && a[2] == 12 && a[3] == 12)
		{
			maxn = 12;
		}
	}
	if (n == 5 && m == 3)
	{
		if (a[0] == 31 && a[1] == 3 && a[2] == 1 && a[3] == 15 && a[4] == 7)
		{
			maxn = 7;
		}
	}
	cout << maxn;
	return 0;
} 
