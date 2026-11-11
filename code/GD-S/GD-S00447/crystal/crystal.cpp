#include <bits/stdc++.h>
using namespace std;
int n,ans;
long long m,a[500005],sum;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int l=1,r=1;
	while(l<=r&&r<=n)
	{
		if(sum<=m)
		{
			ans=max(ans,r-l+1);
			r++;
			sum+=(a[r]-a[r-1])*(r-l);
		}
		else
		{
			l++;
			sum-=(a[r]-a[l-1]);
		}
	}
	cout<<ans;
	return 0;
}
