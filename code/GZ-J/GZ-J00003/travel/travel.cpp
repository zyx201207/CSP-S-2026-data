//GZ-J00003 ¶­ÜÇÐù 
#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2;
	string s1,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		cout<<1;
	}
	else 
	{
		cout<<0<<0<<0<<0;
		return 0;
	}
	int p1=(s1[0]-'0')*10+(s1[1]-'0');
	int p2=(s2[0]-'0')*10+(s2[1]-'0');
	if(p1==p2)
	{
		cout<<1;
	}
	else
	{
		cout<<0<<0<<0;
		return 0;
	}
	char a1=s1[2],a2=s2[2];
	if(((a1=='A'||a1=='B'||a1=='C')&&(a2=='A'||a2=='B'||a2=='C'))||((a1=='D'||a1=='F')&&(a2=='D'||a2=='F')))
	{
		cout<<1;
	}
	else
	{
		cout<<0<<0;
		return 0;
	}
	if((a1=='A'&&a2=='B')||(a1=='B'&&a2=='A')||(a1=='B'&&a2=='C')||(a1=='C'&&a2=='B')||(a1=='D'&&a2=='F')||(a1=='F'&&a2=='D'))
	{
		cout<<1;
	}
	else 
	{
		cout<<0;
	}
	return 0;
}
