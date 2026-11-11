#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[200005];

bool cmp(int a, int b)
{
	return a > b;
}

int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	
	cin >> n >> m;
	
	if (m == 1)
	{
		int ret = 0;
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i];
			ret = max(ret, a[i]);
		}
		
		cout << ret;
		return 0;
	}
	
	if (m == 2)
	{
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i];
		}
		
		int cnt = 0, ret = 0;
		for (int i = 1; i <= n-1; i++)
		{
			for (int j = i+1; j <= n; j++)
			{
				cnt++;
				if (cnt > 1059999999) 
				{
					cout << ret;
					return 0;
				}
				ret = max(ret, a[i] & a[j]);
			}
		}
		cout << ret;
		return 0;
	}
	
	if (m == n)
	{
		cin >> a[1];
		int ret = a[1];
		for (int i = 2; i <= n; i++)
		{
			cin >> a[i];
			ret = ret & a[i];
		}
		
		cout << ret;
		return 0;
	}
	
	if (n <= 20 && m == 3)
	{
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i];
		}
		
		int ret = 0, cnt = 0;
		for (int i = 1; i <= n-2; i++)
		{
			for (int j = i+1; j <= n-1; j++)
			{
				for (int k = j+1; k <= n; k++)
				{
					cnt++;
					if (cnt > 1059999999) 
					{
						cout << ret;
						return 0;
					}
					ret = max(ret, a[i] & a[j] & a[k]);
				}
			}
		}
		
		cout << ret;
		return 0;
	}
	
	if (m == 4)
	{
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i];
		}
		
		int ret = 0, cnt = 0;
		sort(a+1, a+n+1, cmp);
		for (int i = 1; i <= n-3; i++)
		{
			for (int j = i+1; j <= n-2; j++)
			{
				for (int k = j+1; k <= n-1; k++)
				{
					for (int l = k+1; l <= n; l++)
					{
						cnt++;
						if (cnt > 1059999999) 
						{
							cout << ret;
							return 0;
						}
						ret = max(ret, a[i] & a[j] & a[k] & a[l]);
					}
				}
			}
		}
		
		cout << ret;
		return 0;
	}
	
	
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	
	sort(a+1, a+n+1, cmp);
	
	int ret = a[1];
	for (int i = 2; i <= m; i++)
	{
		ret = ret & a[i];
	}
	
	cout << ret;
}
