// GZ-J00104 贵州省瓮安第二中学 严云涵 
#include <bits/stdc++.h>
using namespace std;
int a[5],c[5];
string b[5];
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	for (int i=1;i<=2;i++)
	{
		cin >> a[i];
		cin >> b[i];
	}
	if(a[1]==a[2])
	{
		c[1]=1;
	}
	else
	{
		c[1]=0;
		cout << c[1] << c[2]<< c[3] << c[4];
		return 0;
	}
	if(b[1][0]==b[2][0] &&b[1][1]==b[2][1])
	{
		c[2]=1;
	}
	else
	{
		c[2]=0;
		cout << c[1] << c[2]<< c[3] << c[4];
		return 0;
	}
	if((b[1][2]=='A'|| b[1][2]=='B' || b[1][2]=='C') && (b[2][2]!='D' && b[2][2]!='E'))
	{
		c[3]=1;
	}
	else if((b[1][2]!='A' && b[1][2]!='B' && b[1][2]!='C') && (b[2][2]=='D' || b[2][2]=='E'))
	{
		c[3]=1;
	}
	else 
	{
		c[3]=0;
		cout << c[1] << c[2]<< c[3] << c[4];
		return 0;
		
	}

	if((b[1][2]-'0')-(b[2][2]-'0')==1 || (b[2][2]-'0')-(b[1][2]-'0')==1)
	{
		c[4]=1;
	}
	else
	{
		c[4]=0;
	}
	
	cout << c[1] << c[2]<< c[3] << c[4];
	return 0;
}
