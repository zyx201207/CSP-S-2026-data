#include<bits/stdc++.h>
using namespace std ;

string s , s1 ;

int main(){
	freopen("string.in" , "r" , stdin) ;
	freopen("string.out" , "W" , stdout) ;
	
	int n , t = 0 , sum = 0 ;
	cin >> n ;
	
	while(n--){
		int a ;
		cin >> a ;
		t += a ;
		char b ;
		cin >> b ;
		for(int i = 0 ; i < a ; i++){
			s = s + b ;
		}
	}
	
	for(int i = t/2-1 ; i >= 0 ; i--){
		s1 = s1 + s[i] ;
	}
	
	int j = 0 ;
	if(t % 2 == 1){
		for(int i = t/2+1 ; i < t ; i++){
			if(s[i] != s1[j]){
				sum += 1 ;
			}
			j += 1 ;
		}
	}
	
	cout << sum ;
	return 0 ;
}  
//3
//2 a
//2 b
//1 c

//2
//2 a
//3 a

//6
//1000000000 a
//1000000000 a
//1000000000 a
//1000000000 b
//1000000000 b
//1000000000 b

