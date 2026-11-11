#include <iostream>
#define long long ll
using namespace std;
char s1[10],s2[10];
int c1,c2;
bool ch1(char a,char b) {
	if(a=='A'||a=='B'||a=='C') {
		if(b=='A'||b=='B'||b=='C') {
			return true;
		}
	}
	if(a=='D'||a=='F') {
		if(b=='D'||b=='F') {
			return true;
		}
	}
	return false;
}
bool ch2(char a,char b) {
	if((a+1)==b||(a-1)==b) {
		return true;
	}
	return false;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) {
		cout<<1;
	}
	else {
		cout<<0;
	}
	if(c1==c2&&s1[0]==s2[0]&&s1[1]==s2[1]) {
		cout<<1;
	}
	else {
		cout<<0;
	}
	if(c1==c2&&s1[0]==s2[0]&&s1[1]==s2[1]&&ch1(s1[2],s2[2])) {
		cout<<1;
	}
	else {
		cout<<0;
	}
	if(c1==c2&&s1[0]==s2[0]&&s1[1]==s2[1]&&ch1(s1[2],s2[2])&&ch2(s1[2],s2[2])) {
		cout<<1;
	}
	else {
		cout<<0;
	}
	return 0;
}
