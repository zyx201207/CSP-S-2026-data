#include <bits/c++.h>
namespace std;
int main()
{
	int n,q,s;
	q = 0;
	s = 0;
	cin>>n;
	int a[n];
	chr b[n];
	for (int i = 0;i < n;i++)
	{
		cin>>a[i]>>b[i];
		q += a[i]
	}
	chr c[q]
	for (int i = 1;i <= n;i++)
	{
		for (int j = 0;j < a[i];j++)
		{
			c[i*j] = b[i-1];
		}
	}
	for (int i = 0;i < n;i++)
	{
		for (int j = n;j>=0;j--)
		{
			if (i == n - j)
			{
				if (c[i] != c[j])
				{
					s += 1;
					c[i] = c[j];
				}
			}
		}
	}
	cout<<s;
	return 0;
}
