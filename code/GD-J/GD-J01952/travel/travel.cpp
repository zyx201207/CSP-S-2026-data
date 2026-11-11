#include<bits/stdc++.h>
using namespace std;
string s1,s2,s3,s4;
bool b=1;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1>>s2>>s3>>s4;
	if(s1!=s3)
	{
		cout<<0<<0<<0<<0;
		return 0;
	}
	else
		cout<<1;
	if((s2[0]!=s4[0])||(s2[1]!=s4[1]))
	{
		cout<<0<<0<<0;
		return 0;
	}
	else
		cout<<1;
	if((((s2[2]=='A')||(s2[2]=='B')||(s2[2]=='C'))&&((s4[2]=='A')||(s4[2]=='B')||(s4[2]=='C'))))
	{
		b=1;
	}
	else if(((s2[2]=='D')&&(s4[2]=='F'))||((s2[2]=='F')&&(s4[2]=='D')))
	{
		cout<<1<<1;
		return 0;
	}
	else
	{
		b=0;
		cout<<0<<0;
		return 0;
	}
	if(b==1)
	{
		cout<<1;
	}
	if((s2[2]-1==s4[2])||(s4[2]-1==s2[2]))
	{
		b=1;
	}
	else
		b=0;
	if(b==1)
	{
		cout<<1;
	}
	else
		cout<<0;
	return 0;
}
