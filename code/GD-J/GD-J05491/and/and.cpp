#include<bits/stdc++.h>
using namespace std ;

int a[200005] , b[200005] ;

int main(){
	freopen("and.in" , "r" , stdin) ;
	freopen("and.out" , "W" , stdout) ;
	
	int max = 0 ;
	int n , m ;
	cin >> n , m ;
	for(int i = 1 ; i <= n ; i++){
		cin >> a[i] ;
	}
	for(int i = 1 ; i <= n ; i++){
		cout << a[i] << " " ;
	}
	
	if(m == 1){
		for(int i = 1 ; i <= n ; i++){
			if(max <= a[i]){
				max = a[i] ;
			}
		}
	}else if(m == 2){
		for(int i = 1 ; i <= n ; i++){
			b[i] == 1 ;
			for(int j = 1 ; i <= n ; j++){
				if(max <= a[i] & a[j] && a[j] != 1){
					max = a[i] & a[j] ;
					cout << a[i] << " " << a[j] << endl ;
				}
			}
			b[i] = 0 ;
		}
	}
	cout << max ;
	return 0 ;
}  
//4 2
//3 15 12 12

