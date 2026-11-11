#include<bits/stdc++.h>
using namespace std;
string a,b,n,m;
long long cnt=0,ans=0,x,y;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>n>>m;
	for(long long i=0;i<a.size();i++)
	{
		if(a[i]==n[i])
		cnt++;
	}
	if(cnt==a.size())
	cout<<'1';
	else{
		cout<<"0000";
		return 0;
	}
	for(long long i=0;i<b.size()-1;i++)
	{
		x=x*10+b[i]-48;
		y=y*10+m[i]-48;
	}
	if(x==y)
	cout<<'1';
	else
	{
		cout<<"000";
		return 0;
	}
	if(b[2]=='A'&&(m[2]=='B'||m[2]=='C')||b[2]=='B'&&(m[2]=='A'||m[2]=='C')||b[2]=='C'&&(m[2]=='B'||m[2]=='A'))
	cout<<'1';
	else if(b[2]=='D'&&m[2]=='F'||b[2]=='F'&&m[2]=='D')
	cout<<'1';
	else
	{
		cout<<"00";
		return 0;
	}
	if(abs(b[2]-m[2])==1)
	{
		if(b[2]!='C'&&m[2]!='D'||m[2]!='C'&&m[2]!='D')
		cout<<'1';
		else
		cout<<'0';
	}
	else
	cout<<'0';
	return 0;
}