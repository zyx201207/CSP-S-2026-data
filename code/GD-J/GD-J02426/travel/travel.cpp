#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
int cc1,cc2,ss1,ss2;
bool check(char a,char b)
{
	return !((a=='D'||a=='F')^(b=='D'||b=='F'));
}
signed main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	for(int i=0;i<c1.size();i++)
	{
		cc1*=10;
		cc1+=c1[i]-48;
	}
	for(int i=0;i<c2.size();i++)
	{
		cc2*=10;
		cc2+=c2[i]-48;
	}
	for(int i=0;i<s1.size()-1;i++)
	{
		ss1*=10;
		ss1+=s1[i]-48;
	}
	for(int i=0;i<s2.size()-1;i++)
	{
		ss2*=10;
		ss2+=s2[i]-48;
	}
	if(cc1==cc2) cout<<'1';
	else
	{
		cout<<"0000";
		return 0;
	}
	if(ss1==ss2) cout<<'1';
	else
	{
		cout<<"000";
		return 0;
	}
	if(check(s1[s1.size()-1],s2[s2.size()-1])) cout<<'1';
	else
	{
		cout<<"00";
		return 0;
	}
	if(s1[s1.size()-1]=='D'||s2[s2.size()-1]=='D'||abs(s1[s1.size()-1]-s2[s2.size()-1])==1)
	{
		cout<<'1';
	}
	else cout<<'0';
	return 0;
}
