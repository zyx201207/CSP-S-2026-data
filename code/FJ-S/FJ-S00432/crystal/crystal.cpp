#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500010],ans,s,l;
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	ans=1;l=1;
	for (int r=2;r<=n;r++)
	{
		s+=(r-l)*(a[r]-a[r-1]);
		while (l<r && s>m)
		{
			s-=(a[r]-a[l]);++l;
		}
		ans=max(ans,r-l+1);
	}
	cout<<ans;
	return 0;
}
