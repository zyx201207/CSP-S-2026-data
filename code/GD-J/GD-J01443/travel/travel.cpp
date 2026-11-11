#include <bits/stdc++.h>
#define int long long
using namespace std ;
using ll = long long ;
string c1 , s1 , c2 , s2 ;
signed main() {
	freopen("travel.in" , "r" , stdin) ;
	freopen("travel.out" , "w" , stdout) ;
	cin.tie(nullptr) -> ios :: sync_with_stdio(false) ;
	cin >> c1 >> s1 >> c2 >> s2 ;
	bool flag1 , flag = (c1 == c2) ;
	cout << flag ;
	if(!flag) cout << "000" ;
	else {
		flag = ((s1[0] == s2[0]) && (s1[1] == s2[1])) ;
		cout << flag ;
		if(!flag) cout << "00" ;
		else {
			flag = (s1[2] <= 'C' && s2[2] <= 'C') ;
			flag1 = (s1[2] > 'C' && s2[2] > 'C') ;
			cout << (flag || flag1) ;
			if(!(flag || flag1)) cout << 0 ;
			else if(flag1) cout << 1 ;
			else {
				vector <int> a(4) ;
				a[s1[2] - 'A'] ++ ;
				a[s2[2] - 'A'] ++ ;
				if((a[0] == 1 && a[1] == 1) || (a[1] == 1 && a[2] == 1)) cout << 1 ;
				else cout << 0 ;
			}
		}
	}
	return 0 ;
}
