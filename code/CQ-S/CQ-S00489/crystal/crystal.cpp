#include <bits/stdc++.h>
using namespace std;
#define int long long

int a[500005];

signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie();
	cout.tie();
	int n,m;
	cin>>n>>m;
	for(int i=1; i<=n; i++) cin>>a[i];
	sort(a+1,a+n+1);
	int maxn=0,j=n,cnt=0,sum=0;
	for(int i=n; i>=1; i--)
	{
		while(sum+a[i]-a[j]<=m && j>=1) sum+=a[i]-a[j],cnt++,j--;
		maxn=max(maxn,cnt),sum-=(a[i]-a[i-1])*(cnt-1),cnt--;
	}
	cout<<maxn;
	return 0;
}

