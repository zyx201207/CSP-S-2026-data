#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10,M=25,INF=1e9,K=4010;
int c,T,n,k,dist[N],f[N][M],vis[N],fa[N],res=INF,a[K][K];
vector<int> g[N];
int find(int x)
{
	if(fa[x]!=x)fa[x]=find(fa[x]);
	return fa[x];
}
void dfs(int u,int fa)
{
	dist[u]=dist[fa]+1;
	f[u][0]=fa;
	for(int i=1;i<=20;i++)f[u][i]=f[f[u][i-1]][i-1];
	for(auto v:g[u])
	{
		if(v==fa)continue;
		dfs(v,u);
	}
}
int lca(int a,int b)
{
	if(dist[a]<dist[b])swap(a,b);
	for(int i=20;i>=0;i--)
		if(dist[f[a][i]]>=dist[b])
			a=f[a][i];
	if(a==b)return a;
	for(int i=20;i>=0;i--)
		if(f[a][i]!=f[b][i])
		{
			a=f[a][i];
			b=f[b][i];
		}
	return f[a][0];
}
void dfs_k(int u)
{
	if(u==k+1)
	{
		for(int i=1;i<=n;i++)fa[i]=i;
		vector<int> vec;
		for(int i=1;i<=n;i++)
			if(vis[i])vec.push_back(i);
		for(int i=0;i<vec.size();i++)
			for(int j=0;j<vec.size();j++)
			{
				int x=vec[i],y=vec[j];
				if(!a[x][y])continue;
//				cout<<"Sgdsopjop "<<x<<' '<<y<<endl;
				int fx=find(x),fy=find(y);
				if(fx!=fy)fa[fx]=fy;
			}
		int cnt=0;
		for(int i=1;i<=n;i++)
			if(vis[i]&&find(i)!=find(1))cnt++;
//		cout<<"OPJOijoi "<<cnt<<endl;
		if(cnt<=1)
		{
//			cout<<"A right solution\n";
//			for(int i=0;i<vec.size();i++)cout<<vec[i]<<' ';
//			cout<<endl;
//			cout<<"End\n";
			int maxn=0;
			for(int i=1;i<=n;i++)
			{
				int minv=INF;
				for(int j=0;j<vec.size();j++)
				{
					int x=i,y=vec[j];
					int p=lca(x,y);
//					cout<<"popoj  "<<x<<' '<<y<<' '<<p<<endl;
					minv=min(minv,dist[x]+dist[y]-2*dist[p]); 
				}
				maxn=max(maxn,minv);
			}
			res=min(res,maxn);
		}
		return;
	}
	for(int i=1;i<=n;i++)
		if(!vis[i])
		{
			vis[i]=1;
			dfs_k(u+1);
			vis[i]=0;
		}
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>T;
	while(T--)
	{
		cin>>n>>k;
		for(int i=1;i<=n;i++)
		{
			g[i].clear();
			for(int j=1;j<=n;j++)a[i][j]=0;
		}
		for(int i=1;i<n;i++)
		{
			int u,v;
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
			a[u][v]=a[v][u]=1;
		}
		dfs(1,0);
		res=INF;
		dfs_k(1);
		cout<<res<<endl;
	}
	return 0;
}
