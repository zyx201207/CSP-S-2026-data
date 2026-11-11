#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int t1,t2,t3,t4;
int ce(char x)
{
	if(x=='F'||x=='D')
	{
		return 1;
	}
	else
	{
		return 2;
	}
}
bool lin(char a,char b) 
{
	if(a=='C'&&b=='D'||a=='D'&&b=='C')
	{
		return false;
	}
	if(abs(int(a-'A')-int(b-'A'))==1)
	{
		return true;
	}
	return false;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		cout<<1;
	}
	else
	{
		cout<<"0000";
		return 0;
	}
	t1=s1[0]-'0';
	t2=s1[1]-'0';
	t3=s2[0]-'0';
	t4=s2[1]-'0';
	if((t1*10+t2)==(t3*10+t4))
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	if((t1*10+t2)==(t3*10+t4)&&ce(s1[(s1.size()-1)])==ce(s2[(s2.size()-1)]))
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	if((t1*10+t2)==(t3*10+t4)&&lin(s1[s1.size()-1],s2[s2.size()-1]))
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	return 0;
}
