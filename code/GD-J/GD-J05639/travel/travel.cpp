#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int t1,t2;
bool flag=1;
bool cha(char a,char b)
{
	if(a>='A'&&a<='C'&&b>='A'&&b<='C')
		return 1;
	else if(a=='D'&&b=='F')
		return 1;
	else if(a=='F'&&b=='D')
		return 1;	
	else
		return 0;	
}
bool cha1(char a,char b)
{
	if(a=='A'&&b=='B')
		return 1;
	else if(a=='B'&&b=='A')
		return 1;
	else if(a=='B'&&b=='C')
		return 1;
	else if(a=='C'&&b=='B')
		return 1;			
	else if(a=='D'&&b=='F')
		return 1;
	else if(a=='F'&&b=='D')
		return 1;	
	else
		return 0;	
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.our","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		cout<<'1';
	}
	else if(c1!=c2)
	{
		cout<<"0000";
		return 0;
	}
	t1=(s1[0]-'0')*10+(s1[1]-'0');
	t2=(s2[0]-'0')*10+(s2[1]-'0');
	if(t1==t2)
	{
		cout<<'1';
	}
	else if(t1!=t2)
	{
		cout<<"000";
		return 0;
	}
	if(cha(s1[2],s2[2]))
	{
		cout<<'1';
	}
	else if(!cha(s1[2],s2[2]))
	{
		cout<<"00";
		return 0;
	}
	if(cha1(s1[2],s2[2]))
	{
		cout<<'1';
	}
	else if(!cha1(s1[2],s2[2]))
	{
		cout<<'0';
		return 0;
	}
	return 0;
}
