#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
long long a[2000005];


int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	int c,t;
	cin>>c>>t;
	while(t--)
	{
		int n;
		long long d;
		bool f=1;
		cin>>n>>d;
		cin>>a[1]>>a[2];
		long long k=a[2]-a[1];
		int u=0,v;
		for(int i=3;i<=n;i++)
		{
			cin>>a[i];
			if(a[i]-a[i-1]!=k)
				f=0;
		}
		if(d>=(a[n]-a[1]))
		{
			cout<<0<<endl;
			continue;
		}
		if(f==1);
		{
			if(d<=k)
			{
				cout<<0<<endl;
				continue;
			}
			int m=(d/k);
			if(m>=3)
			{
				cout<<0<<endl;
				continue;
			}
			int sum=0;
			for(int i=n;i>m;i--)
			{
				int c=(i/m);
				sum+=(c-1)*(m-1);
				sum+=(i-(m*c));
			}
			cout<<sum/2<<endl;
			continue;
		}
		int sum=0;
		for(int i=1;i<n;i++)
		{
			int s=0,l,fl=1;
			for(int l=i+1;l<=n;l++)
			{
				if(a[l]>a[i]+d)
				{
					if(l-i<3)
						break;
					int v=a[l]/a[i];
					for(int j=i+1;j<=n;j++)
					{
						if(a[j]-a[i]<d&&a[l]-a[j]<d)
							s++;
						if(s>2)
						{
							break;
						}
					}
				}	
			}
			if(s==2)
				sum++;
		}
		cout<<sum<<endl;
	}
	return 0;
}
