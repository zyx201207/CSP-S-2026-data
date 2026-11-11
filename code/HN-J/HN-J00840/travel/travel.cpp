#include<bits/stdc++.h>
using namespace std;
string c1;
string c2; 
string s1;
string s2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1;
	cin>>s1;
	cin>>c2;
	cin>>s2;
	if(c1!=c2)
	{
		cout<<0<<0<<0<<0;
		return 0;
	}
	if(s1[1]!=s2[1]||s1[0]!=s2[0])
	{
		cout<<1000;
		return 0;
	}
	if(((s1[2]=='A'||s1[2]=='B'||s1[2]=='C')&&(s2[2]=='D'||s2[2]=='F'))||(s2[2]=='A'||s2[2]=='B'||s2[2]=='C')&&(s1[2]=='D'||s1[2]=='F'))
	{
		cout<<1100;
		return 0;
	}
	if(s1[2]==s2[2]+1||s1[2]==s2[2]-1||(s1[2]=='D'&&s2[2]=='F')||(s1[2]=='F'&&s2[2]=='D'))
	{
		cout<<1111;
		return 0;
	}
	else
	{
		cout<<1110;
		return 0; 
	} 
	return 0;
}
