#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+5;
int c,t,n,k,x,y,ans,rt;
vector<int> e[N];
bool vis[N],mark[N];
void col(int u,int fa)
{
	mark[u]=1;
	for(int i:e[u])
	{
		if(vis[i]&&i!=fa)
		{
			mark[i]=1;
			col(i,u);
		}
	}
}
bool ck()
{
	rt=0;
	for(int i=1;i<=n;i++)mark[i]=0;
	for(int i=1;i<=n;i++)
	{
		if(vis[i])
		{
			rt=i;
			break;
		}
	}
	if(!rt)return 1;
	col(rt,rt);
	bool kil=0;
	for(int i=1;i<=n;i++)
	{
		if(vis[i]&&(!mark[i]))
		{
			rt=i,kil=1;
			break;
		}
	}
	if(!kil)return 1;
	col(rt,rt);
	for(int i=1;i<=n;i++)
	{
		if(vis[i]&&(!mark[i]))return 0;
	}
	return 1;
}
int work(int u,int fa,int num)
{
	if(vis[u])return num;
	int sm=1e9;
	for(int i:e[u])
	{
		if(i!=fa)
		{
			sm=min(sm,work(i,u,num+1));
		}
	}
	return sm;
}
int get()
{
	int sm=0;
	for(int i=1;i<=n;i++)if(!vis[i])sm=max(sm,work(i,0,0));
	return sm;
}
void dfs(int u,int num)
{
	if(num>k)return;
	if(u>n)
	{
		if(num!=k)return;
		if(ck())
		{
			ans=min(ans,get());
		}
		return;
	}
	vis[u]=1;
	dfs(u+1,num+1);
	vis[u]=0;
	dfs(u+1,num);
}
void sol()
{
	cin>>n>>k;
	ans=1e17;
	for(int i=1;i<=n;i++)e[i].clear(),vis[i]=0;
	for(int i=1;i<n;i++)
	{
		cin>>x>>y;
		e[x].push_back(y),e[y].push_back(x);
	}
	dfs(1,0);
	cout<<ans<<'\n';
}
signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>c>>t;
	if(c<=1)while(t--)sol();
	return 0;
}
