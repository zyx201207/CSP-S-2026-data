#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdin);
	string r,rz,x,xz;
	cin>>r>>rz>>x>>xz;
	for(int i=0;i<2;i++)
	{
		if(r[i]!=x[i])
		{
			cout<<"0000";
			return 0;
		}
	}
	cout<<1;
	for(int i=0;i<2;i++)
	{
		if(rz[i]!=xz[i])
		{
			cout<<"000";
			return 0;
		}
	}
	cout<<1;
	int flag=10;
	if((rz[2]==68 && xz[2]==69) || (rz[2]==69 && xz[2]==68))
	{
		cout<<"11";
		return 0;
	}
	else if((rz[2]==65 && (xz[2]==66 || xz[2]==67)) || (rz[2]==66 && (xz[2]==65 || xz[2]==67)) || (rz[2]==67 && (xz[2]==65 || xz[2]==66)))
	{
		cout<<1;
		flag=0;
	}
	if(flag==10)
	{
		cout<<"00";
	}
	if(rz[2]==xz[2]+2 || rz[2]==xz[2]-2)
	{
		cout<<0;
		return 0;
	}
	cout<<1;
	return 0;
}
