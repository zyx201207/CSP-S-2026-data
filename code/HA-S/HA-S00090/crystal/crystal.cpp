#include<bits/stdc++.h>
using namespace std ;
long long m , n , ans = -1 , j = 1 , ans1 = 1e9 ;
long long a[500001] , b[500001] ;
int main(){
	freopen("crystal.in","r",stdin) ;
	freopen("crystal.out","w",stdout) ;
	cin >> n >> m ;
	for (int i = 1 ; i <= n ; i++){
		cin >> a[i] ;
	}
	sort(a+1 , a+1+n ) ;
	for (int i = 1 ; i <= n ; i++){
		b[i] = b[i-1]+a[i] ;
	}
	while(j <= n){
		for (long long i = j ; i <= n ; i++){
			long long o = b[i]-b[j-1]-a[i]*(i-1) ;
			long long g = abs(o);
			if(g <= m){
				ans = max(ans , i) ;
			}
			
		 }j++ ;
		 ans1=min(ans1,ans) ;
	}
	cout << ans1 ;
	return 0 ;
}
