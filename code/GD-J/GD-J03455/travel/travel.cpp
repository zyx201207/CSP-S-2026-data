#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string r1,r2;
	string x1,x2;
	cin>>r1>>r2>>x1>>x2; 
	if(r1==x1)
	{
		cout<<1;
	}
	if(r1!=x1)
	{
		cout<<0<<0<<0<<0;
		return 0;
	}
	if((r2[0]==x2[0])&&(r2[1]==x2[1]))
	{
		cout<<1;
	}
	else
	{
		cout<<0<<0<<0;
		return 0;
	}
	char r=r2[2],x=x2[2];
	if((r<='C'&&x<='C')||(r<='F'&&r>='D'&&x<='F'&&x>='D'))
	{
		cout<<1;
	}
	else
	{
		cout<<0<<0;
		return 0;
	}
	if(r<='F'&&r>='D'&&x<='F'&&x>='D')
	{
		cout<<1;
	}
	if((r=='A'&&x=='B')||(r=='B'&&x=='A')||(r=='C'&&x=='B')||(r=='B'&&x=='C'))
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	return 0;
 } 
