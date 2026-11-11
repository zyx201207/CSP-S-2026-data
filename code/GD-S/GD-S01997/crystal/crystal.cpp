#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,a[10005],sum=0,num=0;
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	for (int i = 1;i <= n;i++)
	{
		if (a[i] < a[i+1])
		{
			a[i] += a[i+1]-a[i];
			sum += a[i+1]-a[i];
		}
		if (sum >= m)
		{
			break;
		}
		else
		{
			for (int i = 1;i <= n;i++)
			{
				if (a[i] < a[i+1])
				{
					a[i] += a[i+1]-a[i];
					sum += a[i+1]-a[i];
				}
			}
			if (sum >= m)
			{
				break;
			}
			else
			{
				for (int i = 1;i <= n;i++)
				{
					if (a[i] < a[i+1])
					{
						a[i] += a[i+1]-a[i];
						sum += a[i+1]-a[i];
						if (sum >= m)
						{
							break;
						}
					}
				}
			}
		}
	}
	for (int i = 1;i <= n;i++)
	{
		if (a[i]==a[i+1])
		{
			num++;
		}
	} 
	cout << num;
	return 0;
}
