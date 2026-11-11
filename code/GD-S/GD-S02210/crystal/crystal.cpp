#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN=5e5+5;
ll absl(ll a)
{
	if(a>=0) return a;
	else
	{
		a*=-1;
		return a;
	}
}
int n;
ll m;
ll a[MAXN];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	ll mu=m;
	ll t=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		t+=a[i];
	}
	sort(a+1,a+n+1);
	t/=n;
	ll minn=1e18;
	int x,u=-1;
	for(int i=1;i<=n;i++)
	{
		ll y=absl(t-a[i]);
		if(y<minn)
		{
			x=i;
			minn=y;
		}
		else if(y==minn&&a[x]!=a[i])
		{
			u=i;
			break;
		}
		else if(y>minn) break;
	}
	int ans=1;
	int l=x-1,r=x+1;
	while(a[l]==a[x]) l--,ans++;
	while(a[r]==a[x]) r++,ans++;
	cout<<x<<' '<<a[x]<<' '<<a[l]<<' '<<a[r]<<'\n';
	while(l>=1||r<=n)
	{
		ll yl=absl(a[x]-a[l]),yr=absl(a[x]-a[r]);
		if(yl<yr)
		{
			if(m>=yl)
			{
				ans++;
				m-=yl;
				l--;
			}
			else break;
		}
		else
		{
			if(m>=yr)
			{
				ans++;
				m-=yr;
				r++;
			}
			else break;
		}
	}
	if(u==-1) cout<<ans;
	else
	{
		int ansu=1;
		l=u-1;
		r=u+1;
		while(a[l]==a[u]) l--,ansu++;
		while(a[r]==a[u]) r++,ansu++;
		while(l>=1||r<=n)
		{
			ll yl=absl(a[u]-a[l]),yr=absl(a[u]-a[r]);
			if(yl<yr)
			{
				if(mu>=yl)
				{
					ansu++;
					mu-=yl;
					l--;
				}
				else break;
			}
			else
			{
				if(mu>=yr)
				{
					ansu++;
					mu-=yr;
					r++;
				}
				else break;
			}
		}
		cout<<max(ans,ansu);
	}
	return 0;
}
