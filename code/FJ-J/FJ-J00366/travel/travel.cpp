#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int m=0;
	int cn=0,cln=0,sn=0,sln=0;
	string c, s, cl, sl;
	cin>>c>>s>>cl>>sl;
	for(int i=0; i<c.length(); i++) {
		cln=cln*10+(cl[i]-'0');
		cn=(c[i]-'0')+cn*10;
		sln=sln*10+(sl[i]-'0');
		sn=(s[i]-'0')+sn*10;
	}
	if(cln==cn) {
		cout<<"1";
	} else {
		cout<<"0";
	}


	if(sln==sn&&cln==cn) {
		cout<<"1";
	} else {
		cout<<"0";
	}


	if(s[2]<='C'&&s[2]>='A'&&sl[2]>='A'&&sl[2]<='C'&&sln==sn&&cln==cn) {
		cout<<"1";
		m=1;
	} else if(s[2]<='F'&&s[2]>='D'&&sl[2]>='D'&&sl[2]<='F'&&sln==sn&&cln==cn) {
		cout<<"1";
		m=2;
	} else {
		cout<<"0";
	}

	if(m==1&&abs(s[2]-sl[2])==1) {
		cout<<"1";
	} else if(m==2) {
		cout<<"1";
	} else {
		cout<<"0";
	}
	return 0;
}
