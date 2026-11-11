#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500010],sum[500010],maxx;
bool check(int l,int r)
{
//	cout<<l<<" "<<r<<":"<<a[r]*(r-l+1)-(sum[r]-sum[l-1])<<'\n';
	if(a[r]*(r-l+1)-(sum[r]-sum[l-1])<=m)
	{
		return true;
	}
	return false;
}
void erfen(int x)
{
	int l=1,r=x,mid,ans;
	while(l<=r)
	{
		mid=(l+r)>>1;
		if(check(mid,x))
		{
			r=mid-1;
			ans=mid;
		}
		else
		{
			l=mid+1;
		}
	}
	maxx=max(maxx,x-ans+1);
//	cout<<x<<" "<<ans<<'\n';
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	{
		sum[i]=sum[i-1]+a[i];
//		cout<<sum[i]<<" "; 
	}
//	cout<<'\n';
	for(int i=1;i<=n;i++)
	{
		erfen(i);
	}
	cout<<maxx;
	return 0;
}
