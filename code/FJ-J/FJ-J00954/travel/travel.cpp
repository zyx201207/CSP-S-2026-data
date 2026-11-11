#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c,s,cc,ss;
	cin>>c>>s>>cc>>ss;
	if(c==cc)
	{
		cout<<1;
	}
	else
	{
		cout<<0;
		cout<<0;
		cout<<0;
		cout<<0;
		return 0;
	}
	
	if(s[0]==ss[0] && s[1]==ss[1])
	{
		cout<<1;
	}
	else
	{
		cout<<0;
		cout<<0;
		cout<<0;
		return 0;
	}
	
	if((s[2]=='A' && ss[2]=='B')||(s[2]=='B' && ss[2]=='A')||(s[2]=='A' && ss[2]=='C')||(s[2]=='C' && ss[2]=='A')||(s[2]=='B' && ss[2]=='C') || (s[2]=='C' && ss[2]=='B') || (s[2]=='D' && ss[2]=='F')|| (s[2]=='F' && ss[2]=='D'))
	{
		cout<<1;
	}
	else
	{
		cout<<0;
		cout<<0;
		return 0;
	}
	
	if(abs(s[2]-ss[2])==1)
	{
		cout<<1;
	}
	else 
	{
		cout<<0;
		return 0;
	}
	return 0;
}
