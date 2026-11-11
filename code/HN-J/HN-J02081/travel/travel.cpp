#include<bits/stdc++.h>
#include<cstdio> 
using namespace std;
int c1,c2,p1,p2,l1,l2;
string s1,s2;
bool flag=1;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	p1=s1[0]*10+s1[1];
	p2=s2[0]*10+s2[1];
	l1=s1[2]-'A';
	l2=s2[2]-'A';
	if(c1==c2)
	{
		cout<<"1";
	}
	else 
	{
		cout<<"0";flag=0;
	}
	if(p1==p2&&flag)
	{
		cout<<"1";
	}
	else 
	{
		cout<<"0";flag=0;
	}
	if(((l1>2&&l2>2)||(l1<3&&l2<3))&&flag)
	{
		cout<<"1";
	}
	else
	{
		cout<<"0";flag=0;
	}
	if(flag&&(l1-l2==1||l1-l2==-1))
	cout<<"1";
	else cout<<"0";
	return 0;
}

