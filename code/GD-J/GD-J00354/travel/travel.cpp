#include<bits/stdc++.h>
#define int long long
using namespace std;
string c,s,c2,s2;
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c>>s>>c2>>s2;
	if(c!=c2){cout<<"0000";return 0;}
	string p1="",p2="";
	p1+=s[0],p1+=s[1],p2+=s2[0],p2+=s2[1];
	if(p1!=p2){cout<<"1000";return 0;}
	if(s[2]=='D')
	{
		if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'){cout<<"1100";return 0;}
	}
	if(s[2]=='F')
	{
		if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'){cout<<"1100";return 0;}
	}
	if(s2[2]=='D')
	{
		if(s[2]=='A'||s[2]=='B'||s[2]=='C'){cout<<"1100";return 0;}
	}
	if(s2[2]=='F')
	{
		if(s[2]=='A'||s[2]=='B'||s[2]=='C'){cout<<"1100";return 0;}
	}
	if((s[2]=='A'&&s2[2]=='B')||(s[2]=='B'&&s2[2]=='C')||(s[2]=='D'&&s2[2]=='F')) cout<<"1111";
	else if((s2[2]=='A'&&s[2]=='B')||(s2[2]=='B'&&s[2]=='C')||(s2[2]=='D'&&s[2]=='F')) cout<<"1111";
	else cout<<"1110";
	return 0;
}
