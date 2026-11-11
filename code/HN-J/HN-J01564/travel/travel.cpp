#include <bits/stdc++.h>
using namespace std;
string s1,s2,c1,c2,a,b,x,y;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int cnt=0;
	cin>>c1>>s1>>c2>>s2;
	a=s1[0]+s1[1];
	b=s2[0]+s2[1];
	if(c1==c2)
	{
		cout<<1;
	}
	else{
		cout<<0;
	}
	if(c1==c2&&a==b)
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	if(a==b&&((s1[2]=='A'&&(s2[2]=='B'||s2[2]=='C'))||(s1[2]=='B'&&(s2[2]=='A'||s2[2]=='C'))||(s1[2]=='C'&&(s2[2]=='A'||s2[2]=='B'))))
	{
		cout<<1;
		cnt++;
	}
	else if(a==b&&((s1[2]=='D'&&s2[2]=='F')||(s1[2]=='F'&&s2[2]=='D')))
	{
		cout<<1;
		cnt++;
	}
	else
	{
		cout<<0;
	}
	if(cnt==1&&((s1[2]=='B'&&(s2[2]=='A'||s2[2]=='C'))||(s2[2]=='B'&&(s1[2]=='A'||s1[2]=='C'))))
	{
		cout<<1;
	}
	else if(cnt==1&&((s1[2]=='D'&&s2[2]=='F')||(s1[2]=='F'&&s2[2]=='D')))
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	return 0;
}
