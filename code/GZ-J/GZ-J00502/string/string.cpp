//GZ-J00502 ³ÂÜÆÝæ 
#include <bits/stdc++.h>
using namespace std ;
int n,cnt ;
string s ;
int main(){
	freopen("string.in" , "r" , stdin) ;
	freopen("string.out" , "w" , stdout) ;
	cin >> n ;
	while(n--){
		int a ;
		string b ;
		cin >> a >> b ;
		for(int i = 1 ; i <= a ; i++){
			s += b ;
		}
	}
	for(int i = s.size() ; i > 0 ; i++){
		int f = 1 ;
		for(int j = 0 ; j < s.size() ; j++){
			if(s[i] == s[j]){
				f = 1 ;
			}
			else{
				f = 0 ;
				s[j] = s[i] ;
				cnt++ ;
			}
		}
		if(f == 1){
			cout << 0 ;
			return 0 ;
		}
	}
	cout << cnt ;
	return 0 ;
}
