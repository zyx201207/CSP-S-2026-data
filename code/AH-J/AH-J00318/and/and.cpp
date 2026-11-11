#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,ma=LLONG_MIN,a[200005];
void dfs(ll cur,ll s,ll numb)
{
	if(s==m)
	{
		ma=max(ma,numb);
		return ;
	}
	if(cur>n)
	{
		if(s==m)	ma=max(ma,numb);
		return ;
	}
	if(numb==-1)	dfs(cur+1,s+1,a[cur]);
	else	dfs(cur+1,s+1,numb&a[cur]);
	dfs(cur+1,s,numb);
}
ll check()
{
	ll i;
	for(i=1;i<=n;i++)
	{
		if(((a[i]+1)&a[i])!=0)	return 0;
	}
	return 1;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ll i,j;
	scanf("%lld%lld",&n,&m);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	if(m==1||check()==1)
	{
		ll ma=LLONG_MIN;
		for(i=1;i<=n;i++)
		{
			ma=max(a[i],ma);
		}
		printf("%lld",ma);
	}
	else if(m==2)
	{
		ll ma=LLONG_MIN;
		for(i=1;i<=n;i++)
		{
			for(j=i+1;j<=n;j++)
			{
				ma=max(ma,a[i]&a[j]);
			}
		}
		printf("%lld",ma);
	}
	else if(m==n)
	{
		ll ma=a[1];
		for(i=2;i<=n;i++)
		{
			ma=(ma&a[i]);
		}
		printf("%lld",ma);
	}
	else if(n<=20)
	{
		dfs(1,0,-1);
		printf("%lld",ma);
	}
	return 0;
}
