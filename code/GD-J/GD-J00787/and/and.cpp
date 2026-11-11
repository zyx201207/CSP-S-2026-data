#include <bits/stdc++.h>
using namespace std;
int n,m;
long long int a[2000005]; 
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	sort(a + 1,a+n + 1);
	if (m == 1)
	{
		cout << a[n];
	}
	long long int sum = 0;
	for (int i = 1;i <= n;i++)
	{
		for (int j = 1;j <= n - 1;j++)
		{
			sum = max(sum,a[i] & a[j]);
		}
	}
	long long int num = 0;
	if (m > 2)
	{
		for (int i = 1;i < m - 1;i++)
		{
			for (int j = 1;j <= n - i - 1;j++)
			{
				num = max(num,sum & a[j]);
			}
			sum = num;
			num = 0;
		}
		cout << num;
	}
	else
	{
		cout << sum;
	}
	return 0;
}
