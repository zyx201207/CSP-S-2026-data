#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	if(m==1)
	{
		long long ma=0;
		for(int i=1;i<=n;i++)
		{
			long long t;
			cin>>t;
			ma=max(ma,t);
		}
		cout<<ma;
	}
	else if(m==2)
	{
		long long a[2005],ma=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		for(int i=1;i<=n-1;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				ma=max(ma,a[i]&a[j]);
			}
		}
		cout<<ma;
	}
	else if(m==n)
	{
		long long ma;
		cin>>ma;
		for(int i=2;i<=n;i++)
		{
			long long t;
			cin>>t;
			ma=ma&t;
		}
		cout<<ma;
	}
	else cout<<0;
	return 0;
}
