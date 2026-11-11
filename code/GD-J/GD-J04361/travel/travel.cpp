#include<bits/stdc++.h>
#define ll long long
using namespace std;
string a,b;
string c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	bool f=0,fl=0,fla=0;
	if(a==c)
	{
		cout<<1;
		f=1;
	}
	else
	{
		cout<<0;
	}
	int zy=0,hc=0;
	for(int i=0;i<2;i++)
	{
		zy=zy*10+b[i];
		hc=hc*10+d[i];
	}
	if(zy==hc && f)
	{
		cout<<1;
		fl=1;
	}
	else
	{
		cout<<0;
	}
	if(((b[2]=='E' && d[2]=='F') || (d[2]=='E' && b[2]=='F'))&& f && fl)
	{
		fla=1;
		cout<<1;
	}
	else if(((b[2] >='A' && b[2]<='C' )&& (d[2]>='A'&& d[2]<='C'))&& f && fl)
	{
		cout<<1;
		fla=1;
	}
	else
	{
		cout<<0;
	}
	int yz=b[2]-'A';
	int gh=d[2]-'A';
	if(f && fl && fla &&(abs(yz-gh)<=1))
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	return 0;
} 
