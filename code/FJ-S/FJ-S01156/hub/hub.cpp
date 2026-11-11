#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int c,t,n,k,dis[N],pos[N],ans;
bool vis[N];
struct node{
	int t,val;
};
vector<int>l[N]; 
void dfs(int stp,int cs)
{
	if(cs>k)return;
	if(cs==k)
	{
		memset(vis,0,sizeof(vis));
		memset(dis,0,sizeof(dis));
		queue<node>q;
		for(int i=1;i<=k;i++)
		{
			q.push({pos[i],0});
			dis[i]=0;
		}
		while(!q.empty())
		{
			node nw=q.front();
			q.pop();
			if(vis[nw.t])continue;
			vis[nw.t]=1;
			if(dis[nw.t]==0)dis[nw.t]=nw.val+1;
			for(int i:l[nw.t])
			{
				q.push({i,dis[nw.t]});
			} 
		}
		int mx=0;
		for(int i=1;i<=n;i++)mx=max(mx,dis[i]);
		ans=min(ans,mx);
	}
	if(stp>n)return;
	pos[cs+1]=stp;
	dfs(stp+1,cs+1);
	dfs(stp+1,cs);
}
signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>t;
	while(t--)
	{
		ans=INT_MAX;
		cin>>n>>k;
		for(int i=1;i<=n;i++)l[i].clear();
		int u,v;
		for(int i=1;i<=n-1;i++)
		{
			cin>>u>>v;
			l[u].push_back(v);
			l[v].push_back(u);
		}
		dfs(1,0);
		cout<<ans<<"\n";
	}
	return 0;
}
