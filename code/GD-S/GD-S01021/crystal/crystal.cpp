#include<bits/stdc++.h>
#define int long long
using namespace std;

int n,m,ans,a[500010];

signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	int r=0,sumx=0;
	for(int l=1;l<=n;l++)
	{
		while(r<n && sumx+(r-l+1)*(a[r+1]-a[r])<=m)
		{
			sumx+=(r-l+1)*(a[r+1]-a[r]);
			r++;
		}
		ans=max(ans,r-l+1);
		sumx-=a[r]-a[l];
	}
	cout<<ans<<'\n';
	return 0;
}
