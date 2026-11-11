#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e6+5;
ll c,T,n,k,f[N][22],idx;
ll zhi[N],dep[N];
bool vis[N];
bool flag=false;
vector<ll> e[N];
bool check_subA(ll x)
{
	ll dian1=(n/2+1)-x;
	ll dian2=x;
	if(dian1<=dian2) return true;
	ll cnt=2;
	for(int i=1;i<=n/2;i++)
	{
		if(i<=dian2||i>=dian1) continue;
		ll dis=min(i-dian2,dian1-i);
		if(dis<=x) continue;
		dian2++;
		cnt++;
	}
	if(cnt>k) return false;
	for(int i=n/2+2;i<=n;i++)
	{
		ll fat=i-n/2-1;
		if(fat<=dian2||fat>=dian1) continue;
		ll dis=min(fat-dian2+1,dian1-fat+1);
		if(dis<=x) continue;
		dian2++;
		cnt++;
	}
	if(cnt>k) return false;
	return true;
}
ll find_subA(ll l,ll r)
{
	while(l+1<r)
	{
		ll mid=(l+r)>>1;
		if(check_subA(mid)) r=mid;
		else l=mid;
	}
	return r;
}
ll subA()
{
	if(k==n) return 0;
	return find_subA(0,n);
}
void dfs(ll u,ll fa)
{
	dep[u]=dep[fa]+1;
	f[u][0]=fa;
	for(int i=0;i<e[u].size();i++)
	{
		ll v=e[u][i];
		if(v==fa) continue;
		dfs(v,u);
	}
}
void init()
{
	for(int j=1;(1<<j)<=n;j++)
	{
		for(int i=1;i<=n;i++)
		{
			f[i][j]=f[f[i][j-1]][j-1];
		}
	}
}
ll LCA(ll u,ll v)
{
	if(dep[u]<dep[v]) swap(u,v);
	for(int i=20;i>=0;i--)
	{
		if(dep[f[u][i]]>=dep[v]) u=f[u][i];
	}
	if(u==v) return u;
	for(int i=20;i>=0;i--)
	{
		if(f[u][i]!=f[v][i])
		{
			u=f[u][i];
			v=f[v][i];
		}
	}
	return f[u][0];
}
ll popcnt(ll x)
{
	ll res=0;
	while(x)
	{
		if(x&1) res++;
		x>>=1;
	}
	return res;
}
void dfs2(ll u,ll fa)
{
	if(vis[u])
	{
		if(!vis[fa]) zhi[u]=++idx;
		else zhi[u]=zhi[fa];
	}
	for(int i=0;i<e[u].size();i++)
	{
		ll v=e[u][i];
		if(v==fa) continue;
		dfs2(v,u);
	}
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%lld%lld",&c,&T);
	while(T--)
	{
		scanf("%lld%lld",&n,&k);
		for(int i=1;i<n;i++)
		{
			ll u,v;
			scanf("%lld%lld",&u,&v);
			e[u].push_back(v);
			e[v].push_back(u); 
		}
		if(c==13||c==14)//10pts
		{
			printf("%lld\n",subA());
			for(int i=1;i<=n;i++) e[i].clear();
			continue;
		}
		dfs(1,0);
		init();
		if(n<=10)
		{
			ll ans=1e18;
			for(int S=0;S<(1<<n);S++)
			{
				if(popcnt(S)!=k) continue;
				for(int i=1;i<=n;i++)
				{
					zhi[i]=0;
					if(S&(1<<(i-1)))
					{
						vis[i]=true;
					}
					else vis[i]=false;
				}
				idx=0;
				dfs2(1,0);
				if(idx>2) continue;
				ll res=0;
				for(int i=1;i<=n;i++)
				{
					if(vis[i]) continue;
					ll sum=1e18;
					for(int j=1;j<=n;j++)
					{
						if(!vis[j]) continue;
						ll dis=dep[i]+dep[j]-2*dep[LCA(i,j)];
						sum=min(sum,dis);
					}
					res=max(res,sum);
				}
				ans=min(ans,res);
			}
			printf("%lld\n",ans);
		}
		for(int i=1;i<=n;i++) e[i].clear();
		for(int i=1;i<=n;i++)
		{
			dep[i]=0;
			for(int j=1;(1<<j)<=n;j++)
			{
				f[i][j]=0;
			}
		}
	}
	return 0;
}
/*
0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10
*/
