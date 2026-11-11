#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int N=5e5+5;
int a[N],n,m,ans;
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)	cin>>a[i];
	sort(a+1,a+n+1);
	int l=1,r=1,sum=0;
	while(r<=n)
	{
		while(sum+(a[r+1]-a[r])*(r-l+1)<=m&&r<=n)	sum+=(a[r+1]-a[r])*(r-l+1),r++;
		ans=max(ans,r-l+1);
		sum-=a[r]-a[l],l++;
	}
	cout<<ans;
	return 0;
}
/*
10min total
O(n) 100pts
:)
*/
