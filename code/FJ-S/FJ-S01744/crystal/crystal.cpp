#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e6 + 33;
int n,m,a[N],sum[N],l,r,now,ans,op;
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(0)->ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	l=1;r=2;
	for(int i=2;i<=n;i++)
	{
	  now+=(i-l)*(a[i]-a[i-1]);
	  while(now>m && l<i) now-=(a[i]-a[l]),l++;
	  ans=max(ans,i-l+1);
	}
	cout<<ans;
	return 0;
}