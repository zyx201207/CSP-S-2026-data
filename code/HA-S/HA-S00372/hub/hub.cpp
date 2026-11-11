#include<bits/stdc++.h>
#define int long long
#define pr pair<int,int>
using namespace std;
const int N=505,INF=0x3f3f3f3f3f3f3f3f;
int op,T,n,k,mask,vis[N];
vector<int>g[N];
void dfs(int x)
{
	if(vis[x]) return ;
	vis[x]=1;
	for(auto y:g[x])
	{
		if(vis[y]||(((mask>>y)&1))==0) continue;
		dfs(y);
	}
}
bool check()
{
	for(int i=0;i<n;i++)
		vis[i]=0;
	int res=0;
	for(int i=0;i<n;i++)
		if((mask>>i)&1)
			if(!vis[i])
			{
				res++;
				dfs(i);
			}
	if(res<=2) return 1;
	else return 0;
}
int bfs(int st)
{
	for(int i=0;i<n;i++)
		vis[i]=0;
	queue<pr>q;
	q.push({st,0});
	while(q.size())
	{
		int x=q.front().first,dis=q.front().second;
		q.pop();
		if(vis[x]) continue;
		vis[x]=1;
		if((mask>>x)&1) return dis;
		for(auto y:g[x])
		{
			if(vis[y]) continue;
			q.push({y,dis+1});
		}
	}
}
signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>op>>T;
	while(T--)
	{
		for(int i=0;i<n;i++)
			g[i].clear();
		cin>>n>>k;
		for(int i=1;i<n;i++)
		{
			int x,y;cin>>x>>y;
			x--;y--;
			g[x].push_back(y);
			g[y].push_back(x);
		}
		int ans=INF;
		for(mask=1;mask<(1<<n);mask++)
		{
			if(__builtin_popcount(mask)!=k) continue;
//			cout<<"GGG "<<mask<<'\n';
			if(!check()) continue;
//			cout<<"FFF "<<mask<<'\n';
			int maxx=0;
			for(int i=0;i<n;i++)
				if(((mask>>i)&1)==0) maxx=max(maxx,bfs(i));
			ans=min(ans,maxx);
		}
		cout<<ans<<'\n';
	}
	return 0;
}


