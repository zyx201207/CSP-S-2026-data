#include <bits/stdc++.h>
using namespace std;
long long n,m,a[1000005],sum,k,x;
int main()
{
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	if(m == n)
	{
		sum = a[1] & a[2];
		for(int i = 3;i <= n;i++)
		{
			sum = sum & a[i];
		}
		cout << sum;
		return 0;
	}
	if(n == 1 && m == 1)
	{
		cout << a[1];
		return 0;
	}
	 else if(m == 1)
	{
		sort(a + 1 , a + n + 1);
		cout << a[n];
		return 0;
	}
	return 0;
}
