#include<bits/stdc++.h>
using namespace std ;
int a[100010] , n , m , ans = -1;
int main(){
	freopen("and.in","r",stdin) ;
	freopen("and.out","w",stdout) ;
	cin >> n >> m ;
	int k = m ;
	for (int i = 1 ; i <= n ; i++){
		cin >> a[i] ;
	}
	for (int i = 1 ; i <= n ; i++){
		int l = i+1 , p=a[i] ;
		 while(1){
		 	int j = l ;
		 	for ( ; j-l <= m  ; j++){
		 		p &= a[j] ;
			 }
			 l++ ;
			 ans = max(ans , p) ;
			 cout << p <<" ";
			 p = a[i] ;
			 if(l > n)break ;
		 }
	}
	cout << ans ;
	return 0 ; 
} 
