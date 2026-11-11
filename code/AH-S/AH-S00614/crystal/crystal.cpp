#include<bits/stdc++.h>
using namespace std;
long long a[500005],b[500005],m;
int n;
int Find(int x)
{
	int l=x,r=n+1;
	while(l+1<r)
	{
		int mid=(l+r)/2;
		if(a[x]*(mid-x)-(b[mid]-b[x])<=m)
			l=mid;
		else
			r=mid;
	} 
	return l;
}
bool cmp(long long x,long long y)
{
	return x>y;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++)
		b[i]=b[i-1]+a[i];
	a[n+1]=1000000000000000;
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		int sum=Find(i)-i+1;
		ans=max(ans,sum);
	}
	printf("%d",ans);
	return 0;
} 
