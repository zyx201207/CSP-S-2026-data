#include <bits/stdc++.h>
using namespace std;
string c[200005];
long long a[200005];
int main()
{
	freopen("string.in" , "r" , stdin);
	freopen("string.out" , "w" , stdout);
	long long n , sum = 0;
	cin >> n;
	for (int i = 1 ; i <= n ; i++)
	{
		cin >> a[i] >> c[i];
	}
	long long r = 0 , l = n;
	while (r < l)
	{
		if (a[r] > a[l])
		{
			if (c[r] == c[l])
			{
				a[r] -= a[l];
				l--;
			}
			else
			{
				sum += a[l];
				a[r] -= a[l];
				l--;
			}
		}
		else
		{
			if (c[r] == c[l])
			{
				a[l] -= a[r];
				r++;
			}
			else
			{
				sum += a[r];
				a[l] -= a[r];
				r++;
			}
		}
	}
	cout << sum;
	return 0;
} 
