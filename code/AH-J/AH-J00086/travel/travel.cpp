#include<bits/stdc++.h>
#define ll long long
using namespace std;
string s1,s2,s3,s4;
bool f=0;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1>>s2>>s3>>s4;
	ll x1=(s2[0]-'0')*10+s2[1]-'0',x2=(s4[0]-'0')*10+s4[1]-'0';
	char seat1=s2[2],seat2=s4[2];
	if(s1==s3){f=1;cout<<1;}
	else cout<<0;
	if(f&&s2[0]==s4[0]&&s2[1]==s4[1])cout<<1;
	else {f=0;cout<<0;}
	if(f&&x1==x2&&((seat1>='A'&&seat1<='C'&&seat2>='A'&&seat2<='C')||(seat1>='D'&&seat1<='E'&&seat2>='D'&&seat2<='E')))cout<<1;
	else {f=0;cout<<0;}
	if(f&&abs(seat1-seat2)==1)cout<<1;
	else cout<<0;
	return 0;
}
//10 min EXP:100pts
