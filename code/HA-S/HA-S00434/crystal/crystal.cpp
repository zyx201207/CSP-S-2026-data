#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,a[500086],m,ma=-1e9,mi=1e9,ans;
ll check(ll x)
{
	ll sum=0;
	for(int i=1;i<=n;i++)
	{
		if(x-a[i]<0) return sum;
		sum+=x-a[i];
		if(sum==m) return sum;
	}
	return sum;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i],ma=max(ma,a[i]),mi=min(mi,a[i]);
	sort(a+1,a+1+n);
	if(ma<=10086)
	{
		for(int i=mi;i<=ma;i++)
		{
			ll sum=0,x=m;
			int s=upper_bound(a+1,a+1+n,i)-a;
			for(int j=s-1;j>0;j--)
			{
				if(x-i+a[j]>=0) x=x-(i-a[j]),sum++;
			}
			ans=max(ans,sum);
		}
		cout<<ans;
	}
	else
	{
		ll l=1,r=n,mid;
		while(l<=r)
		{
			mid=(l+r)>>1;
			if(check(a[mid])>m) r=mid-1;
			else if(check(a[mid])<m) l=mid+1;
			else break;
		}
		for(int i=r;i>0;i--)
		{
			if(m>=a[r]-a[i]) m-=(a[r]-a[i]),ans++;
			else break;
		}
		cout<<ans;
	}
	return 0;
}
