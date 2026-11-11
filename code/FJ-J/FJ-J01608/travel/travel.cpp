#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2,x1,x2;
	cin>>c1>>x1>>c2>>x2;
	if(c1==c2) {
		cout<<"1";
	} else {
		cout<<"0000";
		return 0;
	}
	if(x1[0]==x2[0]&&x1[1]==x2[1]) {
		cout<<"1";
	} else {
		cout<<"000";
		return 0;
	}
	if(x1[2]>='A'&&x1[2]<='c'&&x2[2]>='A'&&x2[2]<='C') {
		cout<<"1";
	} else {
		if(x1[2]>='D'&&x1[2]<='F'&&x2[2]>='D'&&x2[2]<='F') {
			cout<<"1";
		} else {
			cout<<"00";
			return 0;
		}
	}
	if(x1[2]=='D') {
		if(x2[2]=='F') {
			cout<<"1";
		} else {
			cout<<"0";
			return 0;
		}
	} else {
		if(x1[2]=='F') {
			if(x2[2]=='D') {
				cout<<"1";
			} else {
				cout<<"0";
				return 0;
			}
		}
	}
	if(x1[2]=='B'||x2[2]=='B') {
		cout<<"1";
	} else {
		cout<<"0";
	}
	return 0;
}
