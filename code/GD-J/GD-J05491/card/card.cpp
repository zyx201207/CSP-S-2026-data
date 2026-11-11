#include<bits/stdc++.h>
using namespace std ;
string a[300005] , b[300005] , c[300005] , s[300005];
int main(){
	freopen("card.in" , "r" , stdin) ;
	freopen("card.out" , "W" , stdout) ;
	
	int n , m ;
	cin >> n >> m ;
	for(int i = 0 ; i < n ; i++){
		cin >> a[i] ;
		c[i] = a[i] ;
	}
	
	int ju = 0 ;
	while(ju == n){
		for(int  i = 0 ; i < m ; i++){
			b[i] = "" ;
			a[i] = c[i] ;
		}
		int d = ju ;
		while(a){
			for(int i = 0 ; i < n ; i++){
				if(b[i] == a[i]){
					b[i] = b[i] ;
				}else{
					b[i] = b + a[d] ;
				}
			}
			d += 1 ;
		}
		for(int i = 0 ; i < n ; i++){
			s[i] += 1 ;
		}
		ju += 1 ;
	}
	
	for(int i = 0 ; i < n ; i++){
		cout << s[c[i]] << " " ; 
	}
	return 0 ;
}  

