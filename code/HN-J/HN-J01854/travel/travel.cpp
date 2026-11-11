#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a1,a2,b1,b2;
	cin>>a1>>a2>>b1>>b2;
	char c=a2[2],d=b2[2];
	if(a1==b1)
	{
		if(a1[0]=='1')
		{
			if(a1[1]=='6')
			{
				cout<<0;
			}
			else
			{
				cout<<1;
			}
		}
		else
		{
			if(a1[1]=='1')
			{
				cout<<0;
			}
			else
			{
				cout<<1;
			}
		}
	}
	else
	{
		cout<<0<<0<<0<<0;
		return 0;
	}
	if(a2[0]==b2[0]&&a2[1]==b2[1])
	{
		cout<<1;
		if((c=='A')||( c=='B' )||(c=='C')&& (d=='A' )|| (d=='B' )||(d=='C' ))
		{
			cout<<1;
			if((int)a2[2]-(int)b2[2]==1||(int)a2[2]-(int)b2[2]==-1)
			{
				cout<<1;
			}
			else
			{
				cout<<0;
			}
		}
		else if( c=='D' || c=='E' && d=='D' || d=='E')
		{
			cout<<1<<1;
		}
		else
		{
			cout<<0<<0;
			return 0;
		}
	}
	else
	{
		cout<<0<<0<<0;
		return 0;
	}
	
	return 0;
}
