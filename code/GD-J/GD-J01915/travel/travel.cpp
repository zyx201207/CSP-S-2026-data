#include <bits/stdc++.h>
using namespace std ;

bool ton [5] = {} ;

int to_pos (char temp){
	if (temp == 'F')
		return 4 ;
	return temp-'A' ;
}

int main() {
	
	freopen ("travel.in","r",stdin) ;
	freopen ("travel.out","w",stdout) ;
	
	string a_boxPos , b_boxPos , a_pos , b_pos ;
	cin >>  a_boxPos >> a_pos >> b_boxPos >> b_pos ;
	
	string ans = "" ;
	if (a_boxPos==b_boxPos)
		ans += '1' ;
	else
		ans += '0' ;
	
	if ((a_pos[0]==b_pos[0])&&(a_pos[1]==b_pos[1]))
		ans += '1' ;
	else
		ans += '0' ;
	
	ton[to_pos(a_pos[2])] = true ;
	ton[to_pos(b_pos[2])] = true ;
	
	if ((ton[0]&&(ton[1]||ton[2]))||(ton[4]&&ton[3]))
		ans += '1' ;
	else
		ans += '0' ;
	
	for (int i = 0 ; i < 4 ; i++){
		if (i==2)
			i++ ;
		
		if (ton[i]&&ton[i+1]){
			cout << ans << "1" ;
			return 0 ;
		}
	}
	
	ans += "0" ;
	cout << ans ;
	
	return 0 ;
}
