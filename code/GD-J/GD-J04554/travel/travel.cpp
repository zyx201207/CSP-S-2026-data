#include <bits/stdc++.h>;
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen{"travel.in","r","stdin"};
	freopen{"travel.out","w","stdout"};
	if(c1==c2)
		cout<<'1';
	else
		cout<<'0';
	if(s1==s2)
		cout<<'1';
	else
		cout<<'0';
	if((s1[3]=='A'||s1[3]=='B'||s1[3]=='C')&&(s2[3]=='A'||s2[3]=='B'||s2[3]=='C'))
		cout<<'1';
	else if((s1[3]=='D'||s1[3]=='F')&&(s2[3]=='D'||s2[3]=='F'))
		cout<<'1';
	else
		cout<<'0';
	if(s1[3]-s2[3]==1||s2[3]-s1[3]==1)
		cout<<'1';
	else
		cout<<'0';
	return 0;
}
