#include <bits/stdc++.h>
using namespace std;
int n,m,a[500005];
int main()
{
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	bool k = 1,l = 1;
	for(int i = 1;i <= n;i++)
	{
		if(a[i] != i)
		{
			k = 0;
		}
	}
	for(int i = 2;i < n;i++)
	{
		if(a[i] - a[i - 1] != a[i + 1] - a[i])
		{
			l = 0;
		}
	}
	int sum = 0;
	if(k)
	{
		for(int i = 1;i <= m;i++)
		{
			sum += i;
			if(sum == m)
			{
				cout << i << endl;
				break;
			}
			else if(sum > m)
			{
				cout << i - 1 << endl;
				break;
			}
		}
	}
	else if(l)
	{
		int r = a[2] - a[1];
		for(int i = 1;i <= m;i++)
		{
			sum += i;
			if(sum == m / r)
			{
				cout << i << endl;
				break;
			}
			else if(sum > m / r)
			{
				cout << i - 1 << endl;
				break;
			}
		}
	}
	return 0;
}