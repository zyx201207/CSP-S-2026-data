#include<iostream>
#include<string>
#include<cstdio>
using namespace std;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s11,s12,s21,s22;
	cin>>s11>>s12>>s21>>s22;
	if(s11!=s21) {
		cout<<"0000";
		return 0;
	} if(s12[0]!=s22[0] || s12[1]!=s22[1]) {
		cout<<"1000";
		return 0;
	} if((s12[2]<='C' && s22[2]>='D') || (s12[2]>='D' && s22[2]<='C')) {
		cout<<"1100";
		return 0;
	} if((s12[2]=='A' && s22[2]=='C') || (s12[2]=='C' && s22[2]=='A')) {
		cout<<"1110";
		return 0;
	}
	cout<<"1111";
	return 0;
} 
/*02 01A 02 01B*/
/*02 01C 02 01A*/
/*02 01C 02 01D*/
/*02 02B 02 01A*/
/*02 01A 03 01A*/
