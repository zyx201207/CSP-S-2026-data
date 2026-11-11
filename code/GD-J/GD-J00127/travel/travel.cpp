#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a1,b1,a2,b2;
	cin>>a1>>b1>>a2>>b2;
	if(a1==a2)
	{
		cout<<1;
		if(b1[0]==b2[0] and b1[1]==b2[1])
		{
			cout<<1;
			if(((b1[2]=='A' or b1[2]=='B' or b1[2]=='C') and (b2[2]=='A' or b2[2]=='B' or b2[2]=='C')) or((b1[2]=='E' or b1[2]=='F') and (b2[2]=='E' or b2[2]=='F')))
			{
				cout<<1;
				if(b1[2]-b2[2]==1 or b2[2]-b1[2]==1)
			{
				cout<<1;
			}
				else
				{
				cout<<0;
				}
			}
			else
			{
				cout<<0<<0;
			}
		}
		else
		{
			cout<<0<<0<<0;
		}	
	}	
	else
	{
		cout<<0<<0<<0<<0;
	}
	cout<<"\n";
	return 0;
} 
