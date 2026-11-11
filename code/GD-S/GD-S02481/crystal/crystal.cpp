#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
typedef long long ll;
ll n,m,ans=0,a[N],s[N],c[N]={0},spc,b=1;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		if(i==2)
		{
			spc=a[2]-a[1];
		}
		if(i>2 && a[i]-a[i-1]!=spc)
		{
			b=0;
		}
	}
	if(b)
	{
		ll i=1,sum=0;
		while(sum<=m && i<=n)
		{
			sum+=spc*i;
			i++;
		}
		cout<<i-1;
		return 0;
	}
	sort(a+1,a+1+n);
	for(int i=1;i<n;i++)
	{
		s[i]=a[i+1]-a[i];
		c[i]=c[i-1]+s[i];
	}
	ll sum=0;
	for(ll l=1,r=2;r<=n;r++)
	{
		sum+=s[r-1]*(r-l);
		if(sum<=m)
		{
			ans=max(ans,r-l+1);
		}
		else
		{
			while(sum>m)
			{
				sum-=c[r-1]-c[l-1];
				l++;
			}
		}
		if(r==n)
		{
			while(sum>m)
			{
				sum-=c[r-1]-c[l-1];
				l++;
			}
			ans=max(ans,r-l+1);
		}
	}
	printf("%lld",ans);
	return 0;
}
