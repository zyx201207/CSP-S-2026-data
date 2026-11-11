#include<bits/stdc++.h>
using namespace std;

string Rc,Rs,Xc,Xs;

int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>Rc>>Rs>>Xc>>Xs;
	if(Rc==Xc) {
		cout<<"1";
	} else {
		cout<<"0000";
		return 0;
	}
	if(Rs[0]==Xs[0]&&Rs[1]==Xs[1]) {
		cout<<"1";
	} else {
		cout<<"000";
		return 0;
	}
	if(Rs[2]<='C'&&Rs[2]>='A'&&Xs[2]<='C'&&Xs[2]>='A') {
		cout<<"1";
		if(Rs[2]=='C'&&Xs[2]=='A'||Rs[2]=='A'&&Xs[2]=='C') {
			cout<<"0";
		} else {
			cout<<"1";
		}
	} else if(Rs[2]<='F'&&Rs[2]>='E'&&Rs[2]<='F'&&Rs[2]>='E') {
		cout<<"11";
		return 0;
	}else {
		cout<<"00";
	}

return 0;
}
