#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	long n, m, a[500005],sum = 0;//a,b的值很大 
	cin >> n >> m;
	for (long i = 1; i <= n; i++)
	{
		cin >> a[i];//读入ai 
	}
	int s = a[2] - a[1];
	for (long i = 1; i <= n; i++)
	{
		sum += i * s;
		if (sum > m)
		{
			cout << i;
			return 0;
		}
	}
	return 0;
}
