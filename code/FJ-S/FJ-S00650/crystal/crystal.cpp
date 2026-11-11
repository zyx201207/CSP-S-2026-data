#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[500010],sum[500010];
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,m,ans=0;cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
	for(int i=1,st=1;i<=n;i++)
	{
		while((a[i]*(i-st+1))-(sum[i]-sum[st-1])>m)st++;
		ans=max(ans,i-st+1);
	}
	cout<<ans;
	return 0;
}
