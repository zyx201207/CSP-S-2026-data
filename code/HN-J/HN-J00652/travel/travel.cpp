#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int x,y;
char a,b;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		cout<<"1";
	}
	else
	{
		cout<<"0";
	}
	for(int i=0;i<s1.size()-1;i++)
	{
		x=x*10+(s1[i]-'0');
	}
	for(int i=0;i<s2.size()-1;i++)
	{
		y=y*10+(s2[i]-'0');
	}
	if(c1==c2&&x==y)
	{
		cout<<"1";
	}
	else
	{
		cout<<"0";
	}
	a=s1[s1.size()-1];
	b=s2[s2.size()-1];
	if(c1==c2&&x==y&&((a>='A'&&a<='C'&&b>='A'&&b<='C')||(a>='D'&&a<='F'&&b>='D'&&b<='F')))
	{
		cout<<"1";
	}
	else
	{
		cout<<"0";
	}
	if(c1==c2&&x==y&&((a>='A'&&a<='C'&&b>='A'&&b<='C'&&abs(a-b)==1)||((a=='D'&&b=='F')||(a=='F'&&b=='D'))))
	{
		cout<<"1";
	}
	else
	{
		cout<<"0";
	}
	return 0;
}
