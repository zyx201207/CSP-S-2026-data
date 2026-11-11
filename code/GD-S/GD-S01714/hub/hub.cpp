#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=15;
int c,T,n,k,x,y,ret,fa[N],dis[N][N];
bool vis[N];
int find(int x){
	if(x==fa[x])return x;
	return fa[x]=find(fa[x]);
}
void floyd(){
	for(int k=1;k<=n;k++)for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
}
void dfs(int x){
	if(x==n+1)
	{
		int num=0;
		for(int i=1;i<=n;i++)num+=vis[i],fa[i]=i;
		if(num!=k)return;
		for(int i=1;i<=n;i++)
		{
			if(vis[i]==0)continue;
			for(int j=i+1;j<=n;j++)
			{
				if(vis[j]==0||dis[i][j]!=1)continue;
				if(find(i)!=find(j))fa[find(i)]=find(j);
			}
		}
		int cnt=0;
		for(int i=1;i<=n;i++)if(vis[i]==1&&i==fa[i])cnt++;
		if(cnt>2)return;
		int sum=0;
		for(int i=1;i<=n;i++)
		{
			if(vis[i]==1)continue;
			int mi=1e18;
			for(int j=1;j<=n;j++)if(vis[j]==1)mi=min(mi,dis[i][j]);
			sum=max(sum,mi);
		}
		ret=min(ret,sum);
		return;
	}
	vis[x]=1;
	dfs(x+1);
	vis[x]=0;
	dfs(x+1);
}
void workx(){
	ret=1e18;
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=n;i++)dis[i][i]=0;
	for(int i=1;i<n;i++)cin>>x>>y,dis[x][y]=dis[y][x]=1;
	floyd();
	dfs(1);
	cout<<ret<<endl;
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>T;
	while(T--)
	{
		cin>>n>>k;
		if(n<=10)
		{
			workx();
			continue;
		}
	}
	return 0;
}

