#include<bits/stdc++.h>
using namespace std;

int c1=0,c2=0;
string s1,s2;
char ch1='A',ch2='A';
int i1=1,i2=1;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		cout<<'1';
	}
	else
	{
		for(int i=0;i<4;i++)
		{
			cout<<'0';
		}
		return 0;
	}
	if(s1[0] == s2[0] && s1[1] == s2[1]) 
	{
		cout<<'1';
	}
	else
	{
		for(int i=1;i<4;i++)
		{
			cout<<'0';
		}
		return 0;
	}
	
	if((s1[2]=='F' || s1[2]=='D') && (s2[2]=='F' ||s2[2]=='F'))
	{
		cout<<"11";
	}
	else
	{
		if((s1[2]<='C') && (s2[2]<='C'))
		{
			cout<<'1';
			if(int(s1[2])-int(s2[2])==1 || int(s1[2])-int(s2[2])==-1)
			{
				cout<<'1';
			}
			else
			{
				cout<<'0';
			}
		}
		else
		{
			cout<<"00";
		}
	}
	return 0;
}
