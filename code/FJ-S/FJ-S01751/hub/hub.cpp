# include <bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int c,t,n,k,dist[N];
vector<int>edge[N];
vector<int>Can;
int vis[N],choose[N];
inline void init()
{
	for(int i=1;i<=n;i++)
		vis[i]=0;
}
inline void dfs(int u)
{
	if(!choose[u-1])return;
	vis[u]=1;
	for(int v:edge[u])
		if(!vis[v])dfs(v);
}
inline void tfs(int u,int len)
{
	if(choose[u-1])dist[u]=0;
	dist[u]=min(dist[u],len);
	vis[u]=1;
	
	for(int v:edge[u])
		if(!vis[v])tfs(v,len+1);
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>k;
		Can.clear();
		for(int i=1;i<=n;i++)
			edge[i].clear();
		for(int i=1,u,v;i<n;i++)
			cin>>u>>v,edge[u].emplace_back(v),edge[v].emplace_back(u);
		
		for(int S=0;S<(1<<n);S++)
		{
			int one_cnt=0;
			for(int g=0;g<n;g++)
				one_cnt+=(S>>g)&1;
			if(one_cnt==k)Can.push_back(S);
		}
		int ans=1e9;
		for(int S:Can)
		{
			init();
			for(int g=0;g<n;g++)
				choose[g]=(S>>g)&1;
			int Lian=0;
			for(int g=0;g<n;g++)
				if(choose[g] && !vis[g+1])dfs(g+1),++Lian;
			if(Lian>2)continue;
			
			for(int i=1;i<=n;i++)
				dist[i]=1e9;
			
			for(int g=0;g<n;g++)
				if(choose[g])
					init(),tfs(g+1,0);
				
			int Max=-1;
			for(int i=1;i<=n;i++)
				Max=max(Max,dist[i]);
			
			if(Max<ans)
				ans=Max;
		}
		cout<<ans<<"\n";
	}
}