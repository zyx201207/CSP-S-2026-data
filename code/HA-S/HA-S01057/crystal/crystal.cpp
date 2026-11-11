#include <bits/stdc++.h>
using namespace std;
long long n , m , a[550000] , add[550000] , ans ;
bool work(long long x){
	long long t = n-x ;
	bool f = 0 ;
	for(long long i = 1 ; i <= t ; i++){
		if((a[i+x-1]*x-add[i+x-1]+add[i-1])<=m){
			f = 1 ;
			break ;
		}
	}
	return f ;
}
int main(){
	freopen("crystal.in","r",stdin) ;
	freopen("crystal.out","w",stdout) ;
	std::ios::sync_with_stdio(0) ;
	cin >> n >> m ;
	for(long long i = 1 ; i <= n ; i++){
		cin >> a[i] ;
	}
	sort(a+1,a+n+1);
	for(long long i = 1 ; i <= n ; i++){
		add[i] = add[i-1]+a[i] ;
	}
	long long l = 1 , r = n , mid = (l+r)>>1 ;bool f ;
	while(l<=r){
		f = work(mid) ;
		if(f){
			l = mid+1 ;
			ans = mid ;
			mid = (l+r)>>1 ;
		}else{
			r = mid-1 ;
		 	mid = (l+r)>>1 ;
		}
	}
	cout << ans ;
	return 0 ;
}
