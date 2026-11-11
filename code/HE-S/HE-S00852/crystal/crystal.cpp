#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m,a[N],sum[N]; 
bool check(int pos,int mid)
{
	int k=sum[pos]-sum[pos-mid];
	int s=mid*a[pos];
	if (s-k<=m) return 1;
	return 0;
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin >> n >> m;
	for (int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	for (int i=1;i<=n;i++)
		sum[i]=sum[i-1]+a[i];
	int ans=0;
	for (int i=1;i<=n;i++)
	{
		int l=1,r=i;
		int ret=0;
		while (l<=r)
		{
			int mid=(l+r)>>1;
			if (check(i,mid)) ret=mid,l=mid+1;
			else r=mid-1;
		}
		ans=max(ans,ret);
	}
	cout << ans;
}
/*
1.最终相同的一定是某个a[i] 
2.枚举a[i],考虑二分
注意边界:全满足条件，全不满足条件 

freopen
多测清空 

5 5
1 2 4 8 9

5 8
-3 -1 2 2 7

5 0
1 2 3 4 5

 
100pts? 
*/ 
