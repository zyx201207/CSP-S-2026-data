#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,t,n,d,edge[10002][10002],x[2000010],sum[2000010];
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	//cout << c << ' ' << t;
	while(t--)
	{
		cin >> n >> d;
		//cout << n << ' ' << d<< endl;
		for (int i = 1;i <= n;i++)
		{
			cin >> x[i];
			if (i >= 2)
			{
				sum[i] = x[i] - x[i - 1];
				//cout << sum[i];
			}
		}
		sum[1] = sum[2];
		int flag = 1;
		for (int i = 2;i <= n;i++)
		{
			if (sum[i] != sum[i - 1])
			{
				flag = 0;
				break;
			}
		}
		if (flag)
		{
			if (d >= sum[2])
			{
				//cout << "!!" << sum[2] << ' ' << d << ' ' << n << '\n';
				if (n >= (d / sum[2]) * 2 && d / sum[2] != 1)
				{
					cout << n - ((d / sum[2]) * 2 - 1) << '\n';
				}
				else
				{
					cout << 0 << '\n';
				}
			}
			else
			{
				//cout << "!!" << sum[2] << ' ' << d << ' ' << n << '\n';
				cout << 0 << '\n';
			}
		}
	}
	return 0;
}
