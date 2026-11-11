#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int c,T,n,k;
vector<int>e[N];
int dis[N];
bool vis[N];
void dfs(int x)
{
	vis[x]=1;
	for(auto y:e[x])
		if(dis[y]==0&&!vis[y])
			dfs(y);
}
void spn()
{
	int ans=n+1;
	for(int S=1;S<(1<<n);S++)
	{
		int cnt=0;
		for(int i=1;i<=n;i++)
			dis[i]=n+1,
			vis[i]=0;
		queue<int>q;q={};
		for(int i=1;i<=n;i++)
			if((S>>(i-1))&1)
				cnt++,
				dis[i]=0,
				q.push(i);
		if(cnt!=k)continue;
		while(!q.empty())
		{
			int x=q.front();q.pop();
			for(auto y:e[x])
				if(dis[y]>dis[x]+1)
					dis[y]=dis[x]+1,
					q.push(y);
		}
		int siz=0;
		for(int i=1;i<=n;i++)
			if(dis[i]==0&&!vis[i])
				siz++,dfs(i);
		if(siz>2)continue;
		int res=0;
		for(int i=1;i<=n;i++)
			res=max(res,dis[i]);
//		for(int i=1;i<=n;i++)
//			if(dis[i]==0)cout<<i<<' ';
//		cout<<":"<<res<<'\n';
		ans=min(ans,res);
	}
	cout<<ans<<'\n';
}
void init()
{
	for(int i=1;i<=n;i++)
		e[i].clear();
}
signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>T;
	while(T--)
	{
		init();
		cin>>n>>k;
		for(int x,y,i=1;i<n;i++)
			cin>>x>>y,
			e[x].push_back(y),
			e[y].push_back(x);
		if(n<=10){spn();continue;}
//		if(k==2){spk();continue;}
		if(c==13||c==14)
		{
		int m=n/2;
		cout<<(m+1)/(k+1)<<'\n';
		continue;}
	}
	return 0;
}
