#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<string>
#include<cstring>
#include<stack>
#include<vector>
#include<queue>
using namespace std;
int n,m,a[200010],ans,maxai;
void dfs( int pos,int num,int sum )
{
	//cout << pos << " " << num << " " << sum << ' ';
	if ( num == m )
	{
		ans = max ( ans,sum );
		return;
	}
	if ( pos > n )
	    return;
	dfs ( pos + 1,num + 1,( num == 0 ) ? a[pos] : sum & a[pos] );
	dfs ( pos + 1,num,sum );
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio( 0 );
	cin.tie( 0 );
	cin >> n >> m;
	for ( int i = 1;i <= n;i++ )
	{
		cin >> a[i];
		maxai = max ( a[i],maxai );
	}
	sort ( a + 1,a + n + 1,greater<int>() );
	if ( m == 1 )
	{
		cout << a[1];
		return 0;
	}
	if ( maxai <= 3 )
	{
		int a1 = 0,a2 = 0,a3 = 0,a0 = 0;
		for ( int i = 1;i <= n;i++ )
		{
		    if ( a[i] == 1 )    a1++; 
		    if ( a[i] == 2 )    a2++; 
		    if ( a[i] == 3 )    a3++; 
		    if ( a[i] == 0 )    a0++; 
		}
		if ( m <= a3 )
		{
			cout << 3;
			return 0;
		}
		if ( m <= a2 )
		{
			cout << 2;
			return 0;
		}
		if ( m <= a3 + a2 )
		{
			cout << 2;
			return 0;
		}
		if ( m > a3 + a2 )
		{
			if ( m <= a1 + a2 + a3 )
			{
				cout << 1;
				return 0;
			}
			else
			{
				cout << 0;
				return 0;
			}
		}
	}
	if ( m == 2 )
	{
		dfs( 1,0,0 );
		cout << ans;
		return 0;
	}
	if ( m == n )
	{
		ans = a[1];
		for ( int i = 2;i <= n;i++ )
		{
			ans = ans & a[i];
		}
		cout << ans;
		return 0;
	}
	dfs( 1,0,0 );
	cout << ans;
	return 0;
}
