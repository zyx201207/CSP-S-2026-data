#include<bits/stdc++.h>
using namespace std;
int c1,c2;
string s1,s2,p1,p2;
char l1,l2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	p1=s1[0];
	p1+=s1[1];
	l1=s1[2];
	p2=s2[0];
	p2+=s2[1];
	l2=s2[2];
	if(c1==c2)
	{
		cout<<1;
	}
	else 
	{
		cout<<0;
	}
	if(c1==c2&&p1==p2)
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	if(c1==c2&&p1==p2&&((l1>='D'&&l2>='D')||(l1<='C'&&l2<='C')))
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	if(c1==c2&&p1==p2&&((l1>='D'&&l2>='D')||(l1<='C'&&l2<='C'))&&abs((int)l1-l2)==1)
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	return 0;
}
