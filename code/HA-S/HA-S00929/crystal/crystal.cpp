#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n,ans;
ll m;
ll a[500010],sum[500010];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	for(int r=n,l=n;r>=1;r--)
	{
		while(l>=1&&(r-l+1)*a[r]-(sum[r]-sum[l-1])<=m) l--;
		ans=max(ans,r-l);
	}
	cout<<ans;
	return 0;
}
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7
*/
