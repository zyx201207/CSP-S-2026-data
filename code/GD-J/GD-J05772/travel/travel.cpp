#include<bits/stdc++.h>
using namespace std;
string s1,s2,s3,s4,ss2,ss4,ss3;
stringstream ss;
long long q1,q2;
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1>>s2>>s3>>s4;
	ss2=s2.substr(0,2);
	ss4=s4.substr(0,2);
	if(s1==s3) {
		cout<<1;
	}
	else {
		cout<<"0000";
		return 0;
	}
	if(ss2==ss4) {
		cout<<1;
	}
	else {
		cout<<"000";
		return 0;
	}
	if(s2[2]<='C'&&s4[2]<='C'||s2[2]>'C'&&s2[2]>'C') {
		cout<<1;
	}
	else {
		cout<<"00";
		return 0;
	}
	if(s2[2]+1==s4[2]||s4[2]+1==s3[2]) {
		cout<<1;
	}
	else {
		cout<<0;
	}
}
