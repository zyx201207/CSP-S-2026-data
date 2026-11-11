#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2,num;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		num[0]='1';
	}else
	{
		cout<<"0000";
		return 0;
	}
	if(s1[0]==s2[0] && s1[1]==s2[1])
	{
		num[1]='1';
	}else
	{
		cout<<"1000";
		return 0;
	}
	if(s1[2]<'D' && s2[2]<'D')
	{
		num[2]='1';
		if(s1[2]=='B' || s2[2]=='B')
		{
			num[3]='1';
		}else if(s1[2]=='A' && s2[2]=='C')
		{
			num[3]='1';
		}
		else{
			num[3]='0';
		}
	}else if(s1[2]>'C' && s2[2]>'C')
	{
		num[2]='1';
		num[3]='1';
	}
	else if(s1[2]>'C' && s2[2]<'D')
	{
		num[2]='0';
		num[3]='0';
	}else
	{
		num[2]='0';
		num[3]='0';
	}
	for(int i=0;i<4;i++)
	{
		cout<<num[i];
	}
	return 0;
} 
