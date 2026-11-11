#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,l=1,num,ans,a[500100];
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0); 
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int r=1;r<=n;r++)
	{
		num+=(a[r]-a[r-1])*(r-l);
		while(l<=r&&num>m)
		{
			num-=(a[r]-a[l]);
			l++;
		}
		ans=max(ans,r-l+1);
	}
	cout<<ans;
	return 0;
}
