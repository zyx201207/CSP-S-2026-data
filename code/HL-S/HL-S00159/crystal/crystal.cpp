#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("crystal4.in","r",stdin);
	freopen("crystal4.out","w",stdout);
	long long n,m;
	cin >> n >> m;
	long long a[n + 5],sum = 0;
	for (int i = 1;i <= n;i ++)
	{
		cin >> a[i];
	}
	for (int i = n;i >= 1;i --)
	{
		long long ok = 1;
		long long s = m;
		for (int j = 1;j <= i - 1;j ++)
		{
			if (a[i] - a[j] <= s)
			{
				s -= a[i] - a[j];
			}
			else
			{
				ok = 0;
				break;
			}
		}
		if (ok) 
		{
			sum = i;
			break;
		}	
	}
	cout << sum;
	return 0;
}
