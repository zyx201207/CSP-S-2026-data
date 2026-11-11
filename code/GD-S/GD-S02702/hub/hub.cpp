#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#define ll long long
using namespace std;
int c,t,n,k;
int dis[1000005];
bool vis[1000005],e[10005][10005];
vector<int> edges[1000005];
void dfs(int u,int f)
{
	for(int i=0;i<edges[u].size();i++)
	{
		int v=edges[u][i];
		if(v==f)continue;
		dis[v]=dis[u]+1;
		dfs(v,u);
	}
}
int main()
{
//	freopen("hub2.in","r",stdin);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>k;
		for(int i=1;i<=n;i++)edges[i].clear();
		memset(e,0,sizeof(e));
		for(int i=1;i<n;i++)
		{
			int u,v;
			cin>>u>>v;
			e[u][v]=e[v][u]=1;
			edges[u].push_back(v);
			edges[v].push_back(u);
		}
		int ans=1e9;
		for(int msk=0;msk<(1<<n);msk++)
		{
			fill(vis+1,vis+1+n,0);
			if(__builtin_popcount(msk)!=k)continue;
			int tmp=msk,id=1;
			while(tmp)
			{
				if(tmp&1)vis[id]=1;
				id++,tmp>>=1;
			}
//			for(int i=1;i<=n;i++)cout<<vis[i]<<" ";cout<<"\n";
			int cnt=k;
			for(int i=1;i<=n;i++)
			{
				for(int j=i+1;j<=n;j++)
				{
					if(e[i][j]&&vis[i]&&vis[j])cnt--;
				}
			}
//			cout<<cnt<<"\n";
			if(cnt>2)continue;
			int mn=1e9,mx=-1;
			for(int i=1;i<=n;i++)
			{
				if(vis[i])continue;
				fill(dis+1,dis+1+n,0);
				mn=1e9;
				dfs(i,0);
//				for(int j=1;j<=n;j++)cout<<dis[j]<<" ";cout<<"\n";
				for(int j=1;j<=n;j++)
				{
					if(vis[j])
					{
						mn=min(mn,dis[j]);
//						cout<<i<<" "<<j<<" "<<dis[j]<<"\n";
					}
				}
//				cout<<"d"<<i<<" "<<mn<<"\n";
				mx=max(mx,mn);
			}
//			cout<<"r"<<" "<<mx<<"\n";
			ans=min(ans,mx);
		}
//		cout<<"min"<<" "<<ans<<"\n";
		cout<<ans<<"\n";
	}
	return 0;
}
//maybe 15pts
//best:100+32+8+15=155 QwQ
//X X XXX
//x x xxx
//XX X XXX
//xx x xxx
