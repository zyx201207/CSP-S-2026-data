#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500009];
long long c[500009];
long long s[500009];
long long ans=0;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	{
		c[i-1]=a[i]-a[i-1];
		s[i]=s[i-1]+a[i];
	}
	long long l=1,r=n,mid;
	while(l<=r)
	{
		mid=(l+r)/2;
		bool vis=0;
		for(int i=1;i+mid<=n;i++)
		{
			long long gg=(a[i+mid-1]*(mid-1))-(s[i+mid-2]-s[i-1]);
//			cout<<i<<" "<<mid<<"=="<<gg<<"\n";
			if(gg<=m)
			{
				vis=1;
				break;
			}
			
		}
		if(vis)
		{
			ans=max(ans,mid);
			l=mid+1;
		}
		else
		{
			r=mid-1;
		}
	}
	cout<<ans;
	return 0; 
}
