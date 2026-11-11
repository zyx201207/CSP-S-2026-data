#include<iostream>
#include<algorithm>
#include<cstdio>
#define int long long
using namespace std ;
const int N = 5e5 + 10 ;
long long a[N] , n , m ;
long long check(int k){
	long long cnt = 0 ;
	for(int i = 0 ; i < k - 1; i++){
		cnt += a[k-1] - a[i] ;
	}
	long long minn = cnt ;
	for(int i = 1 ; i < n - k ; i++){
		cnt = cnt - (a[i+k-2]-a[i-1]) + (a[i+k-1] - a[i+k-2]) * (k-1) ;
		minn = min(minn,cnt) ;
	}
	return minn ;
}
signed main(){
	freopen("crystal.in","r",stdin) ;
	freopen("crystal.out","w",stdout) ;
	scanf("%lld %lld",&n,&m) ;
	for(int i = 0 ; i < n ; i++){
		scanf("%lld",&a[i]) ;
	}
	sort(a,a+n) ;
	int l = 1 , r = n ;
	while(l < r){
		int mid = (l+r+1)>>1 ;
		//cout << l << " " << r << " " << mid  << "\n" ;
		if(check(mid) <= m){
			l = mid ;
		}else{
			r = mid - 1 ;
		}
	}
	printf("%lld\n",l) ;
	fclose(stdin) ;
	fclose(stdout) ;
	return 0 ;
}