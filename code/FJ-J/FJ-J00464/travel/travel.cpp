#include<bits/stdc++.h>
using namespace std;
string S1,C1,S2,C2;
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout); 
	cin >> C1 >> S1 >> C2 >> S2;
	if(C1==C2) {
		cout << "1";
	} else {
		cout << "0000";
		return 0;
	}
	if(S1[0]==S2[0]&&S1[1]==S2[1]) {
		cout << "1";
	} else {
		cout << "000";
		return 0;
	}
	if((S1[2]<='C'&&S2[2]<='C')||(S1[2]>='D'&&S2[2]>='D')) {
		cout << "1";
	} else {
		cout << "00";
		return 0;
	}

	if(abs(int(S1[2])-int(S2[2]))==1) {
		cout << "1";
	} else {
		cout << "0";
		return 0;
	}
	return 0;
}
