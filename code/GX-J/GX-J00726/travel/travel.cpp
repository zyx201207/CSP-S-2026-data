#include<bits/stdc++.h>
using namespace std;
string ca,sa,cb,sb,bc,bs;
char a,b;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>ca>>cb>>sa>>sb;
	for(int i=0;i<2;i++)
	{
		bc+=cb[i];
		
	}
	a=cb[2];
	for(int i=0;i<2;i++)
	{
		bs+=sb[i];
		
	}
	b=sb[2];
	if(ca==sa)
	{
		cout<<1;
		if(bc==bs)
		{
			cout<<1;
			if(a=='A'||a=='B'||a=='C')
			{
				if(b=='A'||b=='B'||b=='C')
				{
					cout<<1;
					if(a=='A'||a=='C')
					{
						if(b=='B')
						{
							cout<<1;
						}
						else cout<<0;
					}
					else if(a=='B')
					{
						if(b=='A'||b=='C')
						{
							cout<<1;
						}
						else cout<<0;
					}	
				}
				else cout<<0<<0;
			}
			else if(a=='D'||a=='F')
			{
				if(b=='D'||b=='F')
				{
					if(a=='D')
					{
						if(b=='F')
						{
							cout<<1;
						}
						else cout<<0;
					}
					else if(a=='F')
					{
						if(b=='D')
						{
							cout<<1;
						}
						else cout<<0;
					}	
				}
				else cout<<0<<0;
			}
		}
		else cout<<0<<0<<0;
	}
	else cout<<0<<0<<0<<0;
	return 0;
}
