#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	 string s,d,f,g;
	 cin>>s>>d>>f>>g;
	 int cnt=1;
	int y=0;
	if(s==f)
	{
		cout<<1;
		if(d[0]==g[0]&&d[1]==g[1])
		{
			cout<<1;
			if(d[2]=='C'||d[2]=='B'||d[2]=='A')
			{
				
				
					if(g[2]=='C'||g[2]=='A'||g[2]=='B')
					{
						cout<<1;
						cnt=0;
					}
			          
				
				else
				{
					cout<<0<<0;
				}
			}
			else if(d[2]=='F'||d[2]=='D')
			{
				
				
					 if(g[2]=='F'||g[2]=='D')
					 {
					 	cout<<1;
					 	cnt=0;
					 	y=0;
					 }	
				else
				{
					cout<<0<<0;
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
	else if(s!=f)
	{
		cout<<0<<0<<0<<0;
	}
        if(cnt==0)
        {
		if(d[2]=='F'||d[2]=='D'||d[2]=='B'||g[2]=='B')
		{
		   cout<<1;
		}
		else
		{
			cout<<0;
		}
    	}
    	return 0;
	}
	
	 
	 
	
	 
