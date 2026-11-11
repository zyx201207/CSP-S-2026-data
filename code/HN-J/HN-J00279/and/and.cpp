#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;
ll n,m;
ll a[N];
ll maxn=-1e9;
ll maxm=-1e9;
ll maxl=-1e9;
ll x,y;
void dfs(ll x,ll sum,ll cnt)
{
	if(x==n+1)
	{
		if(cnt==m)
		{
			if(sum>maxm)
			{
				maxm=sum;
			}
		}
		return ;
	}
	dfs(x+1,sum&a[x],cnt+1);
	dfs(x+1,sum,cnt);
}

signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n<=20)
	{
		for(int i=1;i<=n;i++)
		{
			dfs(1,a[i],0);
			maxn=max(maxm,maxn);
		}
		cout<<maxn;
		return 0;
	}
	else if(m==1)
	{
		for(int i=1;i<=n;i++) maxl=max(maxl,a[i]);
		cout<<maxl;
		return 0;
	}
	else if(m==n)
	{
		ll sum=a[1];
		for(int i=2;i<=n;i++) sum=sum&a[i];
		cout<<sum;
		return 0;
	}
	else
	{
		sort(a+1,a+n+1);
		cout<<a[n-(m-1)];
	}
	return 0;
}
/*

*/
