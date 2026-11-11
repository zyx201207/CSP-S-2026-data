#include<bits/stdc++.h>
using namespace std;
int id;
string s;
int id2;
string s2;
int a=1,b=1,c=1;
void check_train()
{
	if(id==id2)
	{
		cout<<1;
		return;
	}
	cout<<0;
	a=0;
	return;
}
void check_chair_1()
{
	if(a==0)
	{
		cout<<0;
		b=0;
		return;
	}
	if((s[1]==s2[1]) && (s[2]==s2[2]))
	{
		cout<<1;
		return;
	}
	cout<<0;
	b=0;
	return;
}
void check_chair_2()
{
	if(b!=1)
	{
		cout<<0;
		c=0;
		return;
	}
	if((s[3]=='C' && s2[3]=='D') || (s[3]=='D' && s2[3]=='C'))
	{
		cout<<0;
		c=0;
		return;
	}
	cout<<1;
	return;
}
void check_chair_3()
{
	if(c==0)
	{
		cout<<0;
		return;
	}
	if((s[3]+1==s2[3])||(s[3]-1==s2[3]))
	{
		cout<<1;
		return;
	}
	cout<<0;
	return;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>id>>s;
	cin>>id2>>s2;
	s=" "+s;
	s2=" "+s2;
	check_train();
	check_chair_1();
	check_chair_2();
	check_chair_3();
	return 0;
}
