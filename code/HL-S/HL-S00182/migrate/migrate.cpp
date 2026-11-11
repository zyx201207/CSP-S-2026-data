#include <bits/stdc++.h>
using namespace std;
long long c,t,n,d;
long long x[2000006];
int a(int f)
{
	int g = 1,h = 0,m = 0;
	if (f == 0 || f == 1)
	{
		cout<<0<<endl;
	}
	if (f == 2)
	{
		if (n % 2 == 0)
		{
			return 1;
		}else{
			return 2;
		}
	}else{
		for (int i = 1;i <= n;i ++)
		{
			if (x[i]-x[g] <= f)
			{
				h ++;
			}else{
				if (h == 2)
				{
					m ++;
				}
				g ++;
				h = 0;
			}
		}
		return m;
	}
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >>c>>t;
	while (t --)
	{
		for (int i = 1;i <= n;i ++) x[i] = 0;
		cin >>n>>d;
		for (int i = 1;i <= n;i ++)
		{
			cin >>x[i];
		}
		cout<<a(d);
	}
	return 0;
}
