#include<bits/stdc++.h>
using namespace std;
int main()
{
	int c1,c2;
	char s1[5],s2[5];
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1;
	for(int i=1;i<=3;i++)
	{
		cin>>s1[i];
	}
	cin>>c2;
	for(int i=1;i<=3;i++)
	{
		cin>>s2[i];
	}
	if(c1!=c2)
	{
		cout<<0000;
	}
	else if(s1[1]!=s2[1]||s2[2]!=s1[2])
	{
		cout<<1000;
	}
	else if(s1[3]=='B'&&(s2[3]=='A'||s2[3]=='C')||s2[3]=='B'&&(s1[3]=='A'||s1[3]=='C')||s1[3]=='D'&&s2[3]=='F'||s1[3]=='F'&&s2[3]=='D')
	{
		cout<<1111;
	}
	else if(abs(s1[3]-s2[3])>=3||s1[3]=='D'&&(s2[3]=='C'||s2[3]=='B')||s2[3]=='D'&&(s1[3]=='C'||s1[3]=='B'))
	{
		cout<<1100;
	}
	else
	{
		cout<<1110;
	}
	return 0;
}
