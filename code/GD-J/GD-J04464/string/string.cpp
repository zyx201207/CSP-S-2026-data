#include <bits/stdc++.h>

using namespace std ;

int main ()
{
	freopen("string.in" , "r" , stdin) ;
	freopen("string.out" , "w" , stdout) ;
	long long n , k , ans = 0 ;
	char zzz ;
	string wzy = "" ;
	cin >> n ;
	for(int w = 1;w <= n;w ++) {
		cin >> k >> zzz ;
		for(int i = 1;i <= k ; i ++) wzy.push_back(zzz) ;
	}
	for(int i = 0 , c = wzy.size() - 1;i <= c;i ++ , c --) 
			if(wzy[i] != wzy[c]) ans ++ ;
	cout << ans ;
	return 0 ;
}

// 3 / 2a / 2b / 2c 
//Trick||Treat!
