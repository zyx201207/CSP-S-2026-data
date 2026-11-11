#include <bits/stdc++.h>
using namespace std;
int c,t,n,x[2000005];
long long d;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	while (t--)
	{
		cin >> n >> d;
		for (int i = 1;i <= n;i++)
		{
			cin >> x[i];
		}
		int m,z;
		if (x[1] < x[2])
		{
			m = x[2] - x[1];
		}
		else
		{
			m = x[1] - x[2];
		}
		if (d / m != 2)
		{
			cout << 0 << "\n";
			continue;
		}
		z = d / m;
		cout << n - (z * z - 1) << "\n";
	}
	return 0;
}
