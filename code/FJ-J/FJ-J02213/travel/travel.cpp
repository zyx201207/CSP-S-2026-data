#include<bits/stdc++.h>
using namespace std;
bool is_pai(char a,char b)
{
	if(a=='A'&&b=='B')
	{
		return true;
	}
	if(a=='B'&&b=='C')
	{
		return true;
	}
	if(b=='A'&&a=='B')
	{
		return true;
	}
	if(b=='B'&&a=='C')
	{
		return true;
	}
	if(b=='D'&&a=='F')
	{
		return true;
	}
	if(b=='F'&&a=='D')
	{
		return true;
	}
	return false;
}
bool is_lin(char a,char b)
{
	if(a=='A'&&b=='B')
	{
		return true;
	}
	if(a=='B'&&b=='C')
	{
		return true;
	}
	if(b=='A'&&a=='B')
	{
		return true;
	}
	if(b=='B'&&a=='C')
	{
		return true;
	}
	if(b=='D'&&a=='F')
	{
		return true;
	}
	if(b=='F'&&a=='D')
	{
		return true;
	}
	return false;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int c1,c2;
	string s1,s2;
	cin>>c1;
	cin>>s1;
	cin>>c2;
	cin>>s2;
	if(c1==c2)
	{
		cout<<'1';
	}
	else
	{
		cout<<"0000";
		goto g;
	}
	if(s1[1]==s2[1]&&s1[0]==s2[0])
	{
		cout<<'1';
	}
	else
	{
		cout<<"000";
		goto g;
	}
	if(is_pai(s1[2],s2[2]))
	{
		cout<<'1';
	}
	else
	{
		cout<<"00";
		goto g;
	}
	if(is_lin(s1[2],s2[2]))
	{
		cout<<'1';
	}
	else
		cout<<'0';
	g:
	return 0;
}
