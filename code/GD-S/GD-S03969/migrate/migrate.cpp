#include<bits/stdc++.h>
using namespace std;
long long a[2000005];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--)
	{
		long long n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		if(n==1)
		{
			cout<<0<<'\n';
			return 0;
		}
		long long k=a[2]-a[1];
		bool f=1;
		for(int i=2;i<=n;i++) if(a[i]-a[i-1]!=k) f=0;
		long long ans=0;
		if(f==1)
		{
			for(int i=1;i<=n;i++)
			{
				if(a[i]+d+1>a[n]) break;
				int it=lower_bound(a+1,a+n+1,a[i]+d+1)-a;
				if(it-i+1<4)
				{
					continue ;
				}
				if((it-i+1)%2==1) continue ;
				int mid=(i+it)/2;
				if(a[it]-a[mid]<=d&&a[it]-a[mid-1]>d) ans++;
			}
			cout<<ans<<'\n';
			continue ;
		}
		for(int i=1;i<=n;i++)
		{
			if(a[i]+d+1>a[n]) break;
			int it=lower_bound(a+1,a+n+1,a[i]+d+1)-a;
			if(it-i+1<4) continue ;
			if(it-i+1==4&&a[it]-a[i+1]<=d&&a[it-1]-a[i]<=d)
			{
				ans++;
				continue ;
			}
			long long mid=(a[i]+a[it])/2;
			int f=lower_bound(a+1,a+n+1,mid)-a;
			if(f==it)
			{
				if(a[it]-a[it-2]<=d&&a[it]-a[it-3]>d) ans++;
				continue ;
			}
			long long x=a[f]-a[f-1],y=a[f+1]-a[f];
			if(a[it]-a[f]>d||a[f]-a[i]>d) continue ;
			if(x==y) continue ;
			if(x>y)
			{
				if(x>d&&y<=d)
				{
					ans++;
				}
			}
			else
			{
				if(x<=d&&y>d)
				{
					ans++;
				}
			}
		}
		cout<<ans<<'\n';
	}
}
