#include<bits/stdc++.h>
// at 15:00
#define N 500005
using namespace std;
typedef long long ll;

ll n,m,a[N],sum[N],ans;

bool check(int l,int r)
{
	ll s=sum[r]-sum[l-1];
	ll ans=(r-l+1)*a[r];
	return ans-s<=m;
}

int query(int u,int l,int r)
{
	l--,r++;
	while(l+1<r)
	{
		int mid=(l+r)>>1;
		if(check(u,mid))
			l=mid;
		else
			r=mid;
	}
	return max(u,l);
}

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	stable_sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
	for(int i=1;i<=n;i++)
	{
		int pos=query(i,i,n);
		ans=max(ans,pos-i+1LL);
		// cout<<pos<<' ';
	}
	cout<<ans;
	return 0;
}