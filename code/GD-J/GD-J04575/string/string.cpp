#include <bits/stdc++.h>
using namespace std ;
int main(){
	freopen("string.in" , "r" , stdin) ;
	freopen("string.out" , "w" , stdout) ;
	long long n , a[200005] , cnt = 0 , sum = 0 ;
	char s[200005] ;
	char d ;
	bool f = 0 ;
	cin >> n ;
	for(int i = 1;i <= n;i++){
		cin >> a[i] >> s[i] ;
		sum += a[i] ;
		if(i == 1) d = s[i] ;
		if(d != s[i]) f = 1 ;
	}
	string c = "" ;
	if(f == 0){
		cout << 0 ;
		return 0 ;
	}else{
		for(int i = 1;i <= n/2;i++){
			int j = n-i+1 ;
			if(s[i] == s[j]){
				cnt += abs(a[i]-a[j]) ;
				for(int k = 1;k <= abs(a[i]-a[j]);k++) c += s[i] ;
			}else{
				cnt += (a[i]+a[j])/2 ;
				if(a[i] > a[j]) for(int k = 1;k <= a[i]-a[j];k++) c += s[i] ;
				if(a[i] < a[j]) for(int k = 1;k <= a[j]-a[i];k++) c += s[j] ;
			}
		}
	}
	int m = c.size() ;
	for(int i = 0;i < m/2;i++){
		for(int j = m;j > m/2;j++){
			if(c[i] != c[j]){
				cnt++ ;
			}
		}
	}
	cout << cnt ;
	return 0 ;
}
