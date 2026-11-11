#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
string ax,ac,bx,bc;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>ax>>ac>>bx>>bc;
	if(ax==bx)
		cout<<1;
	else
	{
		cout<<"0000";
		return 0;
	}
	if(ac[1]==bc[1]&&ac[0]==bc[0])
		cout<<1;
	else
	{
		cout<<"000";
		return 0;
	}
	if((ac[2]=='A'&&(bc[2]=='B'||bc[2]=='C'))||(ac[2]=='B'&&(bc[2]=='A'||bc[2]=='C'))||(ac[2]=='C'&&(bc[2]=='B'||bc[2]=='A'))||(ac[2]=='D'&&bc[2]=='E')||(ac[2]=='E'&&bc[2]=='D'))
		cout<<1;
	else
	{
		cout<<"00";
		return 0;
	}
	if((ac[2]=='A'&&bc[2]=='B')||(ac[2]=='B'&&(bc[2]=='A'||bc[2]=='C'))||(ac[2]=='C'&&bc[2]=='B')||(ac[2]=='D'&&bc[2]=='E')||(ac[2]=='E'&&bc[2]=='D'))
		cout<<1;
	else
		cout<<0;
	return 0;
}
