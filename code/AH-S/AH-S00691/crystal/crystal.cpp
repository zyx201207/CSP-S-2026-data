#include <bits/stdc++.h>
using namespace std;
struct su{
	long long id,sum;
}st[2];
long long n,a[500000],maxn=LONG_LONG_MIN,minn=LONG_LONG_MAX;
long long tot,ans,m,ans2;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	st[0].sum=LONG_LONG_MIN;
	st[1].sum=1;
	for(long long i=0; i<n; i++)
	{
		scanf("%lld",&a[i]);
		tot+=a[i];
		maxn=max(maxn,a[i]);
		minn=min(minn,a[i]);
	}
	sort(a,a+n);
	for(int i=n-1; i>0; i--)
	{
		if(a[i]==a[i-1])
		{
			st[1].sum++;
			st[1].id=a[i];
		} else {
			st[1].sum=1;
			st[1].id=a[i];
		}
		if(st[0].sum<st[1].sum)
		{
			st[0].sum=st[1].sum;
			st[0].id=st[1].id;
		}
	}
	tot=tot-minn-maxn;
	tot/=(n-2);
	if(st[0].sum>1)
	{
		ans=st[0].sum;
	}
	for(long long i=0; i<n; i++)
	{
		if(a[i]<=tot&&m-(tot-a[i])>=0)
		{
			ans2++;
			m-=(tot-a[i]);
		} 
	}
	cout<<max(ans,ans2);
	return 0;
}
