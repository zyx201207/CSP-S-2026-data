#include<bits/stdc++.h>
using namespace std;
const int N=20;
int c,t,n,k,f[N][N],a[N],ans=2e9,res;
vector<int> e[N];
void dfs(int u,int fa)
{
	if(a[u] and !a[fa])res++;
	for(int v:e[u])
	{
		if(v==fa)continue;
		dfs(v,u);
	}
}
bool ch()
{
	res=0;
	dfs(1,0);
	if(res>2)return 1;
	else return 0;
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		ans=2e9;
		for(int i=0;i<=15;i++)e[i].clear();
		memset(f,0x3f,sizeof f);
		cin>>n>>k;
		for(int i=1;i<n;i++)
		{
			int u,v;
			cin>>u>>v;
			e[u].push_back(v);
			e[v].push_back(u);
			f[u][v]=f[v][u]=1;
		}
		for(int i=1;i<=n;i++)f[i][i]=0;
		for(int h=1;h<=n;h++)
		{
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=n;j++)
				{
					f[i][j]=min(f[i][j],f[i][h]+f[h][j]);
				}
			}
		}
		for(int i=0;i<(1<<n);i++)
		{
			int cnt=0;
			memset(a,0,sizeof a);
			for(int j=1;j<=n;j++)
			{
				if((i>>(j-1))&1)cnt++,a[j]=1;
			}
			if(cnt!=k)continue;
			if(ch())continue;
			int l=0;
			for(int j=1;j<=n;j++)
			{
				int r=2e9;
				if(a[j])continue;
				else 
				{
					for(int h=1;h<=n;h++)
					{
						if(!a[h])continue;
						r=min(r,f[j][h]);
						
					}
				}
				l=max(l,r);
			}
			ans=min(ans,l);
		}
		cout<<ans<<"\n";
	}
	return 0;
}
