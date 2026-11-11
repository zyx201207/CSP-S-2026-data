#include <bits/stdc++.h>
using namespace std;
string c11,s1,c21,s2;
int main()
{
	freopen(travel.in);
	fr;
	}
	//
	int as1=0,as2=0;
	k=1;
	for(int i=1;i>=0;i--)
	{
		as1+=(s1[i]-'0')*k;
		k=k*10;
	}
	k=1;
	for(int i=1;i>=0;i--)
	{
		as2+=(s2[i]-'0')*k;
		k=k*10;
	}
	//char bs1=s1[2],bs2=s2[2];
	
	if(c1==c2)
	{
		cout<<"1";
	}
	else
		cout<<"0";
	if(c1==c2 && as1==as2)
	{
		cout<<"1";	
	}
	else
		cout<<"0";
	if(c1==c2 && as1==as2 && ((s1[2]<'D'&&s2[2]<'D')||(s1[2]>'C'&&s2[2]>'C')))
	{
		cout<<"1";
		if(((s1[2]=='A'&&s2[2]=='C')||(s1[2]=='C'&&s2[2]=='A')))
		{
			cout<<"0";
		}	
		else
			cout<<"1";
	}
	else
		cout<<"0"<<"0";
	return 0;
}