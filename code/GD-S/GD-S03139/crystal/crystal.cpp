#include<bits/stdc++.h>
using namespace std;
int n,ans;
long long m,a[500010],poi;
long long t[500010];
bool check(int poi)
{
	int num=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]>=a[poi])
		{
			num=i-1;
			break;
		}
	}
	long long sum=0;
	for(int i=1;i<=num;i++)
	{
		sum+=(a[poi]-a[i]);
	}
	if(sum<=m)return 1;
	return 0;
}
int h(int l,int r)
{
	int ans=0;
	while(l<=r)
	{
		int mid=l+(r-l)/2;
		if(check(mid))
		{
			l=mid+1;
			ans=mid;
		}
		else r=mid-1;
	}
	return ans;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	poi=h(1,n);
	for(int i=1;i<=n;i++)
	{
		t[i]=a[poi]-a[i];
	}
	sort(t+1,t+n+1);
	int i=1;
	while(t[i]<0)i++;
	while(m-t[i]>=0 && i<=n)
	{
		m-=t[i];
		i++;
		ans++;
	}
	printf("%d",ans);
	return 0;
} 
