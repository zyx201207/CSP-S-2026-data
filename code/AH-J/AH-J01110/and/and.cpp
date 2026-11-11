#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll s,n,m,c,a[200010],jz[200010],v=1;
int mmm=INT_MIN;
ll dfs(ll x,ll s)
{
	c++;
	if(c>m)
	{
		v+=m;
		ll t=s;
		s=0;
		return t;
	}
	s=s&a[x];
	return max(dfs(x+1,s),dfs(x+v,s));
}
int main ()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(ll i=1;i<=n-m+1;i++)
	{
		s=a[i];
		c=1;
		v=0;
		ll F=dfs(i+1,s);
		if(F>mmm)
		{
			mmm=F;
		}
	}
	cout<<mmm;
}
