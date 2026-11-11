#include <bits/stdc++.h> 
using namespace std;
int main()
{
	fropen("travel.in","r",stdin);
	fropen("travel.out","w",stdout);
	string n,m,a,b;
	int q=0,w=0
	cin>>n>>m>>a>>b;
	if (n[0]==a[0] && n[1]==a[1])
	{
		cout<<"1";
	}
	else
	{
		cout<<"0000";
		return 0;
	}
	if (m[0]==b[0] && m[1]==b[1])
	{
		cout<<"1";
		q=1;
	}
	else
	{
		cout<<"0";
		q=0;
	}
	if (q==1)
	{
		if ((m[2]=='A' && b[2]=='B' || m[2]=='A' && b[2]=='C' || m[2]=='B' && b[2]=='A' || m[2]=='B' && b[2]=='C' || m[2]=='C' && b[2]=='A' || m[2]=='C' && b[2]=='B') || (m[2]=='D' && b[2]=='E' || m[2]=='E' && b[2]=='D'))
		{
			cout<<'1';
			w=1;
			
		}
		else
		{
			cout<<'0';
		}
	}
	else
	{
		cout<<"0";
	}
	if (w==1)
	{
		if ((m[2]=='B' || b[2]=='B') || (m[2]=='D' || b[2]=='D'))
		{
			cout<<'1';
		}
		else
		{
			cout<<'0';
		}
	}
	else
	{
		cout<<'0';
	}
	return 0;
}
