#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=200005;
ll n,m,a[N],vis[N];
ll maxn=-1;
long long cnt=-2;
void dfs(int pos,long long ans)
{
	if(pos==m+1)
	{
		cnt=max(cnt,ans);
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			vis[i]=1;
			dfs(pos+1,(ans & a[i]));
			vis[i]=0;
		}
	}
}
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		maxn=max(maxn,a[i]);
	}
	if(n<=20)
	{
		for(ll i=1;i<=n;i++)
		{
			vis[i]=1;
			dfs(2,a[i]);
			memset(vis,0,sizeof(vis));
		}
		cout<<cnt;
		return 0;
	}
	else if(m==1)
	{
		cout<<maxn;
		return 0;
	}
	else if(m==n)
	{
		ll fen2=a[1];
		for(ll i=2;i<=n;i++)
		{
			fen2=(fen2 & a[i]);
		}
		cout<<fen2;
		return 0;
	}
	else if(m==2)
	{
		ll fen3=-1;
		for(ll i=1;i<=n;i++)
		{
			for(ll j=1;j<=n;j++)
			{
				if(i!=j)
				{
					fen3=max(fen3,(a[i] & a[j]));
				}
			}
		}
		cout<<fen3;
		return 0;
	}
	return 0;
}
