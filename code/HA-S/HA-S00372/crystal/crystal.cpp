#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5,INF=0x3f3f3f3f3f3f3f3f;
int n,m,a[N],sum[N],ans;
bool check(int k)
{
	for(int l=1,r=k;r<=n;l++,r++)
	{
		if((a[r]*k-(sum[r]-sum[l-1])) <= m)
			return 1;
	}
	return 0;
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
		sum[i]=sum[i-1]+a[i];
	int l=1,r=n;
	while(l+1<r)
	{
		int mid=(l+r)>>1;
//		cout<<l<<' '<<mid<<' '<<r<<'\n';
		if(check(mid))
		{
			l=mid;
//			cout<<"Yes\n";
		}
		else
		{
			r=mid;
//			cout<<"No\n";
		}
	}
	if(check(r)) ans=r;
	else ans=l;
	cout<<ans<<'\n';
	return 0;
}

