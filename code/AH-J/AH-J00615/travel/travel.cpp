#include<bits/stdc++.h>
using namespace std;
string a1,a2,b1,b2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a1>>a2>>b1>>b2;
	if(a1!=b1){cout<<"0000";return 0;}
	int a=(a2[0]-'0')*10+(a2[1]-'0');
	int b=(b2[0]-'0')*10+(b2[1]-'0');
	if(a!=b){cout<<"1000";return 0;}
	bool af=(a2[2]<='C'?0:1);
	bool bf=(b2[2]<='C'?0:1);
	cout<<"11";
	if(af!=bf){cout<<"00";return 0;}
	if(abs((a2[2]-'0')-(b2[2]-'0'))==1) cout<<"11";
	else if((a2[2]=='D'&&b2[2]=='F')||(a2[2]=='F'&&b2[2]=='D')) cout<<"11";
	else cout<<"10";
	return 0;}
