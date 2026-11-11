#include <bits/stdc++.h>
using namespace std;
string s1,s2,s3,s4;
string a="",b="";
char c,d;
int main () {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1>>s2>>s3>>s4;
	a=s2[0]+s2[1];
	b=s4[0]+s4[1];
	c=s2[2];
	d=s4[2];
	if (s1==s3) cout<<"1";
	else{
		cout<<"0000";
		return 0;
	}
	if (a==b) cout<<"1";
	else{
		cout<<"000";
		return 0;
	}
	if ((c<='C' && d<='C') || (c>='D' && d>='D')) cout<<"1";
	else {
		cout<<"00";
		return 0;
	}
	if (abs(int(c)-int(d))==1) cout<<"1";
	else cout<<"0";
	return 0;
}
