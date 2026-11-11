#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	string x[10];
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
		x[0]='1';
	else
	{
		cout<<"0000";
		return 0;
	}
		
	if(s1[0]==s2[0]&&s1[1]==s2[1])
		x[1]='1';
	else
	{
		cout<<"1000";
		return 0;
	}
	char p=s1[2];
	char q=s2[2];
	
	if('D'-p>=1&&'D'-q>=1)
		x[2]='1';
	else if(p-'C'>=1&&q-'C'>=1)
		x[2]='1';
	else
	{
		cout<<"1100";
		return 0;
	}
	if(p=='A')
	{
		if(q-p==1)
			x[3]='1';
		else
		{
			cout<<"1110";
			return 0;
		} 
	}
	else if(p=='B')
	{
		if(abs(p-q)==1)
			x[3]='1'; 
		else
		{
			cout<<"1110";
			return 0;
		}
		
	}
	else if(p=='C')
	{
		if(p-q==1)
			x[3]='1';
		else
		{
			cout<<"1110";
			return 0;
		}
	}
	else if(p=='D')
	{
		if(q-p==2)
			x[3]='1';
		else
		{
			cout<<"1110";
			return 0;
		}
	}
	else if(p=='F')
	{
		if(p-q==2)
			x[3]='1';
		else
		{
			cout<<"1110";
			return 0;
		}
	}
	for(int i=0;i<10;i++)
		cout<<x[i];
	return 0;
 } 
