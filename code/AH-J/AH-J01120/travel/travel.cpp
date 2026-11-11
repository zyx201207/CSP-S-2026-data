#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s[5];
	for(int i=1;i<=4;i++)
	{
		cin>>s[i];
	}
	bool f1=0,f2=0,f3=0;
	if(s[1]==s[3])
	{
		cout<<1;
		f1=1;
	}
	else
	{
		cout<<0;
	}
	if(f1==1&&(s[2][1]==s[4][1]))
	{
		cout<<1;
		f2=1;
	}
	else
	{
		cout<<0;
	}
	if(f2==1&&((s[2][2]=='A'&&s[4][2]=='B')||(s[2][2]=='B'&&s[4][2]=='A')||(s[2][2]=='A'&&s[4][2]=='C')||(s[2][2]=='C'&&s[4][2]=='A')||(s[2][2]=='C'&&s[4][2]=='B')||(s[2][2]=='B'&&s[4][2]=='C')||(s[2][2]=='D'&&s[4][2]=='F')||(s[2][2]=='F'&&s[4][2]=='D')))
	{
		cout<<1;
		f3=1;
	}
	else
	{
		cout<<0;
	}
	if(f3==1&&(abs(s[2][2]-s[4][2])==1))
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	return 0;
}
