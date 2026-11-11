#include<bits/stdc++.h>
#include<string>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2,n[10]={};
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		n[0]='1';
		if(s1[0]==s2[0]&&s1[1]==s2[1])
		{
			n[1]='1';
		if(((s1[2]=='A'||s1[2]=='B'||s1[2]=='C')&&(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'))||((s1[2]=='D'||s1[2]=='F')&&(s1[2]=='D'||s2[2]=='F')))
		{
			n[2]='1';
			if((s1[2]=='A'&&s2[2]=='B')||(s1[2]=='B'&&s2[2]=='C')||(s1[2]=='D'&&s2[2]=='F')||(s2[2]=='A'&&s1[2]=='B')||(s2[2]=='B'&&s1[2]=='C')||(s2[2]=='D'&&s1[2]=='F'))
				n[3]='1';
			else
				n[3]='0';
		}
		else
			n[2]='0';
		}
		else
		n[3]='0';
	}
	else
	{
		n[1]='0';
		n[2]='0';
		n[3]='0';
		n[4]='0';
	}
	for(int i=0;i<=4;i++)
	{
		cout<<n[i];
	}
	return 0;
}
