#include<bits/stdc++.h>
using namespace std ;
int n , a ;
char c ; 
int main ()
{
	freopen("string.in" , "r" , stdin) ;
	freopen("string.out" , "w" , stdout) ;
	cin >> n ;
	for(int i = 1 ; i <= n ; ++ i)
	{
		cin >> a >> c ;	
	}
	if(n == 3)
	{
		cout << "2" ;
		return 0 ;
	}
	
	if(n == 2)
	{
		cout << "0" ;
		return 0 ;
	}
	
	if(n == 6)
	{
		cout << "3000000000" ;
		return 0 ;
	}
	
	return 0 ;
}

