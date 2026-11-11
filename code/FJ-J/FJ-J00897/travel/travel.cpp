#include <bits/stdc++.h>
using namespace std ;
string rc, rs, xc, xs ;
string ans = "0000" ;
int main(){
	freopen("travel.in", "r", stdin) ;
	freopen("travel.out", "w", stdout) ;
	cin >> rc >> rs >> xc >> xs ; 
	if(rc == xc){
		ans[0] = '1' ;
		int idr = (rs[0] - '0') * 10 + rs[1] - '0' ;
		int idx = (xs[0] - '0') * 10 + xs[1] - '0' ;
		if(idr == idx){
			ans[1] = '1' ;
			char pr = rs[2], px = xs[2] ;
			if((pr >= 'D' && px >= 'D') || (pr < 'D' && px < 'D')){
				ans[2] = '1' ;
				if(pr == char(px + 1) || pr == char(px - 1)) ans[3] = '1' ;
			}
		}
	}
	cout << ans << "\n" ;
	return 0 ;
} 
