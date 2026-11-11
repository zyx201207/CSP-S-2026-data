#include <bits/stdc++.h>
using namespace std ;
int main(){
	freopen("and.in" , "r" , stdin) ;
	freopen("and.out" , "w" , stdout) ;
	int n , m , a[200005] ;
	cin >> n >> m ;
	for(int i = 1;i <= n;i++){
		cin >> a[i] ;
	}
	int ma = -1e9 ;
	if(m == 1){
		for(int i = 1;i <= n;i++){
			ma = max(ma,a[i]) ;
		}
	}else if(m == 2){
		for(int i = 1;i < n;i++){
			for(int j = i+1;j <= n;j++){
				int x = a[i] & a[j] ;
				ma = max(ma,x) ;
			}
		}
	}else if(m == 2){
		for(int i = 1;i < n-1;i++){
			for(int j = i+1;j < n;j++){
				for(int k = j+1;k <= n;k++){
					int x = a[i] & a[j] & a[k] ;
				ma = max(ma,x) ;
				}
			}
			}
		}
	cout << ma ;
	return 0 ;
}
