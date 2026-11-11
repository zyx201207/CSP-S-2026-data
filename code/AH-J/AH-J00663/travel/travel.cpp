#include<bits/stdc++.h>
using namespace std;
int tyc(string s1,string s2)
{
	int b1,b2;
	if(s1[2]>='A'&&s1[2]<='C')
	{
		b1=1;//left
	}
	else
	{
		b1=0;//right
	}
	if(s2[2]>='A'&&s2[2]<='C')
	{
		b2=1;//left
	}
	else
	{
		b2=0;//right
	}
	if(b1==b2)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int xl(string s1,string s2)
{
	char ch1=s1[2],ch2=s2[2];
	int t1=int(ch1),t2=int(ch2);
	if(t1==t2+1||t1==t2-1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a1=0,a2=0,a3=0,a4=0;
	string c1,s1,c2,s2,t1,t2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		a1=1;
	}
	if(a1==1&&s1[0]==s2[0]&&s1[1]==s2[1])
	{
		a2=1;
	}
	if(a2==1&&tyc(s1,s2)==1)
	{
		a3=1;
	}
	if(a3==1&&xl(s1,s2))
	{
		a4=1;
	}
	cout<<a1<<a2<<a3<<a4;
	return 0;
}
