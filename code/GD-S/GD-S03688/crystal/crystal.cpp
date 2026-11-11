#include<bits/stdc++.h>
using namespace std;
long long a[500005],s[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	bool b=true;
	long long n,m,d;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		s[i]=s[i-1]+a[i];
	}
	d=a[2]-a[1];
	for(int i=2;i<=n;i++)
	{
		if(a[i]-a[i-1]!=d) b=false;
	}
	if(b)
	{
		long long l=1,r=m,ans=0;
		while(l<=r)
		{
			int mid=(l+r)/2;
			if(((mid+0)/d)*(mid+1)/2<=m)
			{
				l=mid+1;
				ans=mid;
			}
			else
			{
				r=mid-1;
			}
		}
		cout<<ans;
		return 0;
	}
	long long ans=0;
	for(long long l=1;l<=n;l++)
	{
		for(long long r=l;r<=n;r++)
		{
			if((r-l+1)*a[r]-(s[r]-s[l-1])>m) break;
			ans=max(ans,r-l+1);
		}
	}
	cout<<ans;
	return 0;
}
