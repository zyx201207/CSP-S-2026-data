#include<bits/stdc++.h>
using namespace std;
using i64=int64_t;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,ans=0;
	i64 m;
	cin>>n>>m;
	int l=1,r=n;
	vector<i64> a(n+1),pre(n+1);
	for (int i=1;i<=n;i++)
		cin>>a[i];
	sort(a.begin()+1,a.end());
	for (int i=1;i<=n;i++)
		pre[i]=pre[i-1]+a[i];
	while (l<=r)
	{
		int mid=(l+r)>>1;
		if ([&]()
		{
			for (int i=1;i<=n-mid+1;i++)
				if (1ll*mid*a[i+mid-1]-(pre[i+mid-1]-pre[i-1])<=m) return true;
			return false;
		}()) l=mid+1,ans=l-1;
		else r=mid-1;
	}
	cout<<ans<<'\n';
}
