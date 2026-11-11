#include<bits/stdc++.h>
#define int long long
#define inf 1000000000000000000ll
#define pii pair<int,int>
#define lowbit(x) (x&(-x))
using namespace std;
const int Maxn=5e5+5;
int n,m,a[Maxn],sum[Maxn];
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	int ans=-inf;
	for(int i=1;i<=n;i++)
	{
		int l=0,r=i-1,re=0;
		while(l<=r)
		{
			int mid=(l+r)/2;
			if(mid*a[i]-(sum[i-1]-sum[i-mid-1])<=m)
			{
				re=mid;
				l=mid+1;
			}
			else r=mid-1;
		}
		ans=max(ans,re+1);
	}
	cout<<ans<<'\n';
	return 0;
}
/*
5 5
1 2 4 8 9

3

5 8
-3 -1 2 2 7

4
*/

// 100