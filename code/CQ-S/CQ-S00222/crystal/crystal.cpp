#include<bits/stdc++.h>
using namespace std;
const int N=5e5+1;
long long m,a[N],sum[N],ans;
int n,cnt;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<n;i++)
	{
		ans+=a[n]-a[i];
		sum[i]=sum[i-1]+a[i];
	}
	if(ans<=m)
	{
		cout<<n;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		int l=i,r=n,mid;
		while(l<=r)
		{
			mid=(l+r)>>1;
			if((mid-1)*1ll*a[mid]-sum[mid-1]<=m) l=mid+1;
			else r=mid-1;
		}
		cnt=max(cnt,l-i);
	}
	cout<<cnt;
	return 0;
}
