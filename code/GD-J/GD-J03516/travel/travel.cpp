#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int cr,cx;
	string sr,sx;
	cin>>cr>>sr>>cx>>sx;
	if(cr!=cx)
	{
		cout<<0<<0<<0<<0;
	}
	else
	{
		cout<<1;
		for(int i=0;i<=1;i++)
		{
			sr[i]=sr[i]-'0';
			sx[i]=sx[i]-'0';
		}
		int a=sr[0]*10+sr[1];
		int b=sx[0]*10+sx[1];
		if(a!=b)
		{
			cout<<0<<0<<0;
		}
		else
		{
			cout<<1;
			if('A'<=sr[2]&&'C'>=sr[2]&&'A'<=sx[2]&&'C'>=sx[2])
			{
				cout<<1;
			}
			else if('D'<=sr[2]&&'E'>=sr[2]&&'D'<=sx[2]&&'E'>=sx[2])
			{
				cout<<1;
			}
			else
			{
				cout<<0;
			}
			if((sr[2]=='C'&&sx[2]=='D')||(sx[2]=='C'&&sr[2]=='D'))
			{
				cout<<0;
			}
			else if(sr[2]-sx[2]==1||sr[2]-sx[2]==-1)
			{
				cout<<1;
			}
			else
			{
				cout<<0;
			}
		}
	}
	return 0;
}
