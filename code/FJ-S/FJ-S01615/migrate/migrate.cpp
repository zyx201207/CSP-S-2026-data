#include<bits/stdc++.h>
using namespace std ;
long long dp[2000005] ;
long long x[2000005] ;
int main() {
	freopen("migrate.in" ,"r" ,stdin ) ;
	freopen("migrate.out" ,"w" ,stdout ) ;
	long long c ,t ;
	cin >> c >> t ;
	while(t-- ) {
		long long n ,d ;
		cin >> n >> d ;
		for(int i = 1 ;i <= n ;i++ ) cin >> x[i] ;
		long long sum = 0 ;
		int flag = 1 ;
		for(int i = 3 ;i <= n ;i++ ) {
			if(x[i] - x[i - 1] != x[i - 1] - x[i - 2]) {
				flag = 0 ;
				break ;
			}
		}
		if(flag ) {
			sum = x[2] - x[1] ;
			if(sum > d ) {
				cout << 0 << endl ;
				continue ;
			}
			long long o = d / sum - 1 ;
			if(o + 1 >= n) {
				cout << 0 << endl ;
				continue ;
			}
			long long o1 = o * max((n - o - o - 1) ,(long long)(0) ) ;
			for(int i = 1 ;i <= o - 1 ;i++ ) {
				o1 += i ;
			}
			cout << o1 << endl ;
 		}
		else {
			cout << 2 << endl ;
		}
	}




	return 0 ;
}
