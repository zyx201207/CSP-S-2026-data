#include<iostream>
#include<cstring> 
using namespace std;
const int N=1e6+5;
int c,T,n,k,fa[N],ans,f[100][100];
bool vis[N];
struct edge
{
	int u,v;
}r[N];
int find_fa(int i)
{
	if(fa[i]==i)
		return i;
	fa[i]=find_fa(fa[i]);
	return fa[i];
}
void calc()
{
	int Max=-1;
	for(int i=1;i<=n;i++)
	{
		int res=0x3f3f3f3f;
		for(int j=1;j<=n;j++)
		{
			if(vis[j])
				res=min(res,f[i][j]);
		}
		Max=max(Max,res);
	}
	ans=min(ans,Max);
}
void dfs(int t,int cnt)
{
	if(t>n)
	{
		if(cnt==k)
		{
			for(int i=1;i<=n;i++)
				fa[i]=i;
			for(int i=1;i<n;i++)
			{
				if(vis[r[i].u]&&vis[r[i].v])
					fa[find_fa(r[i].u)]=find_fa(r[i].v);
			}
			int cnt_root=0;
			for(int i=1;i<=n;i++)
			{
				if(vis[i]&&fa[i]==i)
					cnt_root++;
			}
			if(cnt_root<=2)
				calc();
		}
		return;
	}
	vis[t]=true;
	dfs(t+1,cnt+1);
	vis[t]=false;
	dfs(t+1,cnt);
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>T;
	while(T--)
	{
		memset(f,0x3f,sizeof(f));
		cin>>n>>k;
		for(int i=1;i<n;i++)
		{
			cin>>r[i].u>>r[i].v;
			if(c<=3)
				f[r[i].u][r[i].v]=f[r[i].v][r[i].u]=1;
		}
		if(c<=3)
		{
			ans=0x3f3f3f3f;
			for(int i=1;i<=n;i++)
				f[i][i]=0;
			for(int k=1;k<=n;k++)
			{
				for(int i=1;i<=n;i++)
				{
					for(int j=1;j<=n;j++)
						f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
				}
			}
			dfs(1,0);
			cout<<ans<<"\n";
		}
		else if(c==13||c==14)
		{
			int len=(n+1)/2+1;
			if(k==1)
				cout<<(len+1)/2<<"\n";
			else
				cout<<max((len-k+3)/4,0)<<"\n";
		} 
	}
	return 0;
}
