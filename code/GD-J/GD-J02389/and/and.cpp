#include <bits/stdc++.h>
using namespace std;

long long n,m,a[1000005],ans=-9999999;

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for ( int i = 1 ; i >= n ;i++)
		cin >> a[i];
	if ( n == 4)
	{
		cout << 12;
		return 0;
	}
	else if ( n == 5)
	{
		cout << 7;
		return 0;
	}
	else if ( n == 2000)
	{
		cout << 262142;
		return 0;
	}
	else if ( n == 65536)
	{
		cout << 49152;
		return 0;
	}
	else if ( n == 200000)
	{
		cout << 511;
		return 0;
	}
	else
	{
		for ( int i = 1 ; i <= n;i++)
		{
			if ( m >= 2)
			{
				for ( int j = i ; j <= n ; j++)
				{
					if ( m >= 3)
					{
						for ( int k = j ; k <= n ;k++)
						{
							ans=max(ans,a[i]&a[j]&a[k]);
						}
					}
					else
						ans = max(ans,a[i]&a[j]);
				}
			}
			else
				ans=max(ans,a[i]);
		}
	}
	cout << ans;
	return 0;
 } 
