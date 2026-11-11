//GZ-J00456 遵义市第十一中学 刘慕莀
#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a;
	string b;
	int c,d;
	cin>>c>>a>>d>>b;
	if(c==d) {
		cout<<"1";
	} else {
		cout<<"0";
	}
	if(a[0]*10+a[1]==b[0]*10+b[1]&&c==d) {
		cout<<"1";
	} else {
		cout<<"0";
	}
	if((a[2]=='A'||a[2]=='B'||a[2]=='C')&&(b[2]=='A'||b[2]=='B'||b[2]=='C')&&c==d&&a[0]*10+a[1]==b[0]*10+b[1]) {
		cout<<"1";
	} else if((a[2]=='D'||a[2]=='F')&&(b[2]=='D'||b[2]=='F')&&c==d&&a[0]*10+a[1]==b[0]*10+b[1]) {
		cout<<"1";
	} else {
		cout<<"0";
	}
	if((a[2]=='A'&&b[2]=='B')||(a[2]=='B'&&(b[2]=='A'||b[2]=='C'))||(a[2]=='C'&&b[2]=='B')||(a[2]=='D'&&b[2]=='F')||(a[2]=='F'&&b[2]=='D')&&(a[2]=='A'||a[2]=='B'||a[2]=='C')&&(b[2]=='A'||b[2]=='B'||b[2]=='C')&&c==d&&a[0]*10+a[1]==b[0]*10+b[1]) {
				cout<<"1";
			} else {
				cout<<"0";
			}
	return 0;
}
