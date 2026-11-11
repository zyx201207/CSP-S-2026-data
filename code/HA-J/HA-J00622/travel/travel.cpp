#include <bits/stdc++.h>
using namespace std;
long long rc,xc,rp,xp;
char r,x;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>rc>>rp>>r>>xc>>xp>>x;
	if(rc==xc)
	{
		cout<<"1";
	}
	else
	{
		cout<<"0000";
		return 0;
	}
	if(rp==xp)
	{
		cout<<"1";
	}
	else
	{
		cout<<"000";
		return 0;
	}
	if((r<='C'&&x<='C')||(r>='D'&&x>='D'))
	{
		cout<<"1";
	}
	else
	{
		cout<<"00";
		return 0;
	}
	if(abs((r-'0')-(x-'0'))==1)
	{
		cout<<"1";
	}
	else
	{
		cout<<"0";
		return 0;
	}
	return 0;
}
