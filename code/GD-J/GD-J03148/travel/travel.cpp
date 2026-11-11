#include<bits/stdc++.h>
using namespace std;
string s1,s2,s3,s4;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1>>s2>>s3>>s4;
	if(s1==s3)
	{
		cout<<"1";
	}
	else
	{
		cout<<"0";
	}
	if(s2[0]==s4[0] && s2[1]==s4[1] && s1==s3)
	{
		cout<<"1";
	}
	else
	{
		cout<<"0";
	}
	if((s2[2]=='A'||s2[2]=='B'||s2[2]=='C') && (s4[2]=='A'||s4[2]=='B'||s4[2]=='C') && s2[0]==s4[0] && s2[1]==s4[1] && s1==s3)
	{
		cout<<"1";
	}
	else if((s2[2]=='D'||s2[2]=='E') && (s4[2]=='D'||s4[2]=='E') && s2[0]==s4[0] && s2[1]==s4[1] && s1==s3)
	{
		cout<<"1";
	}
	else
	{
		cout<<"0";
	}
	int x=s2[2]-'A';
	int y=s4[2]-'A';
	if(x>y && x-y==1 && x!=3 && s2[0]==s4[0] && s2[1]==s4[1] && s1==s3)
	{
		cout<<"1";
	}
	else if(y>x && y-x==1 && y!=3 && s2[0]==s4[0] && s2[1]==s4[1] && s1==s3)
	{
		cout<<"1";
	}
	else
	{
		cout<<"0";
	}
	return 0;
	     
}
