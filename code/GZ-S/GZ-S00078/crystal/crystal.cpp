//GZ-S00078 贵阳市新世界学校 王正彭 
#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[1000005],h[1000005];
ll n,m,ans=1;
bool check(ll r,ll l)
{
	return (a[r]*(r-l)-(h[r-1]-h[l-1])<=m);
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	
	sort(a+1,a+n+1);

	for(int i=1;i<=n;i++)
		h[i]=h[i-1]+a[i];
	ll L=1,R=n; 
	while(L<=R)
	{
		ll Mid=(L+R)/2;
		ll l=1,r=Mid;
		while(l<=r)
		{
			ll mid=(l+r)/2;
			if(check(Mid,mid))
			{
				r=mid-1;
				ans=max(ans,Mid-mid+1);
			}
			else
				l=mid+1;
		}
		if(l==1)
			L=Mid+1;
		else
			R=Mid-1;
	}
	cout<<ans<<'\n';
	/*for(int i=n;i>1;i--)
	{
		ll x=m,j=i-1,sum=1;
		while(x&&j>=1)
		{
			if(x>=a[i]-a[j])
			x-=a[i]-a[j],sum++;
			j--;
		}
		ans=max(ans,sum);
	}
	cout<<ans<<'\n';*/
	return 0;
}
