#include <bits/stdc++.h>
using namespace std;
bool b;
int main(){
	string s1,s2,c1,c2;
	cin>>c1>>s1>>c2>>s2;
	cout<<(c1[0]-48)*10+c1[1]-48==(c2[0]-48)*10+c2[1]-48;
	bool a=(s1[0]-48)*10+s1[1]-48==(s2[0]-48)*10+s2[1]-48;
	cout<<a;
	if((s1[2]=='B'||s1[2]=='A'||s1[2]=='C')&&(s2[2]=='B'||s2[2]=='A'||s2[2]=='C')&&a){
		cout<<1;
		b=1;
	}
	else if((s1[2]=='D'||s1[2]=='F')&&(s2[2]=='F'||s2[2]=='D')&&a){
		cout<<1;
		b=1;
	}
	else
		cout<<0;
	if((s1[2]==s2[2]+1 || s1[2]==s2[2]-1)&&b)
		cout<<1;
	else
		cout<<0;
	return 0;
}
