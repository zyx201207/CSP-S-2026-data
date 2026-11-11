#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long a[N];
long long sum[N];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	long long m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]),sum[i]=sum[i-1]+a[i];
	sort(a+1,a+n+1);
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		int l=1,r=i-1;
		while(l<r)
		{
			int mid=(l+r-1)/2;
			if(a[i]*(i-1-mid+1)-sum[i-1]+sum[mid-1]<=m)
				r=mid;
			else
				l=mid+1;
		}
		ans=max(ans,i-l+1);
	}
	cout<<ans;
	
	return 0;
}
