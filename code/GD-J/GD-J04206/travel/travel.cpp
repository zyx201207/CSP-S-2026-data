#include <iostream>
#include <string>
using namespace std;
string c1,s1,c2,s2;
int side(char x)
{
	if(x=='A'||x=='B'||x=='C')
	{
		return 1;
	}
	else
	{
		return 2;
	}
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	if(c1==c2&&s1[0]==s2[0]&&s1[1]==s2[1])
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	if(c1==c2&&s1[0]==s2[0]&&s1[1]==s2[1]&&side(s1[2])==side(s2[2]))
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	char x=s1[2];
	char y=s2[2];
	if(x>y) swap(x,y);
	if(y=='F') y='E';
	if(c1==c2&&s1[0]==s2[0]&&s1[1]==s2[1]&&side(s1[2])==side(s2[2])&&y-1==x)
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	
	return 0;
}
