#include<iostream>
#include<string>
#include<cmath>
using namespace std;
string a,b,c,d;
bool flag=0;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(b[2]=='F') b[2]='E';
	if(d[2]=='F') d[2]='E';
	if(a==c) cout<<1;
	else
	{
		cout<<"0000";
		return 0;
	} 
	if(b[1]==d[1] && b[0]==d[0]) cout<<1;
	else
	{
		cout<<"000";
		return 0;
	}
	if((b[2]>='A' && b[2]<='C' && d[2]>='A' && d[2]<='C') || (b[2]>='D' && b[2]<='E' && d[2]>='D' && d[2]<='E'))
	{
		cout<<1,flag=1;
	}
	else
	{
		cout<<"00";
		return 0;
	}
	if(flag && abs(b[2]-d[2])==1) cout<<1;
	else cout<<0;
	return 0;
} 
