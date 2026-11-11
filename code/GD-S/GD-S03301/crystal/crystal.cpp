#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 500005
int n,m,a[N],b[N];
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) b[i]=b[i-1]+a[i];
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		int l=1,r=i;
		while(l<r)
		{
			int mid=l+r>>1;
			int s=i-mid+1;
			int val=s*a[i]-(b[i]-b[mid-1]);
			if(val<=m) r=mid;
			else l=mid+1;
		}
		ans=max(ans,i-l+1);
	}
	cout<<ans;
	return 0;
}
/*
5 8
-3 -1 2 2 7
*/
