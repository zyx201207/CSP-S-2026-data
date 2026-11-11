#include <bits/stdc++.h> 
using namespace std;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string z1,z2;
	int c1,c2;
	cin>>c1;
	cin>>z1;
	cin>>c2;
	cin>>z2;
	bool b=true;
	bool c=true;
	bool d=true;
	if(c1!=c2)
	{
		b=false;
		cout<<"0";
		d=false;
	}
	else
	{
		cout<<"1";
	}
	if((z1[0]!=z2[0]||z1[1]!=z2[1]))
	{
		b=false;
		c=false;
		cout<<"0";
	}
	else if(d)
	{
		cout<<"1";
	}
	else
	{
		cout<<"0";
		b=false;
		c=false;
	}
	if(((z1[2]=='D'&&z2[2]=='F')||(z2[2]=='D'&&z1[2]=='F'))||((z1[2]!='D'&&z1[2]!='F')&&(z2[2]!='D'&&z2[2]!='F'))&&c)
	{
		cout<<"1";
	}
	else
	{
		cout<<"0";
		b=false;	
	}
	if(b&&((z1[2]=='A'&z2[2]=='B')||(z1[2]=='B'&&z2[2]=='A')||(z1[2]=='B'&&z2[2]=='C')||(z1[2]=='C'&&z2[2]=='B')||(z1[2]=='D'&&z2[2]=='F')||(z1[2]=='F'&&z2[2]=='D')))
	{
		cout<<"1";
	}
	else
	{
		cout<<"0";
	}
	return 0;
} 
