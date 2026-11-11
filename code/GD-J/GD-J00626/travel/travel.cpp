#include<bits/stdc++.h>
using namespace std;
bool check(char a,char b)
{
	if(a=='A'||(a=='B'||a=='C'))
	{
		if(b=='A'||(b=='B'||b=='C'))
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	else if(a=='D'||a=='F')
	{
		if(b=='D'||b=='F')
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
}
bool check2(char a,char b)
{
	if(abs((int)a-(int)b)==1&&(((a>='A'&&a<='C')&&(b>='A'&&b<='C'))||((a>='D'&&a<='F')&&(b>='D'&&b<='F'))))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	int a=0,b=0,c=0,d=0,i;
	cin>>c1>>s1>>c2>>s2;
	i=0;
	while(c1[i]=='0')
	{
		i++;
	}
	for(i;i<c1.size();i++)
	{
		a*=10;
		a+=c1[i]-'0';
	}
	i=0;
	while(s1[i]=='0')
	{
		i++;
	}
	for(i;i<s1.size()-1;i++)
	{
		b*=10;
		b+=s1[i]-'0';
	}
	i=0;
	while(c2[i]=='0')
	{
		i++;
	}
	for(i;i<c2.size();i++)
	{
		c*=10;
		c+=c2[i]-'0';
	}
	i=0;
	while(s2[i]=='0')
	{
		i++;
	}
	for(i;i<s2.size()-1;i++)
	{
		
		d+=s2[i]-'0';
	}
	if(a==c)
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	if(b==d&&a==c)
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	if(check(s1[s1.size()-1],s2[s2.size()-1])&&b==d&&a==c)
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	if(check2(s1[s1.size()-1],s2[s2.size()-1])&&b==d&&a==c)
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	return 0;
}
