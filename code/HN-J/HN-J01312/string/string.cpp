#include <bits/stdc++.h>
using namespace std ;
#define int long long
const int N = 2e5 + 5 ;
int n , x[N] , ans , lpos , rpos ;
char c[N] ;
string s ;
signed main()
{
	ios::sync_with_stdio(0) ;
	cin.tie(0) ;
	cout.tie(0) ;
	freopen("string.in" , "r" , stdin) ;
	freopen("string.out" , "w" , stdout) ;
	cin >> n ;
	rpos = n ;
	for(int i = 1 ; i <= n ; i ++) cin >> x[i] >> c[i] ;
	while(lpos < rpos)
	{
		int minn = min(x[lpos] , x[rpos]) ;
		if(c[lpos] != c[rpos]) ans += minn ;
		x[lpos] -= minn ;
		x[rpos] -= minn ;
		if(!x[lpos]) lpos ++ ;
		if(!x[rpos]) rpos -- ;
	}
	cout << ans ;
	return 0 ;
}

