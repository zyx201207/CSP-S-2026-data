#include <bits/stdc++.h>
using namespace std;
long long n,m;
long long ans=-1;
long long ac[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) scanf("%lld",&ac[i]);
	sort(ac+1,ac+n+1);
	for(int i=1;i<=n;i++)
	{
		long long cnt=1,sum=m;
		for(int j=i-1;j>=1;j--)
		{
			sum-=(ac[i]-ac[j]);
			if(sum<0) break;
			cnt++;
		}
		ans=max(ans,cnt);
	}
	cout<<ans;
	return 0;
}
