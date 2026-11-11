#include<bits/stdc++.h>
using namespace std;
string a1,a2,b1,b2;
int a,b,a4,b4;
int a3,b3;
bool ak=false;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a1>>a2>>b1>>b2;
	a4=(a1[0]-'0')*10+a1[1]-'0';
	b4=(b1[0]-'0')*10+b1[1]-'0';
	a=(a2[0]-'0')*10+a2[1]-'0';
	b=(b2[0]-'0')*10+b2[1]-'0';
	a3=a2[2]-'A'+1;
	b3=b2[2]-'A'+1;
	if(a4==b4)
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	if(a==b&&a4==b4)
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	if((a3>=1&&a3<=3&&b3>=1&&b3<=3&&a==b&&a4==b4)||(a3>=4&&a3<=5&&b3>=4&&b3<=5&&a==b&&a4==b4))
	{
		ak=true;
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	if(ak==true&&abs(a3-b3)==1)
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	return 0;
}
