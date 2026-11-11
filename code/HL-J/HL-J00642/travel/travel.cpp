#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string cr,sr,cx,sx; 
bool tc()
{
	if((sr[2]=='A'||sr[2]=='B'||sr[2]=='C')&&(sx[2]=='A'||sx[2]=='B'||sx[2]=='C')) 
	{
		return 1;
	}else if((sr[2]=='D'||sr[2]=='E')&&(sx[2]=='D'||sx[2]=='E'))
	{
		return 1;
	}else
	{
		return 0;
	}
}
bool xl()
{
	if((sr[2]=='B'&&(sx[2]=='A'||sx[2]=='C'))||(sx[2]=='B'&&(sr[2]=='A'||sr[2]=='C'))) 
	{
		return 1;
	}else if((sr[2]=='D'||sr[2]=='E')&&(sx[2]=='D'||sx[2]=='E'))
	{
		return 1;
	}else
	{
		return 0;
	}
}
bool tp()
{
	if(sr[1]==sx[1]&&sr[0]==sx[0]) 
	{
		return 1;
	}else
	{
		return 0;
	}
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>cr>>sr>>cx>>sx;
	if(cr==cx)
	{
		cout<<1;
	}else
	{
		cout<<0;
	}
	if(cr==cx&&tp()==1)
	{
		cout<<1;
	}else
	{
		cout<<0;
	}
	if(cr==cx&&tp()==1&&tc()==1)
	{
		cout<<1;
	}else
	{
		cout<<0;
	}
	if(cr==cx&&tp()==1&&xl()==1)
	{
		cout<<1;
	}else
	{
		cout<<0;
	}
	return 0;
}
