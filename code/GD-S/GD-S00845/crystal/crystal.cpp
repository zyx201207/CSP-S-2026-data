#include<bits/stdc++.h>

using namespace std;

long long int a[600001];
long long int n, m, q;
long long int ans, c;
int b[501];

bool check1()
{
	int r = a[2] - a[1];
	for( int i = 1; i <= n - 1; i++ )
	{
		if( a[i+1] - a[i] != r )
		{
			return false;
		}
	}
	
	return true;
}

bool check2()
{
	for( int i = 1; i <= n; i++ )
	{
		if( a[i] >= 200 || a[i] <= -200 )
		{
			return false;
		}
	}
	
	return true;
}

int main()
{
	freopen( "crystal.in", "r", stdin );
	freopen( "crystal.out", "w", stdout );
	
	cin >> n >> m;
	
	for( int i = 1; i <= n; i++ )
	{
		cin >> a[i];
	}
	
	sort( a + 1, a + 1 + n );
	a[n+1] = 1000000000000000;
	
	if( check1() == true )
	{
		ans = 0;
		for( int j = 1; j <= n; j++ )
		{
			q += ( a[j+1] - a[j] ) * j;
			
			if( q > m )
			{
				ans = max( ans, (long long int)(j) );
				break;
			}
		}
		
		if( q <= m )
		{
			ans = n;
		}
		
		cout << ans << endl;
		
		return 0;
	}
	
	if( check2() == true )
	{
		ans = 0;
		for( int i = 1; i <= n; i++ )
		{
			b[a[i]+200]++;
		}
		
		for( int i = 401; i >= 0; i-- )
		{
			q = 0;
			c = 0;
			
			for( int j = i; j >= 0; j-- )
			{
				q += b[j] * ( i - j );
				c += b[j];
				
				if( q > m )
				{
					c -= b[j];
					q -= b[j] * ( i - j );
					c += ( m - q ) / ( i - j );
					break;
				}
			}
			
			ans = max( ans, c );
		}
		
		cout << ans << endl;
		
		return 0;
	}
	
	ans = 0;
	for( int i = 1; i <= n; i++ )
	{
		q = 0;
		
		for( int j = i; j <= n; j++ )
		{
			q += ( a[j+1] - a[j] ) * ( j - i + 1 );
			
			if( q > m )
			{
				ans = max( ans, (long long int)( j - i + 1 ) );
				break;
			}
		}
		
		if( q <= m )
		{
			ans = max( n - i + 1, ans );
		}
	}
	
	cout << ans << endl;
	
	return 0;
}

