#include <iostream>
using namespace std;
int c1,c2;
char s1[4],s2[4];
int main()
{
	bool bl=false; 
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
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
	if(s1[0]==s2[0] && s1[1]==s2[1])
	{
		cout<<1;
		bl=true;
	}
	else
	{
		cout<<0;
	}
	if(s1[2]<='C' && s2[2]<='C' && bl)
	{
		cout<<1;
	}
	else if(s1[2]>'C' && s2[2]>'C' && bl) 
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	if((s1[2]!='C' && s2[2]!='D')&&(s1[2]!='D' && s2[2]!='C')&&(bl && (s1[2]+1==s2[2] || s1[2]-1==s1[2])))
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	return 0;
} 
