#include<bits/stdc++.h>
using namespace std;
string s;
int n;
int main(){
	freopen( "string.in" , "r" , stdin );
	freopen( "string.out" , "w" , stdout );
	cin >> n;
	for( int i = 1 ; i <= n ; i++ ){
		int a; string s1;
		cin >> a >> s1;
		for( int i = 1 ; i <= a ; i++ ){
			s += s1;
		}
	}
	long long len = s.size() , ans = 0;
	for( int i = 0 ; i < len/2 ; i++ ){
		if( s[i] != s[len-1-i] ){
			ans++;
		} 
	}
	cout << ans / 2;
	return 0;
}
