#include<bits/stdc++.h>
using namespace std;
long long a[200010];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	int maxn = -1e9;
	if (m == 1)
	{
		cout << a[1];
	}
	if (m == 2)
	{
		for (int i = 1;i < n;i++)
		{
			for (int j = i+1;j <= n;j++)
			{
				if (maxn < (a[i] & a[j])) maxn = a[i] & a[j];
			}
		}
		cout << maxn;
	}
	if (m == 3)
	{
		for (int i = 1;i < n-1;i++)
		{
			for (int j = i+1;j < n;j++)
			{
				for (int k = j+1;k <= n;k++)
				{
					if (maxn < (a[i] & a[j] & a[k])) maxn = a[i] & a[j] & a[k];
				}
			}
		}
		cout << maxn;
	}
	if (m == 4)
	{
		for (int i = 1;i < n-2;i++)
		{
			for (int j = i+1;j < n-1;j++)
			{
				for (int k = j+1;k < n;k++)
				{
					for (int l = k+1;l <= n;l++)
					{
						if (maxn < (a[i] & a[j] & a[k] & a[l])) maxn = a[i] & a[j] & a[k] & a[l];
					}
					
				}
			}
		}
		cout << maxn;
	}
	if (m == n)
	{
		maxn = a[1];
		for (int i = 2;i <= n;i++)
		{
			maxn = maxn & a[i];
		}
		cout << maxn;
	}
	if (m == n-1)
	{
		sort (a+1,a+n+1);
		maxn = a[2];
		for (int i = 3;i <= n;i++)
		{
			maxn = maxn & a[i];
		}
	}
	return 0;
}
