#include <bits/stdc++.h>
using namespace std;
int n,m,a[10005];
int main()
{
	freopen( and.in , "r" , stdin);
	freopen( and.out , "w" , stdout);
	cin >> n >> m;
	for ( int i= 1 ; i <= n ; i++)
	{
		cin >> a[i];
		if (a[i] > a[i-1])
		{
			swap (a[i],a[i-1]);
		}
	}
	for ( int i= 1 ; i <= n ; i++)
	{
	    if (a[i] > a[i-1])
		{
			swap (a[i],a[i-1]);
		}
	}
	for (int i= 1 ; i <= m ; i++)
	{
		cout << a[m];
		return 0;
	}
	
	return 0;
	
 } 
 
 
 
 
