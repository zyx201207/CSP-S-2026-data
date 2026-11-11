#include<bits/stdc++.h>
using namespace std;
string ans;
char c1,c2,num1,num2,num3,num4,num5,num6,num7,num8;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>num1>>num2>>num3>>num4>>c1>>num5>>num6>>num7>>num8>>c2;
	int n1=(num1-'0')*10+(num2-'0'),n2=(num5-'0')*10+(num6-'0');
	if(n1==n2&&n1!=1&&n2!=16)ans+="1";
	else ans+="0";
	int n3=(num3-'0')*10+(num4-'0'),n4=(num7-'0')*10+(num8-'0');
	if((n3==n4&&n3>=1&&n4<=18&&n3>=1&&n4<=18)&&(n1==n2&&n1!=1&&n2!=16))ans+="1";
	else ans+="0";
	if((n3==n4&&n3>=1&&n4<=18&&n3>=1&&n4<=18)&&(n1==n2&&n1!=1&&n2!=16)&&(((c1>='A'&&c1<='C')&&(c2>='A'&&c2<='C'))||((c1>='D'&&c1<='F')&&(c2>='D'&&c2<='F'))))ans+="1";
	else ans+="0";
	if(((c1=='A'&&c2=='B')||(c2=='A'&&c1=='B')||(c1=='B'&&c2=='C')||(c2=='B'&&c1=='C')||(c1=='D'&&c2=='F')||(c2=='D'&&c1=='F'))&&(n3==n4&&n3>=1&&n4<=18&&n3>=1&&n4<=18)&&(n1==n2&&n1!=1&&n2!=16)&&(((c1>='A'&&c1<='C')&&(c2>='A'&&c2<='C'))||((c1>='D'&&c1<='F')&&(c2>='D'&&c2<='F'))))ans+="1";
	else ans+="0";
	cout<<ans;
	return 0;
}
