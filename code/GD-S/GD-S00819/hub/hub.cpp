#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N=1e6+5;
int CC,T;
int n,K;
vector<int> a[N];
int fa[N];
int cnt[N];
int dis[300][300];
int D[300];
int find(int x)
{
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
void merge(int x,int y)
{
	int fx=find(x),fy=find(y);
	if(fx!=fy) fa[fx]=fy;
}
int pcnt[10000];
signed main()
{
	freopen("hub.in","r",stdin); 
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>CC>>T;
	for(int i=1;i<(1<<10);i++) pcnt[i]=pcnt[i>>1]+(i&1); 
	while(T--)
	{
		cin>>n>>K;
		for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) dis[i][j]=1e18;
		for(int i=1,u,v;i<n;i++)
		{
			cin>>u>>v;
			a[u].push_back(v);
			a[v].push_back(u);
			dis[u][v]=1;
			dis[v][u]=1;
		}
		for(int k=1;k<=n;k++)
		{
			D[k]=1e18;
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=n;j++)
				{
					if(i==j||j==k||i==k) continue;
					dis[i][j]=min(dis[i][j],dis[i][k]+ dis[k][j]);
				}
			}
		}
		int ans=1e18;
		for(int i=1;i<(1<<n);i++)
		{
			if(pcnt[i]!=K) continue;
			for(int j=1;j<=n;j++) fa[i]=i,cnt[i]=0;
			for(int j=1;j<=n;j++)
			{
				if(i&(1<<(j-1)))
				{
					int u=j;
					for(int v:a[u])
					{
						if(i&(1<<(v-1)))
						{
							merge(u,v);
						}
					}
				}
			}
			for(int j=1;j<=n;j++) cnt[find(j)]++;
			int all=0;
			for(int j=1;j<=n;j++) if(cnt[j]>0) all++;
			if(all>2) continue;
			for(int j=1;j<=n;j++) D[j]=1e18;
			for(int j=1;j<=n;j++)
			{
				if(i&(1<<(j-1)))
				{
					D[j]=0;
					int u=j;
					for(int v=1;v<=n;v++)
					{
						D[v]=min(D[v],dis[u][v]);
					}
				}
			}
			int tmp=0;
			for(int j=1;j<=n;j++) tmp=max(tmp,D[j]);
			ans=min(tmp,ans);
		}
		cout<<ans<<endl;
	}
	return 0;
}
