//travel
#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,sa,b,sb;
	cin>>a>>sa>>b>>sb;
	if(a!=b)
	{
		cout<<"0000";
		return 0;
	}
	if(sa[0]!=sb[0] || sa[1]!=sb[1])
	{
		cout<<"1000";
		return 0;
	}
	if((sa[2]=='F' && sb[2]=='D') || (sa[2]=='D' && sb[2]=='F'))
	{
		cout<<"1111";
		return 0;
	}
	if((sa[2]>='D' && sa[2]<='F') && (sb[2]>='A' && sa[2]<='C'))
	{
		cout<<"1100";
		return 0;
	}
	if((sb[2]>='D' && sb[2]<='F') && (sa[2]>='A' && sa[2]<='C'))
	{
		cout<<"1100";
		return 0;
	}
	if(sa[2]=='A' && sb[2]=='C')
	{
		cout<<"1110";
		return 0;
	}
	if(sa[2]=='C' && sb[2]=='A')
	{
		cout<<"1110";
		return 0;
	}
	cout<<"1111";
	return 0;
}
