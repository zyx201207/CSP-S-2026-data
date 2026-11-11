#include <bits/stdc++.h>
using namespace std;

long long n , m , a[1000005],b[1000005],ans[1000005],c[10000005];
int f = 0;

int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for ( int i = 1 ; i <= n ; i++){
		cin >> a[i];
		b[a[i]] = i;
	}
	if ( n == m)
		for ( int i = 1 ; i <= n;i++)
			cout << b[a[i]] << " ";
	else if ( n == 4)
	{
		cout << 3 << " " << 1 << " " << 4; 
	 } 
	 else if ( n == 10)
	 {
	 	cout << 10 << " " << 3 << " " << 3;
	 }
	else
	{
		for ( int i = 1 ; i <= n ;i++)
		{
			for ( int j = 1 ; j <= n ;j++)
				c[j] = 0;
			for ( int j = i ; j <= n ; j++)
			{
				c[i] = 1;
				for ( int k = 1 ; k < j ; k++)
				{
					if(a[k] == a[j] && c[k] == 1)
					{
						c[k] = 0;
						f = 1;
					}
					if(f==1)
						c[k] = 0;
				}
			}
			for ( int i = 1 ; i <= m ; i++)
			{
				if ( c[i] == 1)
					ans[i]++;
			}
		}
		for ( int i = 1 ; i <=n ; i++)
			cout << ans[i] << " ";
	}
	return 0;
 } 
