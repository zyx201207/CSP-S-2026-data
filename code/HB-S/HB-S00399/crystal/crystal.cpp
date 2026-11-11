#include <bits/stdc++.h>
using namespace std;
long long m;
int n;
long long a[500005];
int l,r;
int check(int x)
{
	long long minn=1e18,sum;
	for(int i=x;i<=n;i++)
	{
		sum=0;
		for(int j=i-x+1;j<=i;j++)
			sum+=(a[i]-a[j]);
		minn=min(minn,sum);
	}
	if(minn<=m)
		return 1;
	else
		return 0;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	int l=1,r=n;
	while(l<r)
	{
		int mid=(l+r+1)/2;
		if(check(mid))
			l=mid;
		else
			r=mid-1;
	}
	printf("%d",l);
	return 0;
}
