#include<bits/stdc++.h>
#define ll long long
#define int ll//#
#define db double
#define all(x) x.begin(),x.end()
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
using namespace std;
const int inf=2e9;
const db eps=1e-7;
const int mod=1e9+7;
int n,m,a[500005],d[500005];
int sum2[500005],sum[500005];
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<n;i++)
	{
		d[i]=a[i+1]-a[i];
		sum[i]=sum[i-1]+d[i];
		sum2[i]=sum2[i-1]+a[n]-a[i];
//		cerr<<sum2[i]<<" ";
	}
//	cerr<<"\n";
	sum[n]=sum[n-1];
	sum2[n]=sum2[n-1];
	int aans=0;
	for(int i=n;i>=1;i--)
	{
		int l=1,r=i,mid,ans=-1;
		while(l<=r)
		{
			mid=(l+r)>>1;
			if(sum2[i]-sum2[mid-1]-(a[n]-a[i])*(i-mid+1)<=m)
			{
				r=mid-1;
				ans=mid;
			}
			else l=mid+1;
		}
//		cerr<<i<<" "<<ans<<"\n";
		aans=max(aans,i-ans+1);
	}
	cout<<aans;
	return 0;
}

