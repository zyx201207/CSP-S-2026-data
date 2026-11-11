#include<bits/stdc++.h>
using namespace std ;
int n , m ;
const int maxn = 200010 ;
long long a[maxn] ;
bool cmp(long long a , long long b) {fn
	return a > b ;
}
int main(){
	freopen("and.in" , "r" , stdin) ;
	freopen("and.out" , "w" , stdout) ;
	ios::sync_with_stdio(false) ;
	cin.tie(0) ;
	cin >> n >> m ;
	int f = 0 , big = 0 , small , d ;
	for(int i = 1 ; i <= n ; i ++){
		cin >> a[i] ;
		if(i == 1) {
			f = a[1] ;
			small = a[1] ;
		}
		if(m == n){
			f = f & a[i] ;
		}
		if(a[i] > big){
			big = a[i] ;
		}
		if(a[i] < small){
			small = a[i] ;
		}
	}
	bool flag = true ;
	if(m == n - 1) {
		for(int i = 1 ; i <= n ; i ++){
			if(a[i] == small && flag){
				flag = false ;
				continue ;
			}else {
				
			}
		}
	}
	bool t = true ;
	for(int i = 1 ; i <= n ; i ++){
		if(small = a[i] && t) {
			t = false ;
		}else {
			d = d & a[i] ;
		}
		cout << d ;
		return 0 ;
	}
	if(m == n) {
		cout << f ;
		return 0 ;
	}
	if(m == 1) {
		cout << big ;
		return 0 ;
	}
	sort(a+1 , a+1+n , cmp) ;
	int l = a[1] ;
	for(int i = 2 ; i <= m ; i ++){
		l = l & a[i] ;
	}
	cout << l ;
	return 0 ;
}
