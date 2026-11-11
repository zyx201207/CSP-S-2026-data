#include <iostream>
#include <algorithm>
using namespace std ;
string name = "crystal" ;
bool debug = 0 ;//上交时为0！
const int N = 5 * 1e5 + 5 ;
int n ;
long long m , a[N] , c[N] ;
int main()
{
    if(!debug)
	{
		string inname = name + ".in" ;
		string outname = name + ".out" ;
		freopen(inname.c_str() , "r" , stdin) ;
		freopen(outname.c_str() , "w" , stdout) ;
	}
	cin >> n >> m ;
	for(int i = 1 ; i <= n ; i ++)
		cin >> a[i] ;
	sort(a + 1 , a + 1 + n) ;
	for(int i = 1 ; i <= n ; i ++)
		c[i] = a[i] - a[i - 1] ;
	int l = 1 , r = 1 , maxn = 0 ;
	unsigned long long cost = 0 ;
	for(; r <= n ;)
	{
		while(cost > m && l < r)
		{
			
			cost -= a[r] - a[l] ;
			l ++ ;
		}
		maxn = max(maxn , r - l + 1) ;
		r ++ ;
		cost += c[r] * (r - l) ;
	}
	cout << maxn ;
	return 0 ;
}
//yee~
