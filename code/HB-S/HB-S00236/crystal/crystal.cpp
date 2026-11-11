#include <bits/stdc++.h>
using namespace std;
const int maxn=5e5+5;
long long n,m,cost,ans=2,a[maxn],b[maxn],c[maxn],d[maxn];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	{
		b[i]=a[i+1]-a[i];
		c[i]=c[i-1]+b[i];
		d[i]=d[i-1]+i*b[i];
	}
	for(long long l=1;l<n;l++)
	{
		for(long long k=ans;k<=n-l+1;k++)
		{
			long long r=l+k-1;
			cost=d[r-1]-d[l-1]-(l-1)*(c[r-1]-c[l-1]);
			if(cost>m) break;
			ans=max(ans,k);
		}
	}
	cout<<ans;
	return 0;
}
