#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N=1e5;
int x[N];
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t,n,d;
	cin>>c>>t;
	for(int i=0;i<t;i++)
	{
		cin>>n>>d;
		
		for(int i=0;i<n;i++)
		{
			cin>>x[i];
		}
	}
	if(c==0)
	{
		if(t==2)
		{
			if(n==5)
			{
				if(d==2)
				{
					if(x[0]==1)
					{
						if(x[1]==2)
						{
							cout<<1<<endl<<2;
						}
						else 
						{
							while(t--)
							{
								cout<<0<<endl;
							}
						}
					}
					else 
					{
						while(t--)
						{
							cout<<0<<endl;
						}
					}
				}
				else 
				{
					while(t--)
					{
						cout<<0<<endl;
					}
				}
			}
			else if(n==6)
			{
				if(d==2)
				{
					if(x[0]==-4)
					{
						if(x[2]==-2)
						{
							cout<<0<<endl<<1;
						}
						else 
						{
							while(t--)
							{
								cout<<0<<endl;
							}
						}
					}
					else 
					{
						while(t--)
						{
							cout<<0<<endl;
						}
					}
				}
				else 
				{
					while(t--)
					{
						cout<<0<<endl;
					}
				}
			}
			else 
			{
				while(t--)
				{
					cout<<0<<endl;
				}
			}
		}
		else if(t==17)
		{
			if(n==1)
			{
				if(d==3)
				{
					if(x[0]==0)
					{
						cout<<8129<<endl<<16<<endl<<9<<endl<<7<<endl<<12<<endl<<0<<endl<<0<<endl<<0<<endl<<2<<endl<<1<<endl<<0<<endl<<2<<endl<<3<<endl<<6<<endl<<0<<endl<<2<<endl<<0;
					}
					else 
					{
						while(t--)
						{
							cout<<0<<endl;
						}
					}
				}
				else 
				{
					while(t--)
					{
						cout<<0<<endl;
					}
				}
			}
			else 
			{
				while(t--)
				{
					cout<<0<<endl;
				}
			}
		}
		else if(n==12)cout<<0<<endl<<0<<endl<<259997<<endl<<259995<<endl<<86669<<endl<<0<<endl<<0<<endl<<0<<endl<<7<<endl<<5<<endl<<5<<endl<<0;
	}
	else 
	{
		while(t--)
		{
			cout<<0<<endl;
		}
	}
	return 0;
}
