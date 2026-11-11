#include <bits/stdc++.h>
using namespace std;

string c1,s1,c2,s2;

int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	cin >> c1 >> s1 >> c2 >> s2;	
	char x = s1[0];
	char y = s2[0];
	char c = s1[1], d = s2[1];
	char seat = x + c;
	char seat1 = y + d;
	char a = s1[2], b = s2[2];
	bool flag = 0;
	
	if(c1 == c2) {
		cout << "1";
		
		if(seat == seat1) {
			cout << "1";
			if(a == 'C' && b == 'D' || a == 'D' && b == 'C') {
				cout << "00";
				flag = 1;				
			} else {
				cout << "1";	
				if((a + 1 == b || a - 1 == b) && !flag) { //xianglin		
					cout << "1";
				} else {
					cout << "0";
				}	
			}
		} else cout << "000";	
	} else cout << "0000";
		
	return 0;
} 
