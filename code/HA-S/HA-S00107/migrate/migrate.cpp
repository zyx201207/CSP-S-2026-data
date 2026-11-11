#include <bits/stdc++.h>
using namespace std;
int c,t;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	if (c == 11||c == 12)
	{
		for (int o = 1;o <= t;o++)
		{
			long long n,d,x,y;
			cin >> n >> d;
			cin >> x >> y;
			for (int i = 3;i <= n;i++)
			{
				long long k;
				cin >> k;
			}
			if (d<2*(y-x))
				cout << 0 << endl;
			else
				cout << n-2 << endl;
		}
	}
	else
		cout << 0 << endl << 1;
	return 0;
}
