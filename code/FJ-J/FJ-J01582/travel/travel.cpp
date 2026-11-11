#include<bits/stdc++.h>
using namespace std;
int bh(char a) {
	if(int(a)<'D') return 1;
	return 0;
}
bool check(char a,char b) {
	return (a=='A'&&b=='C')||(a=='C'&&b=='A');
}
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,s2,c1,c2;
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2) {
		cout<<"0000";
		return 0;
	}
	cout<<"1";
	if(s1[0]!=s2[0]||s1[1]!=s2[1]) {
		cout<<"000";
		return 0;
	}
	cout<<"1";
	int bh1,bh2;
	bh1=bh(s1[2]),bh2=bh(s2[2]);
	if(bh1!=bh2) {
		cout<<"00";
		return 0;
	}
	cout<<"1";
	if(bh1==bh2&&bh1==0) {
		cout<<"1";
		return 0;
	}
	if(check(s1[2],s2[2])) {
		cout<<"0";
		return 0;
	}
	cout<<"1";
	return 0;
}

