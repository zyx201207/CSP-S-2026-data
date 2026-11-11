#include<bits/stdc++.h>
using namespace std;
long long n,m,a[550000],b[550000],ans=1;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		b[i]=b[i-1]+a[i];
	for(int i=2;i<=n;i++)
	{
		long long l=1,r=i;
		while(l<r)
		{
			long long mid=(l+r)/2;
			if(a[i]*(i-mid+1)-(b[i]-b[mid-1])>m)
				l=mid+1;
			else if(a[i]*(i-mid+1)-(b[i]-b[mid-1])<m)
				r=mid;
			else
				l=r=mid;
		}
		ans=max(i-r+1,ans);
	}
	cout<<ans;
	return 0;
}
