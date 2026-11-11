#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
    int c1,c2,s1,s2;
	char c,s;
	cin>>c1>>c2>>c>>s1>>s2>>s;
	if(c1==c2 && c1!=01 && c1!=16)
	{
		if(c2==s2)
		{
			if(c=='A' && s=='B' || c=='A' && s=='C' || c=='B' && s=='C' || c=='B' && s=='A' || c=='C' && s=='B' || c=='C' && s=='A' || c=='D' && s=='F' || c=='F' && s=='D')
			{
				if(c=='A' && s=='B' || c=='B' && s=='C' || c=='B' && s=='A' || c=='C' && s=='B' || c=='D' && s=='F' || c=='F' && s=='D')
				{
					cout<<1111;
				}
				else
				{
					cout<<1110;
				}
			}
			else
			{
				cout<<1100;
			}
		}
		else
		{
			cout<<1000;
		}
	}
	else
	{
		cout<<0<<0<<0<<0;
	} 
	return 0;
} 
