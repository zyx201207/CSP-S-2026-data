#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int cabr,cabx;
	string sitr,sitx;
	cin>>cabr>>sitr>>cabx>>sitx;
	if(cabr==cabx)
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	if(cabr==cabx&&sitr.substr(0,2)==sitx.substr(0,2))
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	if(cabr==cabx&&sitr.substr(0,2)==sitx.substr(0,2)&&
		(((sitr[2]==65||sitr[2]==66||sitr[2]==67)&&(sitx[2]==65||sitx[2]==66||sitx[2]==67))
		||((sitr[2]==68||sitr[2]==70)&&(sitx[2]==68||sitx[2]==70))))
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	if(cabr==cabx&&sitr.substr(0,2)==sitx.substr(0,2)&&
		(((sitr[2]==65||sitr[2]==66)&&(sitx[2]==65||sitx[2]==66))||
		((sitr[2]==67||sitr[2]==66)&&(sitx[2]==67||sitx[2]==66))||
		((sitr[2]==68||sitr[2]==70)&&(sitx[2]==68||sitx[2]==70))))
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	return 0;
}
//shit mountain is very beautiful!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!676767
