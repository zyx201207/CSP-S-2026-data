#include <bits/stdc++.h>
using namespace std ;
#define int long long
struct Sj{
	int in ;
	int z ;
}s[500005];

int  n , m , mxx = -1 , mnn = 1e18;
int a[500005] ;
int ind[500005] ;

bool cmp(Sj x , Sj y){
	return x.z < y.z ;
}
int in = 0 ;
int check(int mid){
	for(int i = 1 ; i <= n ; i++){
		if(mid >= a[i])s[i].z = mid - a[i] ;
		else s[i].z = 1e18 + 1 ; 
		s[i].in = i ;
	}
	sort(s + 1 , s + 1 + n , cmp) ;
	int tmp = m ;
	int cnt = 0 ;
	for(int i = 1 ; i <= n ; i++){
		if(s[i].z != (1e18+1) && tmp - s[i].z >= 0){
			tmp -= s[i].z ;
			cnt ++ ;
		}
		else{
			return cnt ;
		}
	}
	return 0ll ;
}
int maxx = -1 ;
int fn(){
	for(int i = 1 ; i <= n ; i++){
		maxx = max( check(a[i]) , maxx ) ;
	} 
	return maxx ;
}
int tsdx ;
bool tf ;
signed main(){
	freopen("crystal.in","r",stdin) ;
	freopen("crystal.out","w",stdout) ;
	scanf("%lld %lld" , &n , &m) ;
	for(int i = 1 ; i <= n ; i++){
		scanf("%lld" , &a[i]) ;
	} 
	sort(a + 1 , a + 1 + n) ;
	tf = 1 ;
	for(int i = 1 ; i <= n ; i++){
		if(i == 2) tsdx = a[2] - a[1] ;
		else if(i > 2 && (a[i] - a[i - 1]) != tsdx){
			tf = 0 ;
			break ;
		}
	}
	if(tf){
		cout << check(a[n]) ;
		return 0 ;
	}
	cout << fn() ;
	return 0 ;
}
