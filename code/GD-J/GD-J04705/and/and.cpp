#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll N=2e5+10,inf=(1ll<<31)-1;
ll n,m,ans,a[N],pre[N],suf[N];

void dfs(ll p,ll s,ll cnt)
{
	if(p>n)
	{ 
		if(cnt==m) ans=max(ans,s);
		return;
	}
	if(cnt<=m) dfs(p+1,s&a[p],cnt+1);
	dfs(p+1,s,cnt);
}

bool chk2(ll x)
	{return __builtin_popcountll(x)==1;}
bool chkA()
{
	for(ll i=1;i<=n;i++)
		if(!chk2(a[i]+1))
			return false;
	return true;
}

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0); 
	cin>>n>>m;
	for(ll i=1;i<=n;i++)
		cin>>a[i];
	if(n<=20) dfs(1,inf,0);
	else if(m==1)
	{
		ll mx=0;
		for(ll i=1;i<=n;i++)
			mx=max(mx,a[i]);
		ans=mx;
	}
	else if(m==n)
	{
		ll sum=inf;
		for(ll i=1;i<=n;i++)
			sum=sum&a[i];
		ans=sum;
	}
	else if(m==2&&n<=5000) 
	{
		for(ll i=1;i<=n;i++)
			for(ll j=i+1;j<=n;j++)
				ans=max(ans,a[i]&a[j]);			
	}
	else if(m==n-1)
	{
		pre[0]=suf[n+1]=inf;
		for(ll i=1;i<=n;i++) pre[i]=pre[i-1]&a[i];
		for(ll i=n;i>=1;i--) suf[i]=suf[i+1]&a[i];
		for(ll i=1;i<=n;i++) ans=max(ans,pre[i-1]&suf[i+1]);
	}
	else if(chkA())
	{
		sort(a+1,a+1+n);
		ans=inf;
		cout<<a[n-m+1];
	}
	cout<<ans;
	return 0;
}
