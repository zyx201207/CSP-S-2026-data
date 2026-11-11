#include<bits/stdc++.h>
using namespace std;
long long a[2000005];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c=0,t=0;
	cin>>c>>t;
	for(int i=0;i<t;i++)
	{
		long long n=0,d=0;
		cin>>n>>d;
		bool l=true;
		for(int j=0;j<n;j++)
		{
			cin>>a[j];
			if(j>=2)
			{
				if(l && a[j]-a[j-1]!=a[j-1]-a[j-2])
				{
					l=false;
				}
			}
		}
		if(l)
		{
			long long q=abs(a[1]-a[0]);
			if(q*2>d)
			{
				cout<<0<<endl;
			}
			else
			{
				cout<<n/3<<endl;
			}
		}
		else
		{
			cout<<0<<endl;
		}
	}
	return 0;
}
