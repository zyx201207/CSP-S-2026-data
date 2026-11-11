#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
short whichside(string a){
	if(a[2]=='A'||a[2]=='B'||a[2]=='C') return 1;
	else return 2;
}
short whichnum(char a){
	return a-('A'-1);
}
int main()
{
	string a,b,c,d;
	cin >> a >> b >> c >> d;
	if(a==c) cout << 1; else cout << 0;
	if(b[0]==d[0]&&b[1]==d[1]) {
	       	cout<< 1;
		if(whichside(b)==whichside(d))cout << 1;else cout << 0;
	}
	else cout << "00";
	if(abs(whichnum(b[2])-whichnum(d[2]))==1)
		cout << 1;
	else
		cout << 0;
	return 0;
}
