#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin >> c >> t;
	if (c==11 || c==12)
	{
		for (int i = 1;i <= t;i++)
		{
			int n,d,a[2000005];
			cin >> n >> d;
			for (int i =1;i <= n;i++)
			{
				cin >> a[i];
			}
			if (2*d > (a[2]-a[1]))
			{
				cout << n << endl;
			}
			else
			{
				cout << 0 << endl;
			}
		}
	}
	if (c==13 || c==14)
	{
		for (int i = 1;i <= t;i++)
		{
			int n,d,a[2000005];
			cin >> n >> d;
			for (int i =1;i <= n;i++)
			{
				cin >> a[i];
			}
			int x;
			if (x%2==0)
				cout << n;
			else
				cout << n-1;
		}
	}
	return 0;
} 
