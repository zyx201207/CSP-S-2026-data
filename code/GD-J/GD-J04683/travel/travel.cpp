#include <bits/stdc++.h>
using namespace std ;
string s1 , s2 , a1 , a2 ;

int main () {
	freopen ("travel.in","r",stdin) ;
	freopen ("travel.out","w",stdout) ; 
	
	ios::sync_with_stdio (false) ;
	cin.tie(0) , cout.tie(0) ; 
	
	cin >> s1 >> a1 >> s2 >> a2 ;
	
	if (s1 == s2 && (s1 != "01" || s1 != "16")) {
		cout << "1" ;
	} else {
		cout << "0" ;
	}
	
	if  (s1 == s2 && (s1 != "01" || s1 != "16")) {
		if (a1[0] == a2[0] && a1[1] == a2[1]) {
			cout << "1" ;
		}  else {
			cout << "0" ;
		}
	} else cout << "0" ;
	
	
	if  (s1 == s2 && (s1 != "01" || s1 != "16")) {
		if (a1[0] == a2[0] && a1[1] == a2[1]){
			if ((a1[2] <= 'C' && a2[2] <= 'C') || (a1[2] >= 'D' && a2[2] >= 'D')) cout << "1" ;
			else cout << "0" ;
 		}else cout << "0" ; 
	} else cout << "0" ;

	
	
	if (s1 == s2 && (s1 != "01" || s1 != "16")) {
		if (a1[0] == a2[0] && a1[1] == a2[1]) {
			if ((a1[2] <= 'C' && a2[2] <= 'C') || (a1[2] >= 'D' && a2[2] >= 'D')) {
				if (a1[2] + 1 == a2[2] || a1[2] - 1 == a2[2]) cout << "1" ;
				else cout << "0" ;
			}
			else cout << "0" ;
		}
		else cout << "0" ;
	}else {
		cout << "0" ;
	}
	
	
	return 0 ;
} 
