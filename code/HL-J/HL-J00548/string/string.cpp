#include<bits/stdc++.h>
using namespace std ;
int n ;
const int maxn = 200010 ;
long long a[maxn] ;
char c[maxn] ;
string s = "" ;
int ans ;
bool hui(string s){
	int len = s.size() ;
	for(int i = 1 ; i <= len / 2 ; i ++){
		if(s[i - 1] != s[len - i]){
			return false ;
		}
	}
	return true ;
}
bool hui1(long long p[]){
	int len = n ;
	for(int i = 1 ; i <= n / 2 ; i ++){
		if(a[i] != a[n - i + 1]){
			return false ;
		}
	}
	return true ;
}
int main(){
	freopen("string.in" , "r" , stdin) ;
	freopen("string.out" , "w" , stdout) ;
	ios::sync_with_stdio(false) ;
	cin.tie(0) ;
	cin >> n ;
	memset(a , 0 , sizeof(a)) ;
	for(int i = 1 ; i <= n ; i ++){
		cin >> a[i] >> c[i] ;
		s += c[i] ;
	}
	if(hui(s) && hui1(a)) {
		cout << 0 ;
		return 0 ;
	}
	if (!hui(s)){
		int len = s.size() ;
		for(int i = 1 ; i <= n / 2 ; i ++){
			if(s[i - 1] != s[len - i]){
				ans += min(a[i] , a[n - i]) ;
			}
		}
	}
	
	cout << ans ;
	return 0 ;
}

