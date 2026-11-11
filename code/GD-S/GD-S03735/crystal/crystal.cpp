#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],s[500005],k;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		s[i]=s[i-1]+a[i];
		long long l=0,r=i,mid;
		while(l+1<r)
		{
			mid=(l+r)/2;
			if(a[i]*(i-mid+1)-(s[i]-a[mid-1])>m)
				l=mid;
			else r=mid;
		}
		k=max(k,i-r+1);
	}
	cout<<k;
	return 0;
} 
