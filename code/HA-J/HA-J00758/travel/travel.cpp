#include<bits/stdc++.h>
using namespace std;
string s1,s2;
int a1,a2,b1,b2,c1,c2;
bool o1,o2;
signed main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a1>>s1>>a2>>s2;
	b1=(s1[0]-'0')*10+s1[1]-'0';
	b2=(s2[0]-'0')*10+s2[1]-'0';
	c1=s1[2]-'A'+1;
	c2=s2[2]-'A'+1;
	switch(s1[2])
	{
		case 'A':o1=1;break;
		case 'B':o1=1;break;
		case 'C':o1=1;break;
		case 'D':o1=0;break;
		case 'E':o1=0;break;
	}
	switch(s2[2])
	{
		case 'A':o2=1;break;
		case 'B':o2=1;break;
		case 'C':o2=1;break;
		case 'D':o2=0;break;
		case 'E':o2=0;break;
	}
	if(a1!=a2)
	{
		cout<<"0000";
		return 0;
	}
	cout<<"1";
	if(b1!=b2)
	{
		cout<<"000";
		return 0;
	}
	cout<<"1";
	
	if(o1!=o2)
	{
		cout<<"00";
		return 0;
	}
	cout<<"1";
	if(abs(c1-c2)==1)
	{
		cout<<"1";
	}
	else
	{
		cout<<"0";
	}
}
