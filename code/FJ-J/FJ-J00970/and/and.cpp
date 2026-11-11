#include <iostream>
using namespace std ;
string name = "and" ;
bool debug = 0 ;//Òªµ÷0£¡
const int N = 35 , M = 2 * 1e5 + 5 ; 
int n , m , ans ;
int tot[N] , a[M] ;
bool ok[M] ;
string str[M] ;
inline void input(int i)
{
	int temp = a[i] ;
	ok[i] = 1 ;
	int siz = 0 ;
	while(temp != 0)
	{
		str[i] += temp % 2 + '0' ;
		tot[++ siz] += temp % 2 ;
		temp /= 2 ; 
	}
}
inline void del(int i)
{
	int temp = a[i] ;
	ok[i] = 0 ;
	int siz = 0 ;
	string str = "" ;
	while(temp != 0)
	{
		tot[++ siz] -= temp % 2 ;
		temp /= 2 ; 
	}
}
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
	int t ;
	for(int i = 1 ; i <= n ; i ++)
		cin >> a[i] , input(i) ; 
	int len = 0 ;
	for(int i = 1 ; i < N ; i ++)
		if(tot[i] != 0)
			len = i ;
	for(int i = len ; i > 0 ; i --)
	{
		if(tot[i] < m)
			continue ;
		ans += (1 << (i - 1)) ;
		for(int j = 1 ; j <= n ; j ++)
		{
			if(str[j][i - 1] != '1' && ok[j] != 0)
				del(j) ;
		}
	}
	cout << ans << '\n' ;
	return 0 ;
}
//yee~
