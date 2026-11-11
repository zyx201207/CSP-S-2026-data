#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int maxn=2e6+5;
ll p[maxn],p1[maxn];
ll f[maxn];
ll pre[maxn];
ll g[maxn];
ll suf[maxn],a[maxn];
int n;
ll d;
bool check(ll x,ll y)
{
	if(y-x>d)return 0;
	return 1;
}
ll ask(ll x)
{
	int p=lower_bound(a,a+n+2,x)-a;
	if(a[p]>x)p--;
	return p;
}
void solve()
{
	
	cin>>n>>d;
	for(int i=1;i<=n;i++)cin>>a[i],p[i]=0,suf[i]=0,p1[i]=0,pre[i]=0,f[i]=g[i]=0;
	int r=n;
	ll ans=0;
	a[0]=-5e18;
	a[n+1]=5e18;
	for(int i=n;i>=1;i--)
	{
		while(a[r]-a[i]>d)r--;
		suf[i]=r;
	}
	int l=1;
	for(int i=1;i<=n;i++)
	{
		while(a[i]-a[l]>d)l++;
		pre[i]=l;
	}
	for(int i=1;i<=n;i++)
	{
		if(pre[i]==i)continue;
		int x=pre[pre[i]],y=pre[i];
		if(check(a[y+1],a[i]) && check(a[x],a[y+1]))p1[i]++;
		if(check(a[y+2],a[i]) && check(a[x],a[y+2]))p1[i]++;
	}
	for(int i=1;i<=n;i++)
	{
		if(suf[i]==i)continue;
		int x=suf[suf[i]],y=suf[i];
		if(check(a[i],a[y-1]) && check(a[y-1],a[x]))p[i]++;
		if(check(a[i],a[y-2]) && check(a[y-2],a[x]))p[i]++;
	}
	for(int i=n;i>=1;i--)
	{
		f[i]++;
		if(suf[i]==i){f[i]=0;continue;}
		if(p[i]>0){f[i]=1;continue;}
		f[i]+=f[suf[i]];
	}
	for(int i=1;i<=n;i++)
	{
		g[i]++;
		if(pre[i]==i){g[i]=0;continue;}
		if(p1[i]>0){g[i]=1;continue;}
		g[i]+=g[pre[i]];
	}
	for(int i=2;i<n;i++)
	{
		if(suf[pre[i]]==i)
		{
			ans+=g[i]*(ask(a[i-1]+d)-ask(a[i-2]+d));
			if(pre[suf[i-1]]==i-1)ans-=1;
		}
		if(pre[suf[i]]==i)
		{
			ans+=f[i]*(ask(a[i+2]-d-1)-ask(a[i+1]-d-1));
		}
		/*if(p[i]==1)
		{
			if(p[pre[i]]==0)
			{
				ans+=g[i]*(f[suf[i]]-1);
			}
		}*/
	//	cout<<ans<<" "<<g[i]*(ask(a[i-1]+d)-ask(a[i-2]+d))<<" "<<f[i]*(ask(a[i+2]-d-1)-ask(a[i+1]-d-1))<<"\n";
	}
	cout<<ans<<"\n";
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--)solve();
	return 0;
}
