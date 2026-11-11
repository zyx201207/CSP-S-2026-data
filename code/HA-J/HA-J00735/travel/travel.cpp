#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)cout<<"1";
	else return cout<<"0000",0;
	int n1=(s1[0]-'0')*10+s1[1]-'0';
	int n2=(s2[0]-'0')*10+s2[1]-'0';
	if(n1==n2)cout<<"1";
	else return cout<<"000",0;
	if(s1[2]>='A'&&s1[2]<='C'&&s2[2]>='A'&&s2[2]<='C'){
		cout<<"1";
	}
	else if(s1[2]>='D'&&s1[2]<='F'&&s2[2]>='D'&&s2[2]<='F'){
		return cout<<"11",0;
	}
	else return cout<<"00",0;
	if(s1[2]=='A'&&s2[2]=='B')cout<<"1";
	else if(s1[2]=='B'&&s2[2]<'D')cout<<"1";
	else if(s1[2]=='C'&&s2[2]=='B')cout<<"1";
	else cout<<"0";
	return 0;
}
