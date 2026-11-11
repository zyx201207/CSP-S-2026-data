#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,ma = 0,x=0;
	cin >> n>> m;
	int a[n+2];
	for  (int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	ma = a[1];
	if (m == 1)
	{
		for(int i = 1;i <= n;i ++)
		{
			if (a[i]>ma)
			{
				ma = a[i];
			}
		}
	}
	if (m==n)
	{
		for (int i = 2;i <= n;i ++)
		{
			ma = ma&a[i];
		}
	}
	if (m == 2)
	{
		for (int i = 1;i <= n;i++)
		{
			for (int j = 1;j <= n;j ++)
			{
				if (i!=j)
				{
					x= a[i]&a[j];
				}
				if (x > ma)
				{
					ma = x;
				}
			}
		}
	}
	cout << ma;
	return 0;
}
