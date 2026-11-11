#include <bits/stdc++.h>
using namespace std ;
int main(){
	freopen("and.in","r",stdin) ;
	freopen("and.out","w",stdout) ;
	int n , m ;
	cin >> n >> m ;
	int a[300000] = {0}, q[300000] = {0};
	for(int i = 1 ; i <= n ; i++){
		cin >> a[i] ;
	}
	q[1] = a[1] ;
	int ma = -1 ;
	for(int i = 2 ; i <= n ; i++){
		ma = max(a[i] , ma) ;
		q[i] = q[i - 1] & a[i] ;
	}
	if(m == n){
		cout << q[n] << endl ;
		return 0 ;
	}else if(m == 1){
		cout << ma << endl ;
		return 0 ;
	}else if(m == 2){
		int l = -1 ;
		for(int i = 1 ; i <= n ; i++){
			for(int j = i ; j <= n ; j++){
				l = max((a[i] & a[j]) , l) ;
			}
		}
		cout << l << endl ;
	}
	return 0 ;
}
