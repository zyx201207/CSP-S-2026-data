#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	char a=s1[0],b=s1[1],n=s1[2];
	char a1=s2[0],b1=s2[1],n1=s2[2];
	if(c1==c2)
	{
		cout<<"1";
	}else
	{
		cout<<"0000";
		return 0;
	}
	if(a==a1&&b==b1)
	{
		cout<<"1";		
	}else
	{
		cout<<"000";
		return 0;
	}
	if((n<='C'&&n1<='C')||(n>='D'&&n1>='D'))
	{
		cout<<"1";
	}else
	{
		cout<<"0";
	}	
	if((char)(n+1)==n1)
	{
		cout<<"1";
	}else
	{
		cout<<"0";
	}
	return 0;
} 
