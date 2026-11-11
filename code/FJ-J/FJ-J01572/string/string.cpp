#include <bits/stdc++.h>
using namespace std ;

int main(){
	freopen("string.in","r",stdin) ;
	freopen("string.out","w",stdout) ;
	long long n ;
	cin >> n ;
	string s ;
	long long len = 0 ;
	for(long long i = 1 ; i <= n  ;i++){
		long long m ;cin >> m ;
		len += m ;
		char a ;
		cin >> a ;
		for(int i = 1 ; i <= m  ;i++){
			s += a ;
		}
	}
	bool d = 0;
	if(len % 2 == 1)d = 1 ;
	len /= 2 ;
	long long g = 0 ;
	for(long long i = 0  ; i < len ; i++){
		if(s[i] != s[i + (len - i - 1) * 2 + 1] && d == 0 ){
			g++ ;
		}else if(s[i] != s[i + (len - i - 1) * 2 + 2] && d == 1 ){
			g++ ;
		}
	}
	cout << g << endl ;
	return 0 ;
}
