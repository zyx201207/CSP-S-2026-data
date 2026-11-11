//贵阳市第十九中学 刘承福 GZ-S00032
#include <bits/stdc++.h>
using namespace std;

long long c, t;
long long n, d;
long long a[2000005];

int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while (t--)
	{
		cin >> n >> d;
		for (long long i = 1; i <= n; i++)
		{
			cin >> a[i]; 
		}
		long long gc = abs(a[2] - a[1]);
		if (gc * 2ll > d) cout << 0 << endl;
		else
		{
			cout << n-3ll << endl;
		}
	}
	return 0;
}

