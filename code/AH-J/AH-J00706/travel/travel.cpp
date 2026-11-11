#include<bits/stdc++.h>
using namespace std;
string a,b,c,d,s1,s2;
bool checkto(char x,char y)
{
	if((x=='A'&&y=='B')||(x=='B'&&y=='A')||(x=='A'&&y=='C')||(x=='C'&&y=='A')||(x=='B'&&y=='C')||(x=='C'&&y=='B')||(x=='D'&&y=='F')||(x=='F'&&y=='D'))
	{
		return true;
	}
	return false;
}
bool checkli(char x,char y)
{
	if((x=='A'&&y=='B')||(x=='B'&&y=='A')||(x=='B'&&y=='C')||(x=='C'&&y=='B')||(x=='D'&&y=='F')||(x=='F'&&y=='D'))
	{
		return true;
	}
	return false;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>a>>b>>c>>d;
	s1=b[0]+b[1];
	s2=d[0]+d[1];
	if(a==c)
	{
		cout<<"1";
	}
	else
	{
		cout<<"0";
	}
	if(a==c&&s1==s2)
	{
		cout<<"1";
	}
	else
	{
		cout<<"0";
	}
	if(a==c&&s1==s2&&checkto(b[2],d[2])!=0)
	{
		cout<<"1";
	}
	else
	{
		cout<<"0";
	}
	if(a==c&&s1==s2&&checkli(b[2],d[2])!=0)
	{
		cout<<"1";
	}
	else
	{
		cout<<"0";
	}
}
