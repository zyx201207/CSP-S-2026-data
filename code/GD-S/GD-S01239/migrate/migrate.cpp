#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	long long c,t;
	cin>>c>>t;
	for(int i=1;i<=t;i++)
	{
		long long n,d;
		cin>>n>>d;
		if(n<=3)
		{
			cout<<"0";
			continue;
		}
		long long x[n+5];
		for(int i=1;i<=n;i++)
		{
			cin>>x[i];
		}
		long long k;
		if((n-2)==d)
		{
			if(d%2==0)
			{
				cout<<"1";
			}
			else
			{
				cout<<"0";
			}
		}
		else if((n-2)%d==0)
		{
			k=(n-2)/d;
			if(k%2==0)
			{
				cout<<k;
			}
			else
			{
				cout<<k-1;
			}			
		}
		else
		{
			k=ceil((n-2)/d)+1;
			cout<<k;
		} 
	}
	return 0;
}
