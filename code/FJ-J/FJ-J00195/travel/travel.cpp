#include <bits/stdc++.h>
using namespace std;
int n,m;
string x,y;
char a[10000007],b[10000007];
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n>>x>>m>>y;
	if(n!=m)
	{
		cout<<"0000";
		return 0;
	}
	cout<<"1";
	for(int i=0;i<3;i++)
	{
		a[i]=x[i];
	}
	for(int i=0;i<3;i++)
	{
		b[i]=y[i];
	}
	if(a[0]!=b[0]||a[1]!=b[1])
	{
		cout<<"000";
		return 0;
	}
	cout<<"1";
	if(a[2]==b[2])
	{
		cout<<"00";
		return 0;
	}
	else
	{
		if('A'<=a[2]&&a[2]<='C' && 'A'<=b[2]&&b[2]<='C')
		{
			cout<<"1";
		}
		else if('D'<=a[2]&&a[2]<='F' && 'D'<=b[2]&&b[2]<='F')
		{
			cout<<"1";
		}
		else
		{
			cout<<"00";
			return 0;
		}
	}
	if((a[2]=='A'&&b[2]=='B')||(a[2]=='B'&&b[2]=='A')||(a[2]=='B'&&b[2]=='C')||(a[2]=='C'&&b[2]=='B')||(a[2]=='D'&&b[2]=='F')||(a[2]=='F'&&b[2]=='D'))
	{
		cout<<"1";
	}
	else
	{
		cout<<"0";
	}	
	return 0;
}
