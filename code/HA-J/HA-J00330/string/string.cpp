#include <bits/stdc++.h>
using namespace std;
int a[200005];
char c[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	long long sum = 0;
	cin >> n;
	for(int m = 1;m <= n;m++)
	{
		cin >> a[m] >> c[m];
	}
	for(int i = 1,j = 1;i + j <= n;)
	{
		if(a[i] == a[n - j + 1])
		{
			if(c[i] != c[n - j + 1])
			{
				sum = sum + a[i];
				i++;
				j++;
			}
		}
		else if(a[i] < a[n - j + 1])
		{
			if(c[i] == c[n - j + 1])
			{
				a[i] = a[n - j + 1] - a[i];
				i++;
			}
			else
			{
				sum = sum + a[i];
				a[i] = a[n - j + 1] - a[i];
				c[i] = c[n - j + 1];
				i++;
			}
		}
		else
		{
			if(c[i] == c[n - j + 1])
			{
				a[i] = a[i] - a[n - j + 1];
				j++;
			}
			else
			{
				sum = sum + a[n - j + 1];
				a[i] = a[i] - a[n - j + 1];
				j++;
			}
		}
	}
	cout << sum;
	return 0;
}