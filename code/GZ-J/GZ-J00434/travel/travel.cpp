//GZ-J00434 雷信洋 贵阳市第三十四中学 
#include<bits/stdc++.h>
using namespace std;
int zs(string n)
{
	int s=0;
	int l=n.size();
	int i=0;
	while(n[i]<'A'&&i<l)
	{
		s=s*10+(n[i]-'0');
		i++;
	}
	return s;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string x,y,s,s1;
	cin>>x>>y>>s>>s1;
	if(x==s)
	{
		cout<<"1";
	}
	else
	{
		cout<<"0000";
		return 0;
	}
	char c=y[2],b=s1[2];
	if(c>b)
	{
		char f=c;
		c=b;
		b=f;
	}
	int t=zs(y),t1=zs(s1);
	if(t==t1)
	{
		cout<<"1";
	}
	else
	{
		cout<<"000";
		return 0;
	}
	if(c=='D'&&b=='F')
	{
		cout<<"11";
	}
	else if(c=='A'&&b=='B'||c=='B'&&b=='C')
	{
		cout<<"11";
	}
	else if(c=='A'&&b=='C')
	{
		cout<<"10";
	}
	else
	{
		cout<<"00";
	}
	return 0;
}
