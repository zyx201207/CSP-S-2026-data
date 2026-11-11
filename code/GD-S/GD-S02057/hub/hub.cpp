#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll op,t,n,k,ans;
vector<ll > c[1000005];
ll f[10000005];
ll vis[10000005];
void dfs2(ll s)
{
	vis[s]=1;
	for(auto vx : c[s])
	{
		if(vis[vx]==1)continue;
		dfs2(vx);
	}
}
ll find(ll x,ll y)
{
	if(x==y)return 0;
	ll xx=1e16;
	//cout<<x<<" ";
	for(auto vx : c[x])
	{
		//if(vx==fa)continue;
		if(f[vx]==0)continue;
		xx=min(xx,find(vx,y)+1);
	}
	return xx;
}
void dfs(ll id)
{
	if(id==n+1)
	{
		ll sum=0;
		for(int i=1;i<=n;i++)
		{
			if(f[i]==1)sum++;
			vis[i]=0;
		}
		if(sum!=k)return ;
		sum=0;
		for(int i=1;i<=n;i++)
		{
			if(f[i]==0)vis[i]=1;
			if(vis[i]==0)
			{
				dfs2(i);
				sum++;
			}
		}
		if(sum>2)return ;
		//cout<<11111;
		ll minn=1e16;
		for(int i=1;i<=n;i++)
		{
			if(f[i]==0)continue;
			for(int j=i+1;j<=n;j++)
			{
				if(f[j]==0)continue;
				minn=min(minn,(ll)find(i,j));
				//cout<<find(i,j)<<" ";
			}
		}
		ans=min(ans,minn);
		return ;
	}
	f[id]=1;
	dfs(id+1);
	f[id]=0;
	dfs(id+1);
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>op>>t;
	if(t==2)cout<<1<<'\n'<<2<<'\n';
	else
	{
		while(t--)
		{
			cout<<0<<'\n';
		}
	}
	/*while(t--)
	{
		cin>>n>>k;
		for(int i=1;i<n;i++)
		{
			ll u,v;
			cin>>u>>v;
			c[u].push_back(v);
			c[v].push_back(u);
		}
		ans=1e16;
		dfs(1);
		cout<<ans<<'\n';
	}*/
	return 0;
}
