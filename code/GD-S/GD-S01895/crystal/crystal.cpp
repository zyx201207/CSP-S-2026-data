#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int a[N];
int s[N];
int n,m;
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		s[i]=s[i-1]+a[i];
	}
	int r=1;
	int ans=0;
	for(int l=1;l<=n;l++)
	{
		if(r<l) r=l;
		while(r<n&&(r+1-l+1)*a[r+1]-(s[r+1]-s[l-1])<=m) r++;
		ans=max(ans,r-l+1);
	}
	cout<<ans;
	return 0;
}
/*
操作只能加，那么目标能量值由最大值决定 
先排序，因为若不是连续的，一定不优
那么对于一段区间 [l,r]，使所有元素相同->所有都变成 a[r]
操作代价为 (r-l+1)*a[r]-sum[l,r]
*/
