#include<bits/stdc++.h>
using namespace std;
int n[5];
bool pan(char a,char b)
{
	if(abs(a-b)==1)
	{
		return true;
	}
	if(abs(a-b)==2)
	{
		if(a=='F'&&b=='D'||a=='D'&&b=='F')
		return true;
	}
	return false;
}
int main()
{
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a==c)
	{
		n[1]=1;
		if(b[0]==d[0]&&b[1]==d[1])
		{
			n[2]=1;
			if(b[2]>='A'&&b[2]<='C'&&d[2]>='A'&&d[2]<='C'||b[2]>='D'&&b[2]<='F'&&d[2]>='D	'&&d[2]<='F')
			{
				n[3]=1;
				if(pan(b[2],d[2]))
				{
					n[4]=1;
				}
			}
		}
	}
	for(int i=1;i<=4;i++)
	{
		cout<<n[i];
	}
	return 0;
}
