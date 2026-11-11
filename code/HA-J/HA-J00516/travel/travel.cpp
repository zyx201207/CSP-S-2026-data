#include<bits/stdc++.h>
using namespace std;
int c1,c2,a=0,b=0;
string s1,s2,s3="ABC",s4="DF";
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1;
	cin>>c2>>s2;
	if(c1==c2)
		cout<<1;
	else
	{
		cout<<0<<0<<0<<0;
		return 0;
	}
	if(s1[0]==s2[0])
	{
		if(s1[1]==s2[1])
			cout<<1;
		else
		{
			cout<<0<<0<<0;
			return 0;
		}
	}
	else
	{
		cout<<0<<0<<0;
		return 0;
	}
	for(int i=0;i<3;i++)
	{
		if(s1[2]==s3[i])
			a=i;
		if(s2[2]==s3[i])
			b=i;
	}
	for(int i=0;i<2;i++)
	{
		if(s1[2]==s4[i])
			a=3+i;
		if(s2[2]==s4[i])
			b=3+i;
	}
	if(a<3&&b<3)
	{
		cout<<1;
		if(b-a==1||a-b==1)
			cout<<1;
		else
			cout<<0;
	}
	else if(a>=3&&b>=3)
	{
		cout<<1;
		if(b-a==1||a-b==1)
			cout<<1;
		else
			cout<<0;
	}
	else
	{
		cout<<0<<0;
		return 0;
	}
	return 0;
}
