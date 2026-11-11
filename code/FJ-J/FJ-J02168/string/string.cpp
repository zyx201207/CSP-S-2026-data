#include <iostream>
using namespace std;
int n , a[200005] , k , sum = 0 , ans = 0 ;
char s[200005] ;
int main()
{
	freopen("problem1.in","r",stdin);
	freopen("problem1.out","w",stdout);
	char k ;
	cin >> n ;
	for ( int i = 1 ; i <= n ; i ++ )
	{
		cin >> a[i] >> k ;
		for ( int j = sum + 1 ; j <= sum + a[i] ; j ++ )
		{
			s[j] = k ;
		}
		sum += a[i];
	}
	for ( int i = 1 ; i <= sum / 2 ; i ++ )
	{
		if ( s[i] != s[sum+1-i] )
		{
			ans ++ ;
		}
	}
	cout << ans ;
}
