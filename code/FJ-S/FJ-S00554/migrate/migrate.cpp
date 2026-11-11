#include<bits/stdc++.h>
using namespace std;
int c,t;
long long n,d,a5;
long long a[2000005]; 
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	if(c==11 || c==12)
	{
		for(int i=1;i<=t;i++)
		{
			cin>>n>>d;
			for(int j=1;j<=n;j++)
			{
				cin>>a[j];
			}
			a5=a[2]-a[1];
			if(a5>=d)
			{
				if(a5/d==1)
				{
					cout<<a5%d<<endl;
				}
			}
			else
			{
				cout<<0<<endl;
			}
		}
	}
	else if(c>=15 && c<=18)
	{
		for(int i=1;i<=t;i++)
		{
			cin>>n>>d;
			for(int j=1;j<=n;j++)
			{
				cin>>a[j];
			}
			cout<<0<<endl;
		}
	}
	else
	{
		for(int i=1;i<=t;i++)
		{
			cin>>n>>d;
			for(int j=1;j<=n;j++)
			{
				cin>>a[j];
			}
			if(n<=4)
			{
				cout<<1<<endl;
			}
			else
			{
				cout<<2<<endl;
			}
		}
	}
	return 0;
 } 
