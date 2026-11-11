#include<bits/stdc++.h> 
using namespace std ;
int a[10001] ;
int main()
{
	freopen("andin","w",stdin) ;
	freopen("andout","r",stdout) ;
	int n , m ,p = 999999;
	cin >> n >> m ;
	for(int i = 1 ; i < n ; i ++)
	{
		cin >> a[i] ;
		p = min(a[i] , p) ;
	} 
	cout << a[1] << p << a[n] ;
	
	fclose(stdin) ;
	fclose(stdout) ;
	return 0 ;
}
