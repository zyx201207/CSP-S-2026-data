#include<bits/stdc++.h>
using namespace std;
string s1,z1,s2,z2;
int a1,a2;
int x1,x2,x3,x4;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1>>z1>>s2>>z2;
	if(s1==s2)
	{
		x1=1;
	}
	else x1=0;
	if(z1[0]==z2[0]&&z1[1]==z2[1])
	{
		x2=1;
	}
	else x2=0;
	if((z1[2]=='A'&&z2[2]=='B')||(z1[2]=='A'&&z2[2]=='C')||(z1[2]=='B'&&z2[2]=='C')||(z1[2]=='C'&&z2[2]=='A')||(z1[2]=='C'&&z2[2]=='B')||(z1[2]=='B'&&z2[2]=='A')||(z1[2]=='D'&&z2[2]=='F')||(z1[2]=='F'&&z2[2]=='D'))
	{
		x3=1;
	}
	else x3=0;
	if(z1[2]=='A'&&z2[2]=='B'||z1[2]=='B'&&z2[2]=='C'||z1[2]=='C'&&z2[2]=='B'||z1[2]=='B'&&z2[2]=='A'||z1[2]=='D'&&z2[2]=='F'||z1[2]=='F'&&z2[2]=='D')
	{
		x4=1;
	}
	else x4=0;
	if(x1==0)
	{
		x2=0;
		x3=0;
		x4=0;
	}
	else if(x2==0)
	{
		x3=0;
		x4=0;
	}
	else if(x3==0)
	{
		x4=0;
	}
	cout<<x1<<x2<<x3<<x4;
	return 0;
}

