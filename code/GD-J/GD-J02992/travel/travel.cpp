#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);	
	string s,z,s1,z1,x,x1;
	bool l=0,o=0;
	cin>>s>>z>>s1>>z1;
	x=z[0]+z[1];
	x1=z1[0]+z1[1];
	if(z[2]>'C') l=1;
	if(z1[2]>'C') o=1;

	if(s==s1)
	{
		cout<<'1';
	}
	else
	{
		cout<<"0000";
		return 0;
	}
	if(x==x1)
	{
		cout<<'1';
	}
	else
	{
		cout<<"000";
		return 0;
	}
	if(l==o)
	{
		cout<<'1';
	}
	else
	{
		cout<<"00";
		return 0;
	}
	if(abs(z[2]-z1[2])==1)
	{
		cout<<'1';
	}
	else
	{
		cout<<"0";
		return 0;
	}
	return 0;
}
