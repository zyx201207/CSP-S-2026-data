#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    string li[1005];
    string tr = "ABCDF";
   	cin >> li[0] >>li[1] >> li[2] >> li[3];
	if (li[0]==li[2]) {
		cout << 1;
	} else cout << '0';
	
	if ((li[1][0]==li[3][0] && li[1][1]==li[3][1]) && (li[1][2]!=li[3][2])) {
		cout << '1';
	} else cout << '0';
	
	if ((li[1][0]==li[3][0] && li[1][1]==li[3][1]) && (li[1][2]!=li[3][2])) {
		if (li[1][2]>='A' && li[3][2]<='C') {
			cout << '1';
		} else if ((li[1][2]=='D' && li[3][2]=='F') || (li[1][2]=='F' && li[3][2]=='D')) {
			cout << '1';
		} else cout << '0';
	} else cout << '0';
	
	if ((li[1][2]+1==li[3][2] && li[1][2]>='A' && li[3][2]<='C' && li[3][2]>='A' && li[1][2] <= 'C')) {
		cout << '1';
	} else if ((li[1][2]=='D' && li[3][2]=='F') || (li[1][2]=='F' && li[3][2]=='D')) {
		cout << '1';
	} else cout << '0';
    
    return 0;
}
