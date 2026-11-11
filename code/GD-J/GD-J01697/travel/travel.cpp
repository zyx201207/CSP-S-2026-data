#include<bits/stdc++.h>
using namespace std;
char a[15],b[15],c[15],d[15];
int la,lb,lc,ld,s=0;
bool hs1()
{
	char x=b[2],y=d[2];
	if(x=='A')
	{
		if(y=='B'||y=='C')
		return true;
	}
	if(x=='B')
	{
		if(y=='A'||y=='C')
		return true;
	}
	if(x=='C')
	{
		if(y=='A'||y=='B')
		return true;
	}
	if(x=='D')
	{
		if(y=='F')
		return true;
	}
	if(x=='F')
	{
		if(y=='D')
		return true;
	}
	return false;
}
bool hs2()
{
	char x=b[2],y=d[2];
	if(x=='A'&&y=='B')
	return true;
	if(x=='B'&&(y=='C'||y=='A'))
	return true;
	if(x=='C'&&y=='B')
	return true;
	if(x=='D'&&y=='F')
	return true;
	if(x=='F'&&y=='D')
	return true;
	return false;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout); 
	cin>>a>>b>>c>>d;
	la=strlen(a);
	lb=strlen(b);
	lc=strlen(c);
	ld=strlen(d);
	if(a[0]==c[0]&&a[1]==c[1]) s++;
	else
	{
		cout<<"0000";
		return 0;
	}
	if(b[0]==d[0]&&b[1]==d[1]) s++;
	else
	{
		cout<<"1000";
		return 0;
	}
	if(hs1()) s++;
	else
	{
		cout<<"1100";
		return 0;
	}
	if(hs2()) s++;
	else
	{
		cout<<"1110";
		return 0;
	}
	cout<<"1111";
	return 0;
}
