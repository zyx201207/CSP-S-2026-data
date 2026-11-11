#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string cxa,zha,cxb,zhb;
	int t,lx=0;
	bool f=true,ff=false;
	cin>>cxa>>zha>>cxb>>zhb;
	if(cxa==cxb)
	cout<<'1';
	else
	{
		cout<<'0';
		f=false;
	}
	if(zha[0]==zhb[0]&&zha[1]==zhb[1]&&f)
	cout<<'1';
	else
	{
		cout<<'0';
		f=false;
	}
	if(zha[2]<='C'&&zhb[2]<='C')
	{
		ff=true;
		lx=1;
	}
	else if(zha[2]>'C'&&zhb[2]>'C')
	{
		ff=true;
		lx=2;
	}
	if(ff&&f)
	cout<<'1';
	else
	{
		cout<<'0';
		f=false;
	}
	t=abs(zha[2]-zhb[2]);
	if(t==1&&lx==1&&f)
	cout<<'1';
	else if(t==2&&lx==2&&f)
	cout<<'1';
	else
	cout<<'0';
	return 0;
}
