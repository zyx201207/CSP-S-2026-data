#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string co,so,ct,st;
	cin>>co>>so>>ct>>st;
	if(co==ct)
	{
		printf("1");
	}
	else
	{
		printf("0");
	}
	if(co==ct && so[0]==st[0] && so[1]==st[1])
	{
		printf("1");
	}
	else
	{
		printf("0");
	}
	if(co==ct && (so[0]==st[0] && so[1]==st[1]) && ((so[2]>='A' && so[2]<='C' && st[2]>='A' && st[2]<='C') || (so[2]>='D' && so[2]<='F' && st[2]>='D' && st[2]<='F')))
	{
		printf("1");
	}
	else
	{
		printf("0");
	}
	if(co==ct && (so[0]==st[0] && so[1]==st[1]) && ((so[2]>='A' && so[2]<='C' && st[2]>='A' && st[2]<='C') || (so[2]>='D' && so[2]<='F' && st[2]>='D' && st[2]<='F')))
	{
		if(so[2]>='A' && so[2]<='C' && st[2]>='A' && st[2]<='C')
		{
			if(abs(so[2]-st[2])==1)
			{
				printf("1");
			}
			else
			{
				printf("0");
			}
		}
		else
		{
			printf("1");
		}
	}
	else
	{
		printf("0");
	}
	return 0;
}
