#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+10;
ll a[N],b[N];
ll n,m,ans,maxn,lx,rx;
bool pd1=true,pd2=true;
ll read()
{
	ll f=1,s=0;
	char ch=getchar();
	while (!isdigit(ch))
	{
		if (ch=='-')
		{
			f=-1;
		}
		ch=getchar();
	}
	while (isdigit(ch))
	{
		s=s*10+ch-'0';
		ch=getchar();
	}
	return f*s;
}
ll change(ll l,ll r,ll cnt,ll d,ll mm)
{
	while (1)
	{
		if (l<lx && r>rx)
		{
			return cnt;
		}
		if (l<lx)
		{
			ll rs=b[r]*(r-d);
			if (mm<rs)
			{
				return cnt;
			}
			mm-=rs;
			cnt+=b[r];
			r++;
			continue;
		}
		if (r>rx)
		{
			ll ls=b[l]*(d-l);
			if (mm<ls)
			{
				return cnt;
			}
			mm-=ls;
			cnt+=b[l];
			l--;
			continue;
		}
		ll ls=b[l]*(d-l);
		ll rs=b[r]*(r-d);
		ll sum=min(ls,rs);
		if (sum>mm)
		{
			return cnt;
		}
		if (ls<=rs)
		{
			mm-=ls;
			cnt+=b[l];
			l--;
		}
		else
		{
			mm-=rs;
			cnt+=b[r];
			r++;
		}
	}
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read();
	m=read();
	ll mins=INT_MAX;
	for (int i=1; i<=n; i++)
	{
		a[i]=read();
		if (a[i]!=i)
		{
			pd1=false;
		}
		if (i>=3)
		{
			if (a[i]-a[i-1]!=a[i-1]-a[i-2])
			{
				pd2=false;
			}
		}
		mins=min(mins,a[i]);
	}
	if (pd1)
	{
		while (m>=0)
		{
			ans++;
			m-=ans;
		}
		printf("%lld\n",ans);
		return 0;
	}
	if (pd2)
	{
		while (m>=0)
		{
			ans++;
			m=m-(a[2]-a[1])*ans;
		}
		printf("%lld\n",ans);
		return 0;
	}
	if (mins>=0)
	{
		mins=0;
	}
	else
	{
		mins=-mins;
	}
	lx=INT_MAX;
	rx=0;
	for (ll i=1; i<=n; i++)
	{
		b[a[i]+mins]++;
		lx=min(lx,a[i]+mins);
		rx=max(rx,a[i]+mins);
	}
	for (ll i=lx; i<=rx; i++)
	{
		maxn=max(maxn,b[i]);
	}
	for (ll i=lx; i<=rx; i++)
	{
		if (b[i]==maxn)
		{
			ans=max(change(i-1,i+1,b[i],i,m),ans);
		}
	}
	printf("%lld\n",ans);
	return 0;
}
