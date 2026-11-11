#include<bits/stdc++.h>
using namespace std;
string cr,cx;
string sr,sx;
string f[]= {"FD","DF","AB","BA","BC","CB","CA","AC"};
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>cr>>cx>>sr>>sx;
	string a=cx.substr(0,2);
	string b=sx.substr(0,2);
	char c=cx[2];
	char d=sx[2];
	string q=cx.substr(2,1)+sx.substr(2,1);
	bool qwq=true;
	for(int i=0; i<8; i++) {
		if(q==f[i]) {
			qwq=0;
			break;
		}
	}
	if(cr==sr) {
		cout<<'1';
		//
		if(a==b) {
			cout<<'1';
		} else {
			cout<<'0';
		}
		//
		if(a==b&&qwq) {
			cout<<'1';
		} else {
			cout<<'0';
		}
		//
		if((c==(d+1)||c==(d-1))&&!(q=="CD"||q=="DC")&&a==b) {
			cout<<'1';
		} else {
			cout<<'0';
		}
	} else {
		cout<<"000";
		if((c==(d+1)||c==(d-1))&&!(q=="CD"||q=="DC")&&qwq==false) {
			cout<<'1';
		} else {
			cout<<'0';
		}
	}
	return 0;
}
