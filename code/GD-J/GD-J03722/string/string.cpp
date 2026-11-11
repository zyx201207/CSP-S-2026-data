#include<bits/stdc++.h>
using namespace std ;
const unsigned long long N = 2e5 + 5 ;
struct q {
	unsigned long long num ;
	char c ; 
}a[N]; 
int main(){
	freopen("string.in" , "r" , stdin) ;
	freopen("string.out" , "w" , stdout) ;
	unsigned long long n ;
	cin >> n ;
	for(unsigned long long i =  1; i <= n ; i ++){
		cin >> a[i].num >> a[i].c ; 
	}
	unsigned long long cnt = 0;
	unsigned long long l = 0 , r = n ;
	while(l < r){
		unsigned long long p = min(a[l].num , a[r].num);
		a[l].num -= p ;
		a[r].num -= p ;
		if(a[l].c != a[r].c){
			cnt += p ;
		}
		if(a[l].num == 0){
			l ++ ;
		}
		if(a[r].num == 0){
			r -- ;
		}	
	}
	cout << cnt ;
	return 0 ;
} 
