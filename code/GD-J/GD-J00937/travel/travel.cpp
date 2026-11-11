#include<iostream>
#include<cstdio>
#include<cmath>
#define ll long long
#define si short int
using namespace std;
string c1,s1,c2,s2;
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) {
		cout<<'1';
		if(s1[0]==s2[0] && s1[1]==s2[1]) {
			cout<<'1';
			char x1=s1[2],x2=s2[2];
			if((x1<='C')==(x2<='C')) {
				cout<<'1'<<(abs(x1-x2)==1);
			}
			else cout<<"00"; 
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}

/*
02 01A 02 01B   1111
02 01C 02 01A   1110
02 01C 02 01D   1100
02 02B 02 01A   1000
02 01A 03 01A   0000
*/
