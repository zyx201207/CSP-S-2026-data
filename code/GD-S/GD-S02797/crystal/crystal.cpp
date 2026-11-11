#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN=5e5+10;
int n,m;
int arr[MAXN];
int ans,sum[MAXN];
bool check(int x)
{
	for(int l=1;l<=n-x+1;l++)
	{
		int r=l+x-1;
		if(x*arr[r]-(sum[r]-sum[l-1])<=m)
			return true;
	}
	return false;
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>arr[i];
	if(m==0)
	{
		cout<<0<<endl;
		return 0;
	}
	sort(arr+1,arr+n+1);
	for(int i=1;i<=n;i++)
		sum[i]=sum[i-1]+arr[i];
	
	int l=1,r=5e5+10;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(check(mid))
		{
			ans=mid;
			l=mid+1;
		}
		else
		{
			r=mid-1;
		}
	}
	cout<<ans<<endl;
	return 0;
}
