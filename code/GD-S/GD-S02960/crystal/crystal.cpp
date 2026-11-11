#include <bits/stdc++.h>
using namespace std;
long long n , m , a[500005] , max1 , sum = 1;
int main()
{
	freopen("crystal.in" , "r" , stdin);
	freopen("crystal.out" , "w" , stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	for(int j = 1;j <= n;j++)
	{
		for(int i = 2;i <= n;i++)
		{
			if(a[i] > a[i - 1])
			{
				max1 = a[i];
				a[i] = a[i - 1];
				a[i - 1] = max1;
			}
		}
	}
	for(int i = 2;i <= n;i++)
	{
		if(a[1] - a[i] <= m)
		{
			sum++;
		}
		else
		{
			break;
		}
		m -= a[1] - a[i];
	}
	cout << sum;
	return 0;
}
