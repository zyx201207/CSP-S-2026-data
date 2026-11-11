#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e6+5;
ll c,t,n,k,a[N],g[20][20],ans,dep[N];
vector<ll> e[N];
bool v[N],v1[N],v2[N];
void dfs(ll u,ll fa)
{
//	if(t==0)
//	{
//		cout<<u<<' '<<fa<<'\n';
//	}
	for(auto v : e[u])
	{
		if(v==fa)
		{
			continue;
		}
		if(!v2[v]||v1[v])
		{
			continue;
		}
		dfs(v,u);
		v1[v]=1;
	}
}
void work(ll p)
{
	if(p==k)
	{
		ll res=0;
		ll cnt=0;
//		for(int i=1;i<=k;i++)
//		{
//			cout<<a[i]<<" ";
//		}
//		cout<<"(\n";
		for(int i=1;i<=n;i++)
		{
			v1[i]=v2[i]=0;
		}
		for(int i=1;i<=k;i++)
		{
			v2[a[i]]=1;
		}
		int f=0;
		for(int i=1;i<=k;i++)
		{
			if(!v1[a[i]])
			{
				v1[a[i]]=1;
				cnt++;
				if(cnt>2)
				{
					f=1;
					break;
				}
				dfs(a[i],0);
			}
		}
//		cout<<")\n";
		if(f)
		{
//			cout<<"NO\n";
			return ;
		}
		for(int i=1;i<=n;i++)
		{
			ll h=1e18;
			for(int j=1;j<=k;j++)
			{
				h=min(h,g[i][a[j]]);
			}
			res=max(res,h);
		}
//		cout<<":"<<res<<"\n";
		ans=min(ans,res);
		return ;
	}
	for(int i=a[p]+1;i<=n;i++)
	{
		if(!v[i])
		{
			v[i]=1;
			a[p+1]=i;
			work(p+1);
			v[i]=0;
		}
	}
}
void dfs2(ll u,ll fa)
{
	dep[u]=dep[fa]+1;
	for(auto vv : e[u])
	{
		if(vv==fa)
		{
			continue;
		}
		dfs2(vv,u);
	}
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>k;
		for(int i=1;i<=n;i++)
		{
			e[i].clear();
		}
		if(n<=10)
		{
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=n;j++)
				{
					g[i][j]=1e18;
					if(i==j)
					{
						g[i][j]=0;
					}
				}
				e[i].clear();
			}
		}
		int f=0;
		for(int i=1;i<n;i++)
		{
			ll u,v;
			cin>>u>>v;
			e[u].push_back(v);
			e[v].push_back(u);
			if(!((i<=n/2&&u==i&&v==i+1)||(i>n/2&&u==i-n/2&&v==i+1)))
			{
				f=1;
			}
			if(n<=10)
			{
				g[u][v]=g[v][u]=1;
			}
		}
		if(n<=14)
		{
			for(int p=1;p<=n;p++)
			{
				for(int i=1;i<=n;i++)
				{
					for(int j=1;j<=n;j++)
					{
						g[i][j]=min(g[i][j],g[i][p]+g[p][j]);
					}
				}
			}
//			for(int i=1;i<=n;i++)
//			{
//				for(int j=1;j<=n;j++)
//				{
//					cout<<g[i][j]<<" ";
//				}
//				cout<<"\n";
//			}
//			cout<<"\n\n";
			ans=1e18;
			work(0);
			cout<<ans<<"\n";
			continue;
		}
		if(n%2==1&&!f)
		{
			cout<<(n-k+3)/4<<"\n";
			continue;
		}
		if(n<=k)
		{
			cout<<"0\n";
			continue;
		}
		ll s=0;
//		cout<<"*";
		dfs2(1,0);
		ll mx=0;
		for(int i=1;i<=n;i++)
		{
			if(dep[i]>mx)
			{
				mx=dep[i];
				s=i;
			}
			dep[i]=0;
		}
//		cout<<s<<" ";
		dfs2(s,0);
		mx=0;
		for(int i=1;i<=n;i++)
		{
			if(dep[i]>mx)
			{
				mx=dep[i];
			}
		}
//		cout<<mx<<" ";
		cout<<(mx-k+3)/4<<"\n";
	}
	return 0;
}
