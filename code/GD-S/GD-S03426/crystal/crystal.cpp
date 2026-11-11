#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e6;
int a[N],sum[N];
int n,m;
bool cheak(int x)
{
	if(x==1)return true;
	for(int i=x;i<=n;i++)
	{
		int q=a[i]*x;
		int shi=(sum[i]-sum[i-x]);
		int ned=q-shi;
		if(ned<=m)return true;
	}
	return false;
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	sum[0]=0;
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
	int l=0,r=n,ans=0;
	while(l<=r)
	{
		int mid=(l+r)/2;
		if(cheak(mid))
		{
			ans=mid;
			l=mid+1;
		}
		else r=mid-1;
	}
	cout<<ans;
}
