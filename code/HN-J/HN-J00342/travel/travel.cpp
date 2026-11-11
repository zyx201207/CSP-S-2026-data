#include <bits/stdc++.h>
using namespace std; 

int main(){
	
	freopen(travel.in,'r',stdin);
	freopen(travel.out,'w',stdout);
	int a,b;
	char q[4],p[4];
	cin >> a >> q >> b >> p; 
	bool vis = true;
	if (a == b) {
		;
	}else {
		cout << "0000" << endl;
		return 0;
	}
	
	if (q[0] == p[0]&&q[1] == p[1]) {
		;
	}else {
		cout << "1000" << endl;
	return 0;
	}
	
	if ((q[2] < 'D'&&p[2] < 'D')||(q[2] >='D'&&p[2] >= 'D')) {
		;
	}
	else {
		cout << "1100" << endl;
		return 0;
	}
	
	if ((q[2] + 1 == p[2]||q[2] - 1 == p[2])) {
		;
	}else {
		cout << "1110" << endl;
		return 0;
	}
	
	cout << "1111" << endl;
	return 0;
}
