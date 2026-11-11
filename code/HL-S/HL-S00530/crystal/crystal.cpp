#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500005],s[500005];
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	int maxn=0;
	for(int i=1;i<=n;i++)
	{
		s[i]=s[i-1]+a[i];
		int l=1,r=i,ans=i;
		while(l<=r)
		{
			int mid=(l+r)/2;
			if(a[i]*(i-mid+1)-s[i]+s[mid-1]<=m) 
			{
				r=mid-1;
				ans=mid;
			}
			else
			{
				l=mid+1;
			}
		}
		maxn=max(maxn,i-ans+1);
	}
	cout<<maxn;
	return 0;
}