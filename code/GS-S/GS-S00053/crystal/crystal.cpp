#include<bits/stdc++.h>
typedef long long ll ;
using namespace std ;
const int MAXN = 5e5 + 10 ;

ll a[MAXN] , n , m ,  ans , Temp[MAXN];

int main(){
	freopen("crystal.in" , "r" , stdin) ;
	freopen("crystal.out" , "w", stdout) ;
	ios::sync_with_stdio(false) ;
	cin.tie(0) ;
	cout.tie(0) ;
	
	cin>>n>>m ;
	
	for (int i = 1 ; i <= n ; ++i){
		cin>>a[i] ;
	}
	
	sort(a + 1 , a + 1 +n) ;
	
	for (int k = a[1] ; k <= a[n] ; ++k){
		ll mark = 1 , temp = m , cnt = 0;
		
		for (int i = 1 ; i <= n ; ++i){
			Temp[i] = a[i] ;
		}
		
		for (int i = 1 ; i <= n ; ++i){
			if (Temp[i] >= k){
				mark = i - 1;
				break ;
			}
		}
		
		for (int i = mark ; i >= 1 ; --i){
			if (k - Temp[i] <= temp){
				temp -= (k - Temp[i]) ;
				Temp[i] = k ;
				continue ;
			}else{
				break ;
			}
		}
		
		for (int i = 1 ; i <= n ; ++i){
			if (Temp[i] == k){
				++cnt ;
			}
		}
		
		if (cnt > ans){
			ans = cnt ;
		}
	}
	
	cout<<ans ;
	
	return 0 ;
}
