#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string rcx,xcx,rh,xh;
	cin>>rcx>>rh>>xcx>>xh;
	if(rcx==xcx)
		cout<<1;
	else
	{
		for(int i=1;i<=4;i++)
			cout<<0;
		return 0;
	}
	if(rh[0]==xh[0]&&rh[1]==xh[1])
		cout<<1;
	else
	{
		for(int i=1;i<=3;i++)
			cout<<0;
		return 0;
	}
	if((rh[2]<='C'&&xh[2]<='C')||(rh[2]>='D'&&xh[2]>='D'))
		cout<<1;
	else
	{
		for(int i=1;i<=2;i++)
			cout<<0;
		return 0;
	}
	if(rh[2]<='C')
	{
		if(rh[2]-1==xh[2]||rh[2]+1==xh[2])
			cout<<1;
		else if((rh[2]=='D'&&xh[2]=='F')||(rh[2]=='F'&&xh[2]=='D'))
					cout<<1;
		else
			cout<<0;
	}
	else if((rh[2]=='D'&&xh[2]=='F')||(rh[2]=='F'&&xh[2]=='D'))
		cout<<1;
	else
		cout<<0;	
}
