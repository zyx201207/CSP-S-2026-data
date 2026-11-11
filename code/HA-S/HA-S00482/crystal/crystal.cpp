#include<bits/stdc++.h>
using namespace std;
int n,m,mid,l,r,sum,ans,cnt[500005];
int a[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		cnt[i]=cnt[i-1]+a[i];
	}
	for(int i=1;i<=n;i++)
	{
		l=i;
		r=n;
		while(l<=r)
		{
			mid=(l+r)/2;
			sum=0;
			sum=(mid-i)*a[mid]-(cnt[mid-1]-cnt[i-1]);
			if(sum>=m)
			{
				r=mid-1;
			}
			else
			{
				l=mid+1;
			}
		}
		ans=max(mid-i+1,ans);
	}
	cout<<ans;
}
