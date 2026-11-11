#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int maxn=5e5+5;
int a[maxn],sum[maxn];int n,m;
bool check(int x)
{
	int ans=LLONG_MAX;
	for(int i=1;i<=n-x+1;i++)
	{
		ans=min(ans,a[i+x-1]*x-(sum[i+x-1]-sum[i-1]));
	}
	return ans<=m;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)  cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	int l=1,r=n+1;
	while(l!=r-1)
	{
		int mid=(l+r)>>1;
		if(check(mid)) l=mid;
		else r=mid;
	}
	cout<<l;
	return 0;
}

