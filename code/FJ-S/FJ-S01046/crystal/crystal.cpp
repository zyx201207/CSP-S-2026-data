#include<bits/stdc++.h>
#define int long long
#define N 500005
using namespace std;
int n,m,ans,a[N],b[N];
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) b[i]=b[i-1]+a[i];
	for(int i=1;i<=n;i++)
	{
		int l=1,r=i,mid;
		while(l<r)
		{
			mid=l+r>>1;
			if((i-mid+1)*a[i]-(b[i]-b[mid-1])<=m) r=mid;
			else l=mid+1;
			ans=max(ans,i-r+1);
		}
	}
	cout<<ans;
	return 0;
}

