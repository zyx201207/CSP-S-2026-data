#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN=5e5+10;
constexpr int ICANDOTHEMAX=3e5+10;

int n,m;
int a[MAXN],las[MAXN],vis[MAXN],nex[MAXN],d[MAXN];
int ans[MAXN];

signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i) cin>>a[i];
	for(int i=n;i>=1;--i)
	{
		if(vis[a[i]]==0)
		{
			las[a[i]]=i;
			nex[i]=nex[i+1];
			if(nex[i+1]==0) nex[i]=i+1;
		}
		vis[a[i]]=1;
	}
	if(n>ICANDOTHEMAX)
	{
		for(int i=1;i<=n;++i)
		{
			if(i==n) ++ans[a[n]];
			for(int j=i;j<n;)
			{
				if(j==las[a[j]])
				{
					d[j]+=1;
					j=nex[j];
					d[j]-=1;
				}
				else
				{
					j=las[a[j]];
					++ans[a[j]];
					++j;
				}
			}
		}
		int now=0;
		for(int i=1;i<=n;++i)
		{
			now+=d[i];
			ans[a[i]]+=now;
		}
	}
	else
	{
		for(int i=1;i<=n;++i)
		{
			for(int j=las[a[i]];j<n;j=las[a[j]])
			{
				++ans[a[j]];
				++j;
			}
			++ans[a[n]];
		}
	}
	for(int i=1;i<=m;++i) cout<<ans[i]<<" ";
	return 0;
}