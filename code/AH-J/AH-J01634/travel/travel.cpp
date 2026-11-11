#include<bits/stdc++.h>
using namespace std;
char s[4][3];
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	for(int i=0;i<4;i++)
	{
		cin>>s[i];
	}
	if(s[0][1]==s[2][1])
	{
		cout<<"1";
	}
	else
	{
		cout<<"0";
	}
	if(s[0][1]==s[2][1]&&s[1][1]==s[3][1])
	{
		cout<<"1";
	}
	else
	{
		cout<<"0";
	}
	int f1=s[3][2]-'A',f2=s[1][2]-'A';
	bool flag=(f1<=2&&f2<=2)||(f1>2&&f2>2);
	if(s[0][1]==s[2][1]&&s[1][1]==s[3][1]&&flag==1)
	{
		cout<<"1";
	}
	else
	{
		cout<<"0";
	}
	if(s[0][1]==s[2][1]&&s[1][1]==s[3][1]&&flag==1)
	{
		cout<<"1";
	}
	else
	{
		cout<<"0";
	}
	return 0;
}
