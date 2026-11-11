#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
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
	int a=s1[1];
	int b=s1[2];
	int c=s2[1];
	int d=s2[2];
	char tiga=s1[3];
	char geed=s2[3];
	if(a==c||b==d)
	{
		cout<<1;
	}
	else  
	{
		cout<<0;
	}
	if(((tiga=='A'||tiga=='B'||tiga=='C')&&(geed=='A'||geed=='B'||geed=='C'))||((tiga=='D'||tiga=='F')&&(geed=='D'||geed=='F')))
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	if(((tiga=='A'&&geed=='B')||(tiga=='B'&&geed=='C')||(tiga=='C'&&geed=='D')||(tiga=='D'&&geed=='F'))||((geed=='A'&&tiga=='B')||(geed=='B'&&tiga=='C')||(geed=='C'&&tiga=='D')||geed=='D'&&tiga=='F'))
	{
		cout<<1;
	}
	else 
	{
		cout<<0;
	} 
	return 0;
}
