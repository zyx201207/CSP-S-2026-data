#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500010],sum[500010];
bool check(int x)
{
	for(int i=x;i<=n;i++)
	{
		if(a[i]*x-(sum[i]-sum[i-x])<=m) return 1;
	}
	return 0;
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
		sum[i]=sum[i-1]+a[i];
	int l=1,r=n;
	while(l<r)
	{
		int mid=(l+r+1)>>1;
		if(check(mid)) l=mid;
		else r=mid-1;
		//cout<<l<<r<<endl;
	}
	cout<<l<<endl;
	
	return 0;
}
