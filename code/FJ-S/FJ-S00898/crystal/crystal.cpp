#include<bits/stdc++.h>
using namespace std;
int n,l,r,mid,ans=1;
long long m,a[500010],s[500010];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		s[i]=s[i-1]+a[1]-a[i];
	}
	for(int i=2;i<=n;i++)
	{
		l=1;
		r=i;
		while(l<r)
		{
			mid=(l+r)/2;
			if(s[i]-s[mid-1]+(a[i]-a[1])*(i-mid+1)<=m)
			{
				r=mid;
			}
			else l=mid+1;
		}
		ans=max(ans,i-l+1);
	}
	cout<<ans;
}
