#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500010];
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	int l=n,r=n,cnt=m,ans=0;
	while(r>=1)
	{
		l=min(l,r);
		while(l>1 && cnt-(a[r]-a[l-1])>=0) cnt-=a[r]-a[--l];
		ans=max(ans,r-l+1);
		cnt+=(r-l)*(a[r]-a[r-1]);
		r--;
	}
	cout<<ans;
	return 0;
} 
