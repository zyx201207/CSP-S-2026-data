#include<bits/stdc++.h>
#define N 1000010
using namespace std;

int fa[N],ban[N],col[N],dis[N],vis[N],DIS[N],dp[N],tong[N];
vector <int> v[N];

void dfs1(int x,int f)
{
	fa[x]=f;
	for(int y:v[x]) if(y!=f) dfs1(y,x);
}

void dfs2(int x,int f)
{
	col[x]=1;
	for(int y:v[x]) if(y!=f&&!ban[y]) dfs2(y,x);
}

void dfs3(int x,int f)
{
	dis[x]=dis[f]+1;
	for(int y:v[x]) if(y!=f) dfs3(y,x);
}

void dfs4(int x,int f)
{
	dp[x]=1;
	for(int y:v[x]) if(y!=f&&!ban[y]) 
	{
		dfs4(y,x);
		dp[x]=max(dp[x],dp[y]+1);
	}
}

int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		int ans=1e9;
		for(int i=1;i<n;i++)
		{
			int x,y;
			cin>>x>>y;
			v[x].push_back(y);
			v[y].push_back(x);
		}
		dfs1(1,0);
		for(int x=1;x<=n;x++) for(int y=1;y<=n;y++)
		{
			int xx=x;
			while(xx) vis[xx]++,xx=fa[xx];
			int yy=y;
			while(yy) vis[yy]++,yy=fa[yy];
			xx=x;
			while(vis[xx]!=2) ban[xx]=1,xx=fa[xx];
			ban[xx]=1;
			yy=y;
			while(vis[yy]!=2) ban[yy]=1,yy=fa[yy];
			ban[yy]=1;
			
			dfs2(x,0);
			dfs2(y,0);
			
			for(int i=1;i<=n;i++) DIS[i]=1e9;
			dfs3(x,0);
			for(int i=1;i<=n;i++) DIS[i]=min(DIS[i],dis[i]);
			dfs3(y,0);
			for(int i=1;i<=n;i++) DIS[i]=min(DIS[i],dis[i]);
			
			dfs4(x,0);
			dfs4(y,0);
			
			int mx=0;
			for(int i=1;i<=n;i++) if(!col[i]) mx=max(mx,DIS[i]-1);
			for(int i=1;i<=n;i++) if(col[i]&&i!=x&&i!=y) tong[dp[i]]++;
			int rk=0;
			for(int i=n;i>=1;i--)
			{
				rk+=tong[i];
				if(rk>k-2) 
				{
					mx=max(mx,i);
					break;
				}
			}
			ans=min(ans,mx);
			
			for(int i=1;i<=n;i++) vis[i]=ban[i]=col[i]=tong[i]=0,DIS[i]=1e9;
		} 
		
		cout<<ans<<endl;
		for(int i=1;i<=n;i++) v[i].clear();
	}
}
