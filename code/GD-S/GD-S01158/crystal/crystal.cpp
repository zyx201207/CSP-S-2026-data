#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=5e5+5;
int a[maxn],n,m;
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)a[i]=a[i]+a[i-1];
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		int l=0,r=i+1,now=a[i]-a[i-1];
		while(l+1<r)
		{
			int mid=((l+r)>>1);
			int len=(i-mid+1);
			if(len*now-(a[i]-a[mid-1])<=m)r=mid;
			else l=mid;
		}
		ans=max(ans,i-r+1);
	}
	cout<<ans;
	return 0;
}
/*
AliceInCradle
*/
