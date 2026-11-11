#include <bits/stdc++.h>
using namespace std;
int c1,c2;
string s1,s2;
int check1(){
	return c1==c2;
}
int check2(){
	return check1() && s1[0]==s2[0] && s1[1]==s2[1];
}
int check3(){
	bool f=0;
	char a=s1[2],b=s2[2];
	if((a=='A' || a=='B' || a=='C') && (b=='A' || b=='B' || b=='C')) f=1;
	if((a=='D' || a=='F') && (b=='D' || b=='F')) f=1;
	return check2() && f;
}
int check4(){
	bool f=0;
	char a=s1[2],b=s2[2];
	if(a=='A' && b=='B' || b=='A' && a=='B' || a=='B' && b=='C' || a=='C' && b=='B' ||  a=='D' && b=='F' || a=='F' && b=='D') f=1;
	return check3() && f;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	cout << check1();
	cout << check2();
	cout << check3();
	cout << check4();
	return 0;
}
