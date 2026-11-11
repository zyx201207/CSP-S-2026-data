#include<bits/stdc++.h>
using namespace std;
string a,b,a1,b1;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>a>>b>>a1>>b1;
	for(int i=0;i<a.size();i++)
	{
		if(a[i]!=a1[i])
		{
			for(int i=1;i<=4;i++)
			{
				cout<<0;
			}
			return 0;
		}
	}
	cout<<1;
	int k=0;
	for(int i=0;i<2;i++)
	{
		if(b[i]!=b1[i])
		{
			for(int i=1;i<=2;i++)
			{
				cout<<0;
			}
			k=1;
		}
	}
	if(k==0)
	{
		cout<<1;
		if((b[2]=='A'||b[2]=='B'||b[2]=='C')&&(b1[2]=='A'||b1[2]=='B'||b1[2]=='C'))
		{
			cout<<1;
		}
		else if((b[2]=='F'||b[2]=='D')&&(b1[2]=='F'||b1[2]=='D'))
		{
			cout<<1;
		}
		else
		{
			cout<<0;
		}
	}
	if(((b[2]=='C'&&b1[2]=='D')||(b1[2]=='C'&&b[2]=='D')))
	{
		cout<<0;
		return 0;
	}
	if((b[1]-'0'+1==b1[1]-'0'&&b1[2]==b[2])||(b[1]-'0'-1==b1[1]-'0'&&b1[2]==b[2])||((b[2]+1==b1[2])&&(b[1]-'0'==b1[1]-'0')&&(b[0]-'0'==b1[0]-'0'))||((b[2]-1==b1[2])&&(b[1]-'0'==b1[1]-'0')&&(b[0]-'0'==b1[0]-'0')))
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	return 0;
}
