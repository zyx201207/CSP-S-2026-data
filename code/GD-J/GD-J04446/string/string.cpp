#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,a[200005],ans = 0,sum = 0;
	string b[200005],c;
	cin >> n;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
		ans += a[i];
	}
	for (int i = 1;i <= n;i++)
	{
		cin >> b[i];
		for (int j = 1;j <= a[i];j++)
		{
			c += b[i];
		}
	}
	int d = ans / 2;
	if (ans % 2 == 0)
	{
		for (int i = 1;i <= d;i++)
		{
			if (c[i] != c[n - i - 1])
			{
				sum++;
			}
		}
	}
	else
	{
		for (int i = 1;i <= d;i++)
		{
			if (c[i] != c[n - i - 1])
			{
				sum++;
			}
		}
	}
	cout << sum;
	return 0;
}






