//GZ-J00502 ³ÂÜÆÝæ 
#include <bits/stdc++.h>
using namespace std ;
const int N = 2e5+10 ;
int n,m,ma ;
int a[N] ;
int main(){
	freopen("and.in" , "r" , stdin) ;
	freopen("and.out" , "w" , stdout) ;
	cin >> n >> m ;
	for(int i = 1 ; i <= n ; i++){
		cin >> a[i] ;
	}
	for(int i = 1 ; i <= n ; i++){
		int cnt = 0 ;
		int s ;
		for(int j = 1 ; j <= n ; j++){
			if(cnt == m){
				break ;
			}
			s += &a[i] ;
			cnt++ ;
		}
		if(ma < s){
			ma = s ;
		}
	}
	cout << ma ;
	return 0 ;
}
