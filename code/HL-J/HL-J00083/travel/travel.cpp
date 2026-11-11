#include <bits/stdc++.h>
using namespace std;
int a,b;
string as,bs;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>a>>as>>b>>bs;
	if(a!=b)
	{
		cout<<"0000"<<'\n';
	}
	else
	{
		cout<<"1";
		if(as[1]!=bs[1]||as[0]!=bs[0])
		{
			cout<<"000"<<'\n';
		}
		else
		{
			cout<<"1";
			if((as[2]=='D'&&bs[2]=='F')||(as[2]=='F'&&bs[2]=='D'))
			{
				cout<<"11"<<'\n';
			}
			else if((as[2]=='A'&&(bs[2]=='B'||bs[2]=='C'))||(as[2]=='B'&&(bs[2]=='A'||bs[2]=='C'))||(as[2]=='C'&&(bs[2]=='A'||bs[2]=='B')))
			{
				cout<<"1";
				if(as[2]-bs[2]==1||bs[2]-as[2]==1)
				{
					cout<<"1"<<'\n';
				}
				else
				{
					cout<<"0"<<'\n';
				}
			}
			else
			{
				cout<<"00"<<'\n';
			}
		}
	}
	return 0;
}