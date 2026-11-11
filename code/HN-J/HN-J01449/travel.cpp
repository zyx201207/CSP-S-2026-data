#include<bits/stdc++.h>
using namespace std;
int a,b;
string s,s1;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>s>>b>>s1;
	if(s[2]=='F') s[2]='E';
	if(s1[2]=='F') s1[2]='E';
	if(a==b) cout<<1;
	else cout<<0;
	if(a==b&&s[0]==s1[0]&&s[1]==s1[1]) cout<<1;
	else cout<<0;
	if(a==b&&s[0]==s1[0]&&s[1]==s1[1]&&((s[2]>='A'&&s[2]<='C'&&s1[2]>='A'&&s1[2]<='C')||(s[2]>='D'&&s[2]<='E'&&s1[2]>='D'&&s1[2]<='E'))) cout<<1;
	else cout<<0;
	if(a==b&&s[0]==s1[0]&&s[1]==s1[1]&&((s[2]>='A'&&s[2]<='C'&&s1[2]>='A'&&s1[2]<='C')||(s[2]>='D'&&s[2]<='E'&&s1[2]>='D'&&s1[2]<='E'))&&(s[2]-s1[2]==1||s[2]-s1[2]==-1)) cout<<1;
	else cout<<0;
	return 0;
} 
