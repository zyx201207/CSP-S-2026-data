#include <bits/stdc++.h>
using namespace std ;

int main ()
{
	freopen("travel.in" , "r" , stdin) ;
	freopen("travel.out" , "w" , stdout) ;
	string c1 , s1 , c2 , s2 ;
	cin >> c1 >> s1 >> c2 >> s2 ;
	if ((int)c1[0] == (int)c2[0] && (int)c1[1] == (int)c2[1]) {
		cout << "1" ;
		if ((int)s1[0] == (int)s2[0] && (int)s1[1] == (int)s2[1]) {
			cout << "1" ;
			if ((s1[2] <= 'C' && s2[2] <= 'C') || (s1[2] >= 'D' && s2[2] >= 'D')) {
				cout << "1" ;
				if (abs(s1[2] - s2[2]) == 1) {
					cout << "1" ;
				}
				else cout << "0" ;
			}
			else cout << "00" ;
		}
		else cout << "000" ;
	}
	else cout << "0000" ;
	
	return 0 ;
}
