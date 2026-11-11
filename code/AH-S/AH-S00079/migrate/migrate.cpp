#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,T;
int n,m;
int ans=0;
int a[2000010]={0};
int cnt[2000010]={0};
int fa[2000010]={0};
int find(int x)
{
	if(fa[x]==x)
	{
		return x;
	}
	else
	{
		fa[x]=find(x);
		return fa[x];
	}
}
void solve()
{
	int l=1;
	int r=3;
	for(int i=2;i<=n;i++)
	{
		while(a[l]+m<a[i])
		{
			l++;
		}
		while(a[i]+m>=a[r+1]&&r<n)
		{
			r++;
		}
		fa[find(i)]=find(l);
		fa[find(r)]=find(l);
		ans-=r-l;
	}
}
signed main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--)
	{
		ans=0;
		cin>>n>>m;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			fa[i]=i;
			cnt[i]=0;
		}
		solve();
		ans*=2;
		for(int i=1;i<=n;i++)
		{
			cnt[find(i)]++;
		}
		for(int i=1;i<=n;i++)
		{
			ans+=cnt[i]*(n-cnt[i]);
		}
		ans/=2;
	}
	return 0;
}
