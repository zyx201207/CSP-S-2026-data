#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+7;
int n,m,a[N],sum[N],ans;
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	int i,j,k,l,r,mid;
	for(i=1;i<=n;i++) cin >> a[i];
	sort(a+1,a+1+n);
	for(i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	for(i=1;i<=n;i++)
	{
		l=0,r=i;
		while(l+1<r)
		{
			mid=(l+r)>>1;
			if(a[i]*(i-mid+1)-sum[i]+sum[mid-1]>m) l=mid;
			else r=mid;
		}
		ans=max(ans,i-r+1);
	}
	cout << ans;
	return 0;
} 
