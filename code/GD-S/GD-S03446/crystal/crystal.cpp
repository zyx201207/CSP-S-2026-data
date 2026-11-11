#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=500010;
int a[N],s[N];
int n,m;
bool check(int x)
{
	for(int i=x;i<=n;++i)
	{
		int k=s[i]-s[i-x];
		if(a[i]*x-k<=m) return true;
	}
	return false;
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;++i)
	{
		s[i]=s[i-1]+a[i];
	}
	int l=1,r=n,ans=1;
	while(l<=r)
	{
		int mid=l+(r-l)/2;
//		cout<<l<<' '<<r<<' '<<mid<<'\n';
		if(check(mid))
		{
			ans=mid;
			l=mid+1;
		}
		else r=mid-1;
	}
	cout<<ans;
	return 0;
}
