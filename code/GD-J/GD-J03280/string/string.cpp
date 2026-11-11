#include <bits/stdc++.h>
using namespace std ;

int n ;
int a ;
char c;
string s;


int main (){
	ios_base::sync_with_stdio(0) ;
	cin.tie();
	cout.tie();
	
	freopen("string.in", "r", stdin) ;
	freopen("string.out", "w", stdout) ;
	
	cin >> n ;
	for(int i = 1; i <= n; i++){
		cin >> a >> c ;
		for(int i = 1; i <= a; i ++){
			s += c ;
		}
	}
	int cnt = 0 ;
	
	for(int i = 0, j = s.size() - 1; i <= j; i ++, j --){
		if(s[i] != s[j])cnt ++ ;
	}cout << cnt ;
	return 0 ;
}
