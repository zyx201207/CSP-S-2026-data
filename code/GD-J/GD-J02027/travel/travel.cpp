#include<bits/stdc++.h>
using namespace std;
using ll=long long ;
string a,b,c,d,s;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a!=c)
	{
		cout<<"0000";
		return 0;
	}
	else s+='1';
	ll bb=b[0]+b[1];
	ll dd=d[0]+d[1];
	if(bb==dd)s+='1';
	else 
	{
		cout<<"1000";
		return 0;
	}
	if((b[2]>='A'&&b[2]<='C'&&d[2]>='A'&&d[2]<='C')||(b[2]>='D'&&b[2]<='E'&&d[2]>='D'&&d[2]<='E'))s+='1';
	else 
	{
		cout<<"1100";
		return 0;
	}
	char b1=b[2],d1=d[2];
	if(b1>d1)swap(b1,d1);
	if(char(b1+1)==d1&&d1!='D')s+='1';
	else
	{
		cout<<"1110";
		return 0;
	}
	cout<<s;
	return 0;
 } 
