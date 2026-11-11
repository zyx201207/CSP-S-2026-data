#include <bits/stdc++.h>
using namespace std ;

int c1, c2;
string s1, s2 ;

bool check(string a, string b){//是否在同一侧 
	if(((a[2] <= 'C') && (b[2] <= 'C')) || ((a[2] >= 'D') && (b[2] >= 'D'))){
		return 1 ;
	}return 0 ;
}

bool ch2 (string a, string b){//是否相邻 
	if(((abs(a[2] - b[2])) == 1) || ((a[2] == 'D') && (b[2] == 'F')) || (a[2] == 'F') && (b[2] == 'D')){
		return 1;
	}return 0;
}

int main (){
	ios_base::sync_with_stdio(0) ;
	cin.tie();
	cout.tie();
	
	freopen("travel.in", "r", stdin) ;
	freopen("travel.out", "w", stdout) ;
	
	cin >> c1 >> s1 >> c2 >> s2 ;
	
	if(c1 != c2){
		cout << "0000";
		return 0 ;
	}else if((s1[0] != s2[0]) || (s1[1] != s2[1])){
		cout << "1000" ;
		return 0;
	}else if(!check(s1, s2)){
		cout << "1100" ;
		return 0 ;
	}else if(!ch2(s1, s2)){
		cout << "1110" ;
		return 0;
	}else cout << "1111" ;
	
	return 0 ;
}
