#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);	
	freopen("travel.out","w",stdout);	
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) cout<<"1";
	else cout<<"0";
	if(c1==c2&&s1[0]==s2[0]&&s1[1]==s2[1]) cout<<"1";
	else cout<<0;
	if(c1==c2&&s1[0]==s2[0]&&s1[1]==s2[1]&&(int)s1[2]=='A'||(int)s1[2]=='B'||(int)s1[2]=='C')
	{
		if('s2[2]'=='A'||'s2[2]'=='B'||'s2[2]'=='C') cout<<"1";
		if(!((int)s2[2]=='A'||(int)s2[2]=='B'||(int)s2[2]=='C')) cout<<"0";
	}
	if(c1==c2&&s1[0]==s2[0]&&s1[1]==s2[1]&&(int)s1[2]=='D'||(int)s1[2]=='F')
	{
		if((int)s2[2]=='D'||(int)s2[2]=='F') cout<<"1";
		if(!((int)s2[2]=='D'||(int)s2[2]=='F')) cout<<"0";
	}
	else if(!(c1==c2&&s1[0]==s2[0]&&s1[1]==s2[1])) cout<<0;
	if((int)s1[2]=='A'&&c1==c2&&s1[0]==s2[0]&&s1[1]==s2[1])
	{
		if((int)s2[2]=='B') cout<<"1";
		if(!((int)s2[2]=='B')) cout<<"0";
	}
	if((int)s1[2]=='B'&&c1==c2&&s1[0]==s2[0]&&s1[1]==s2[1])
	{
		if((int)s2[2]=='A'||(int)s2[2]=='C') cout<<"1";
		if(!((int)s2[2]=='A'||(int)s2[2]=='C')) cout<<"0";
	}
	if((int)s1[2]=='C'&&c1==c2&&s1[0]==s2[0]&&s1[1]==s2[1])
	{
		if((int)s2[2]=='B') cout<<"1";
		if(!((int)s2[2]=='B')) cout<<"0";
	}
	if((int)s1[2]=='D'&&c1==c2&&s1[0]==s2[0]&&s1[1]==s2[1])
	{
		if((int)s2[2]=='F') cout<<"1";
		if(!((int)s2[2]=='F')) cout<<"0";
	}
	if((int)s1[2]=='F'&&c1==c2&&s1[0]==s2[0]&&s1[1]==s2[1])
	{
		if((int)s2[2]=='D') cout<<"1";
		if(!((int)s2[2]=='D'))  cout<<"0";
	}
	else if(!(c1==c2&&s1[0]==s2[0]&&s1[1]==s2[1])) cout<<0;
	return 0;
} 
