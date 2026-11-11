//GZ-S00025 秦子懿 贵阳市白云区华师一学校 
#include <bits/stdc++.h>
using namespace std ;
#define int long long
int n , m ;
int a[500000 + 10] ;
int sum[500000 + 10] ;
bool check(int x){
//	cout << x << " : \n" ;
	for(int i = 1 ; i + x - 1 <= n ; i ++){
		int need = a[i + x - 1] * x - (sum[i + x - 1] - sum[i - 1]);
//		cout << "  " << i << ' ' << need << '\n' ;
		if(need <= m) return 1 ;
	}
	return 0 ;
}
signed main(){
	freopen("crystal.in" , "r" , stdin) ;
	freopen("crystal.out" , "w" , stdout) ;
	scanf("%lld%lld" , &n , &m) ;
	for(int i = 1 ; i <= n ; i ++) scanf("%lld" , &a[i]) ;
//	cout << n << ' ' << m << '\n' ;
	sort(a + 1 , a + 1 + n) ;
//	for(int i = 1 ; i <= n ; i ++) cout << a[i] << ' ' ;
//	cout << '\n' ;
	for(int i = 1 ; i <= n ; i ++) sum[i] = sum[i - 1] + a[i] ;
	int l = 1 , r = n ;
	while(l < r){
		int mid = (l + r + 1) / 2 ;
//		cout << mid << '\n' ;
		if(check(mid)) l = mid ;
		else r = mid - 1 ;
	}
	printf("%lld" , l) ;
	return 0 ;
}
