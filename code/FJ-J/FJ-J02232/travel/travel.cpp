#include<bits/stdc++.h>
using namespace std;
string  co,ct,so,st;
int a[15];
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>co>>so>>ct>>st;
	if(co==ct) a[1]=1;
	else a[1]=0;
	if(so[0]==st[0]&&so[1]==st[1])
	{
		a[2]=1;
	}
	else
	{
		a[2]=0;
	}
	if(so[2]=='A'||so[2]=='B'||so[2]=='C')
	{
		if(st[2]=='A'||st[2]=='B'||st[2]=='C')
		{
			a[3]=1;
		}
		else
		{
			a[3]=0;
		}
	}
	else
	{
		if(so[2]=='D'||so[2]=='F')
		{
			if(st[2]=='D'||st[2]=='F')
			{
				a[3]=1;
			}
			else
			{
				a[3]=0;
			}
		}
	}
	int o=4;
	if(so[2]=='A'||so[2]=='B'||so[2]=='C')
	{
		if(so[2]=='A'&&st[2]=='B')
		{
			a[o]=1;o++;
		}
		else
		{
			a[o]=0;o++;
		}
		if(so[2]=='B'&&(st[2]=='A'||st[2]=='C'))
		{
			a[o]=1;o++;
		}
		else
		{
			a[o]=0;o++;
		}
		if(so[2]=='C'&&st[2]=='B')
		{
			a[o]=1;o++;
		}
		else
		{
			a[o]=0;o++;
		}
	}
	if(so[2]=='D'||so[2]=='F')
	{
		if(so[2]=='D'&&st[2]=='F') a[o]=1;
		else a[o]=0;
		o++;
		if(so[2]=='F'&&st[2]=='D') a[4]=1;
		else a[4]=0;
	}
	for(int i=1;i<=4;i++)
	{
		cout<<a[i];
	}
	return 0;
}
