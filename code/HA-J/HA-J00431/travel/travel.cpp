#include<bits/stdc++.h>
using namespace std;
int j[4],k[4],l[4],m[4],o[10];
string a,b,x,y;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>x>>a>>y>>b;
	j[1]=x[0]-'0';
	j[2]=x[1]-'0';
	k[1]=y[0]-'0';
	k[2]=y[1]-'0';
	if(j[1]==k[1]&&j[2]==k[2])
	{
		o[1]=1;
		if(a[0]==b[0]&&a[1]==b[1])
		{
			o[2]=1;
		}
		if(a[2]<='C'&&a[2]>='A')
		{
			if(b[2]<='C'&&b[2]>='A')
			{
				o[3]=1;
			}
		}
		else if(a[2]=='D'||a[2]=='F')
		{
			if(b[2]=='D'||b[2]=='F')
			{
				o[3]=1;
			}
		}
		if(b[2]=a[2]+1||b[2]==a[2]-1)
		{
			o[4]=1;
		}
	}
	for(int i=1;i<=4;i++)
	{
		cout<<o[i];
	}
	return 0;
}
