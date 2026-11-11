#include<bits/stdc++.h>
using namespace std;
int x,r;
string x2,r2;
int ans[10];
int x3,r3;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>x>>x2;
	cin>>r>>r2;
	if(x==r)
	{
		ans[1]=1;
		if(x2[0]==r2[0]&&x2[1]==r2[1])
		{
			ans[2]=1;
			if(x2[2]=='A'&&r2[2]=='B')
			{
				ans[3]=1;
				ans[4]=1;
			}
			if(x2[2]=='A'&&r2[2]=='C')
			{
				ans[3]=1;
			}
			if(x2[2]=='B'&&r2[2]=='A')
			{
				ans[3]=1;
				ans[4]=1;
			}
			if(x2[2]=='B'&&r2[2]=='C')
			{
				ans[3]=1;
				ans[4]=1;
			}
			if(x2[2]=='C'&&r2[2]=='A')
			{
				ans[3]=1;
			}
			if(x2[2]=='C'&&r2[2]=='B')
			{
				ans[3]=1;
				ans[4]=1;
			}
			if(x2[2]=='E'&&r2[2]=='F')
			{
				ans[3]=1;
				ans[4]=1;
			}
			if(x2[2]=='F'&&r2[2]=='E')
			{
				ans[3]=1;
				ans[4]=1;
			}
			
		}
		
	}
	
	for(int i=1;i<=4;i++)
	{
		cout<<ans[i];
	}

	
	return 0;
}
// Trick||Treat! 
