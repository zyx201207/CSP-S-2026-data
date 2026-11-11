#include<bits/stdc++.h>
using namespace std ;
long long r[500005] ;
long long n ,m ;
long long sum[500005] ;
bool check(long long t ) {
	for(int i = 1 ;i + t - 1 <= n ;i++ ) {
		long long y = r[i + t - 1] * t - (sum[i + t - 2] - sum[i - 1]) ;
		if(y <= m ) return true ;
	}
	return false ;
}
int main() {
	freopen("crystal.in" ,"r" ,stdin ) ;
	freopen("crystal.out" ,"w" ,stdout ) ;
	cin >> n >> m ;
	for(int i = 1 ;i <= n ;i++ ) {
		cin >> r[i] ;
	}
	sort(r + 1 ,r + 1 + n ) ;
	for(int i = 1 ;i <= n ;i++ ) {
		sum[i] = sum[i - 1] + r[i] ;
	}
	long long l = 1 ,r = n ;
	while(l <= r ) {
		long long mid = (l + r ) / 2 ;
		if(check(mid)) {
			l = mid + 1 ;
		}
		else r = mid - 1 ;
	}
	cout << l ;
	
	return 0 ;
}
