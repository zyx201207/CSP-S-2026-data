#include<bits/stdc++.h>
using namespace std;
int cr,cx;
string sr,sx;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>cr>>sr>>cx>>sx;
	if(cr==cx)
	{
		cout<<1;
	}
	else
	{
		cout<<0;
		cout<<0;
		cout<<0;
		cout<<0;
		return 0;
	}
	if(sr[0]==sx[0]&&sr[1]==sx[1])
	{
		cout<<1;
	}
	else
	{
		cout<<0;
		cout<<0;
		cout<<0;
		return 0;
	}
	if(sr[2]=='A'||sr[2]=='B'||sr[2]=='C')
	{
		if(sx[2]=='A'||sx[2]=='B'||sx[2]=='C')
		{
			cout<<1;
			if(max(sr[2],sx[2])-min(sr[2],sx[2])==1)
			{
				cout<<1;
				return 0;
			}
			else
			{
				cout<<0;
				return 0;
			}
		}
	}
	if(sr[2]=='D'||sr[2]=='F')
	{
		if(sx[2]=='F'||sx[2]=='D')
		{
			cout<<1;
			cout<<1;
			return 0;
		}
	}
	else
	{
		cout<<0;
		cout<<0;
		return 0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
