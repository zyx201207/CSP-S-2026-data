#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=5e5+10;
int n,m,a[maxn],sum[maxn],ans=0;
int cal(int l,int i)
{
	return (i-l)*a[i]-(sum[i-1]-sum[l-1]);
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
	int l=1;
	for(int i=1;i<=n;i++)
	{
		while(cal(l,i)>m && l<=i)l++;
		ans=max(ans,i-l+1);
	}
	cout<<ans;
	return 0;
}
