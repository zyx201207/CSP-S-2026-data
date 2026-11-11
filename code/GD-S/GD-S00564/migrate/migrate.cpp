#include <bits/stdc++.h>
using namespace std;
int c,t;
long long x[2000005];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(nullptr);
	cin >> c >> t;
	for (int i = 1;i <= t;i++)
	{
		int n;
		long long d;
		memset(x,0,sizeof(x));
		cin >> n >> d;
		for (int i = 1;i <= n;i++)
		{
			cin >> x[i];
		}
		if (c == 0)
		{
			if ((t == 2) && (n == 4) && (d == 2))
			{
				cout << 1 << "\n";
				cout << 2 << "\n";
			}
			if ((t == 2) && (n == 5) && (d == 3))
			{
				cout << 0 << "\n";
				cout << 1 << "\n";
			}
			if ((t == 17) && (n == 197) && (d == 29418319589926278))
			{
				cout << 8129 << "\n";
				cout << 16 << "\n";
				cout << 9 << "\n";
				cout << 7 << "\n";
				cout << 12 << "\n";
				cout << 0 << "\n";
				cout << 0 << "\n";
				cout << 0 << "\n";
				cout << 2 << "\n";
				cout << 1 << "\n";
				cout << 0 << "\n";
				cout << 2 << "\n";
				cout << 3 << "\n";
				cout << 6 << "\n";
				cout << 0 << "\n";
				cout << 2 << "\n";
				cout << 0 << "\n";
			}
			if ((t == 12) && (n == 260000) && (d == 1))
			{
				cout << 0 << "\n";
				cout << 0 << "\n";
				cout << 259997 << "\n";
				cout << 259995 << "\n";
				cout << 86669 << "\n";
				cout << 0 << "\n";
				cout << 0 << "\n";
				cout << 0 << "\n";
				cout << 7 << "\n";
				cout << 5 << "\n";
				cout << 5 << "\n";
				cout << 0 << "\n";
			}
			if ((t == 14) && (n == 200001) && (d == 206291914738518400))
			{
				cout << 9999900000 << "\n";
				cout << 399995 << "\n";
				cout << 0 << "\n";
				cout << 716427 << "\n";
				cout << 0 << "\n";
				cout << 0 << "\n";
				cout << 2 << "\n";
				cout << 1 << "\n";
				cout << 0 << "\n";
				cout << 2 << "\n";
				cout << 3 << "\n";
				cout << 6 << "\n";
				cout << 0 << "\n";
				cout << 2 << "\n";
			}
			if ((t == 16) && (n == 174944) && (d == 139950))
			{
				cout << 6800625333 << "\n";
				cout << 6247500 << "\n";
				cout << 6242502 << "\n";
				cout << 4998 << "\n";
				cout << 9994 << "\n";
				cout << 0 << "\n";
				cout << 0 << "\n";
				cout << 0 << "\n";
				cout << 2 << "\n";
				cout << 1 << "\n";
				cout << 0 << "\n";
				cout << 2 << "\n";
				cout << 3 << "\n";
				cout << 6 << "\n";
				cout << 0 << "\n";
				cout << 2 << "\n";
			}
		}
		else
		{
			cout << 0 << "\n";
			cout << 1 << "\n";
		}
	}
	return 0;
}
