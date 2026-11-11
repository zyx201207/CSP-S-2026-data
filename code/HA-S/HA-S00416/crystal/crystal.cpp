#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=500010;
int n,m,a[N],sum[N],maxx;
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
	for(int l=1,r=1;r<=n;r++)
	{
		while(sum[r]-sum[l-1]+m<a[r]*(r-l+1))l++;
		maxx=max(maxx,r-l+1);
	}
	cout<<maxx;
	return 0;
}
