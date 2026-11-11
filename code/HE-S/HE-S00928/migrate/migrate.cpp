#include <bits/stdc++.h>
using namespace std;
int c,t,n,d,a[2000005],sum = 0;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> c >> t;
	while(t--)
	{
		cin >> n >> d;
		for (int i = 1;i <= n;i++)
		{
			cin >> a[i];
		}
		if (a[n] - a[1] <= d)
		{
			cout << 0 << endl;
			break;
		}
		if(a[2] - a[1] == a[3] - a[2] && a[2] - a[1] == a[n] - a[n - 1])
		{
			if ((a[2] - a[1] >= d) || (d <= 2 * (a[2] - a[1])))
			{
				cout << 0 << endl;
				break;
			}
			if ((n - 1) % (d / (a[2] - a[1])) == 0)
			{
				cout << 0 << endl;
				break;
			}
		}
		if (n % 2 == 0)
		{
			cout << 1 << endl;
		}
		else
		{
			cout << 2 << endl;
		}
	}
	
}
