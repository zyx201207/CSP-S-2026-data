#include <bits/stdc++.h> 
using namespace std ;
int a[20000005] , n , sum ;
long long cnt = 1 ;
int main()
{
	freopen("string.in" , "r" , stdin) ;
	freopen("string.out" , "w" , stdout) ;
	cin >> n ;
	for (int i = 1 ; i <= n ; i++){
		char x ;
		int m , k;
		cin >> m >> x ;
		k = x - 'a' + 1 ;
		for (int j = cnt ; j <= cnt + m - 1 ; j++) {
			a[j] = k ;
		}
		cnt += m ;
	}
	cnt-- ;
	for (int i = 1 ; i <= cnt / 2 ; i++){
		if (a[i] != a[cnt + 1 - i]) sum++ ;
	}
	cout << sum ;
	return 0 ;
}
