#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
int main() {
	freopen("travel.in","r","stdin");
	freopen("travel.out","w","stdout");
	cin>>c1>>s1>>c2>>s2;
	int flag=0;
	if(c1==c2) {//chexiang
		cout<<"1a";
	} else cout<<"0000";

	if(c1==c2 && s1[0]==s2[0] && s1[1]==s2[1]) {//paishu
		cout<<"1b";
	} else cout<<"0";

	if(c1==c1 && s1[0]==s2[0] && s1[1]==s2[1]) {
		int a='A',b='B',c='C',d='D',f='F';//tongyice
		if(s1[2]>'C' && s2[2]>'C') cout<<"1c";
		else if(s1[2]<='C' && s2[2]<='C') cout<<"1d";
	} else cout<<"00";

	if(c1==c1 && s1[0]==s2[0] && s1[1]==s2[1]) {
		if(s1[2]=='A' && s2[2]=='B') {//xianglin
			cout<<"1A";
		} else if(s1[2]=='B' && s2[2]=='A' || s2[2]=='C') {
			cout<<"1B";
		} else if(s1[2]=='C' && s2[2]=='B') {
			cout<<"1C";
		} else if(s1[2]=='D' && s2[2]=='F') {
			cout<<"1D";
		} else if(s1[2]=='F' && s2[2]=='D') {
			cout<<"1F";
		}
	}
	return 0;
}
