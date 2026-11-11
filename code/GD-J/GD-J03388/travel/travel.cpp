#include<iostream>
#include<stdio.h>
#include<cmath>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)cout<<'1';
	else 
	{
		cout<<"0000";
		return 0;
	}
	int x=(s1[0]-'0')*10+s1[1]-'0',y=(s2[0]-'0')*10+s2[1]-'0';;
	bool b=(s1[2]-'0')/4==(s2[2]-'0')/4;
	if(x==y)
	{
		cout<<'1'<<char(b+'0');
	}
	else
	{
		cout<<"00";
	}
	if((x-y)*(x-y)==1 xor ((s1[2]-s2[2])*(s1[2]-s2[2])==1)&&b)cout<<'1';
	else cout<<'0';
	return 0;
} 
