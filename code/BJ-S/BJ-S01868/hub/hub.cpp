#include<algorithm>
#include<iostream>
#include<fstream>
#include<vector>
#include<queue>
using namespace std;
queue<int> q;
#define cin lyc
#define cout lmy
vector<int> g[1000005];
ifstream cin("hub.in");
ofstream cout("hub.out");
int ban,fa[1000005],dis[1000005],atdis[1000005];
void getfa(int u,int f)
{
	fa[u]=f;
	for(int v:g[u])	if(v!=f)	getfa(v,u);
}
void dfs(int u,int f)
{
	int s=0;
	for(int v:g[u])
		s+=(v!=f && v!=ban);
	if(s<=!f)	q.push(u),dis[u]=0;
	for(int v:g[u])
		if(v!=f && v!=ban)
			dfs(v,u);
}
void mian()
{
	int n,k;
	cin>>n>>k;
	int m=n/2;
	int ans=1e9;
	bool good=(n&1);
	for(int i=1;i<=n;i++)	g[i].clear();
	for(int i=1,u,v;i<n;i++)
		cin>>u>>v,g[u].push_back(v),g[v].push_back(u),good&=((1<=i && i<=m)?(u==i && v==i+1):(u==i-m && v==i+1));
	if(good)
	{
		if(k==n)	cout<<"0\n";
		int need=m,ans=1;
		while(need>k)	need-=4,ans++;
		cout<<ans<<endl;
		return;
	}
	getfa(1,0);
	for(int i=2;i<=n;i++)
	{
		for(int i=1;i<=n;i++)	dis[i]=-1;
		ban=i;
		dfs(1,0);
		dfs(i,fa[i]);
		while(q.size())
		{
			int u=q.front();
			q.pop();
			for(int v:g[u])
				if(!((u==i && v==fa[i]) || (u==fa[i] && v==i)))
					if(dis[v]==-1)
						dis[v]=dis[u]+1,q.push(v);
		}
		int need=n;
		for(int i=1;i<=n;i++)	atdis[dis[i]]++;
		for(int i=0;i<n;i++)
		{
			if(need<=k)
			{
				ans=min(ans,i);
				break;
			}
			need-=atdis[i];
		}
		for(int i=0;i<=n;i++)	atdis[i]=0;
	}
	cout<<ans<<endl;
}
int main()
{
	int c,t;
	cin>>c>>t;
	while(t--)	mian();
}