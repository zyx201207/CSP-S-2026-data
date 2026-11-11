#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,a2,b,b2;
	cin>>a>>a2>>b>>b2;
	bool yyy=true;
	if(yyy&&a==b) {
		cout<<1;
	} else {
		cout<<0;
		yyy=false;
	}
	if(yyy&&a2[0]==b2[0]&&a2[1]==b2[1]) {
		cout<<1;
	} else {
		cout<<0;
		yyy=false;
	}
	if(yyy&&((a2[2]<='C'&&b2[2]<='C')||(a2[2]>'C'&&b2[2]>'C'))) {
		cout<<1;
	} else {
		cout<<0;
		yyy=false;
	}
	if(yyy&&((max(a2[2],b2[2])-min(a2[2],b2[2])==1&&max(a2[2],b2[2])!='D')||(min(a2[2],b2[2])=='D'&&max(a2[2],b2[2])=='F'))) {
		cout<<1;
	} else {
		cout<<0;
		yyy=false;
	}
}
