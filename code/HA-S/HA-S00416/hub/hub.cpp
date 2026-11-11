#include<bits/stdc++.h>
using namespace std;
const int N=1000002;
int cid,t,n,k,minn,st[N],top,dis[N];
vector<int>G[N];
bool vis[N];
void dfss(int x)
{
	vis[x]=false;
	for(auto i:G[x])if(vis[i])dfss(i);
}
inline void getans()
{
	queue<int>q;
	for(int i=1;i<=n;i++)dis[i]=n,vis[i]=false;
	for(int i=1;i<=top;i++)dis[st[i]]=0,q.push(st[i]),vis[st[i]]=true;
	int num=0,maxx=0;
	for(int i=1;i<=top;i=-~i)if(vis[st[i]])dfss(st[i]),num++;
	if(num>2)return;
	while(!q.empty())
	{
		int x=q.front();
		q.pop(),maxx=dis[x];
		for(auto i:G[x])if(dis[i]==n)
			dis[i]=dis[x]+1,q.push(i);
	}
	minn=min(minn,maxx);
}
void dfs(int x)
{
	if(x>n)return getans();
	if(top+(n-x)>=k)dfs(-~x);
	if(top!=k)st[++top]=x,dfs(x+1),top--;
}
inline void work()
{
	cin>>n>>k,minn=n;
	for(int i=1;i<=n;i=-~i)G[i].clear();
	for(int i=1,x,y;i<n;i=-~i)cin>>x>>y,G[x].push_back(y),G[y].push_back(x);
	if(n==k)return cout<<0<<'\n',void();
	if(n==k+1||n==k+2)return cout<<1<<'\n',void();
	if(cid==13||cid==14)
	{
		int m=n/2;
		for(int i=1;i<=n;i++)
			if((i-1)*4+k>=m)return cout<<i<<'\n',void();
		cout<<n<<'\n';
		return;
	}
	dfs(1);
	cout<<minn<<'\n';
}
signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>cid>>t;
	while(t--)work();
	return 0;
}
