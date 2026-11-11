#include <bits/stdc++.h>
using namespace std;
int n,m;
long long a[2000005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	if (m == 1)
	{
		sort(a + 1,a + n + 1);
		cout << a[n];
	}
	else if (m == n)
	{
		int num = a[1];
		for (int i = 2;i <= n;i++)
		{
			num = (a[i] & num);
		}
		cout << num;
	}
	else if (m == 2)
	{
		int maxn = -1;
		for (int i = 1;i <= n - 1;i++)
		{
			for (int j = i + 1;j <= n;j++)
			{
				if ((a[i] & a[j]) > maxn)
				{
					maxn = (a[i] & a[j]);
				}
			}
		}
		cout << maxn;
	}
	else if (m == n - 1)
	{
		int num,maxn = -1;
		for (int i = 1;i <= n;i++)
		{
			if (i == 1)
			{
				num = a[2];
			}
			else
			{
				num = a[1];
			}
			for (int j = 1;j <= n;j++)
			{
				if (i != j)
				{
				    num = (a[j] & num);	
				}
			}
			if (num > maxn)
			{
				maxn = num;
			}
		}
		cout << maxn;
	}
	return 0;
}
