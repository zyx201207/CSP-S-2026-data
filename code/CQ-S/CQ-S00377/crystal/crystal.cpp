#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
long long n,m,res=0,a[500005],sum[500005]; 
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(long long i=1;i<=n;i++)
	{
		sum[i]=sum[i-1]+a[i];
		long long l=1,r=i,ans=i;
		while(l<=r)
		{
			long long mid=(l+r)>>1;
			if(a[i]*(i-mid+1)-sum[i]+sum[mid-1]<=m)
			{
				ans=mid;
				r=mid-1;
			}
			else
			{
				l=mid+1;
			}
		}
		res=max(res,i-ans+1);
	}
	cout<<res<<endl;
	return 0;
}
