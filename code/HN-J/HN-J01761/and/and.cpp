#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int a[200010],ab,sum;
int n,m;
int A( int b )
{
	for ( int j = 0;j < b;j++ )
	{
		for ( int i = 0;i < n-1;i++ )
		{
			ab ^= a[i];
		}
		if ( ab > sum ) cout << ab;
	}
	return 0;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m; 
	for ( int i = 0;i < n;i++ ) cin >> a[i];
	A(m);
	cout << sum;
	return 0;
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
 } 
