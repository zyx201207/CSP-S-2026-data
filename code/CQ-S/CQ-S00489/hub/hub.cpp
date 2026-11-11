#include <bits/stdc++.h>
using namespace std;

vector<int> a[300005];
int n,k,maxn,cnt,minn=1e9,plan[300005],d[300005];
bitset<300005> vis;
void dfs_t(int x)
{
	if(!plan[x] || vis[x]) return ;
	vis[x]=1;
	for(int i:a[x]) dfs_t(i);
}
void bfs(int x)
{
	queue<pair<int,int> > q;
	q.push({x,0});
	while(!q.empty())
	{
		if(plan[q.front().first])
		{
			maxn=max(maxn,q.front().second);
			break;
		}
		int x=q.front().first,y=q.front().second;
		q.pop();
		if(vis[x]) continue;
		vis[x]=1;
		for(int i:a[x]) q.push({i,y+1});
	}
}
void dfs(int x,int now)
{
	if(now>=k)
	{
		maxn=0,cnt=0,vis.reset();
		vector<int> vec;
		for(int i=1; i<=n; i++)
		{
			if(plan[i] && !vis[i]) dfs_t(i),vec.push_back(i); 
		}
		if(vec.size()<=2)
		{
			for(int i=1; i<=n; i++) vis.reset(),bfs(i);
			minn=min(minn,maxn);
		}
		return ;
	}
	if(x>n) return ;
	plan[x]=1;
	dfs(x+1,now+1);
	plan[x]=0;
	dfs(x+1,now);
}

int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie();
	cout.tie();
	int c,t;
	cin>>c>>t;
	if(c==0)
	{
		while(t--)
		{
			cin>>n>>k;
			for(int i=1; i<n; i++)
			{
				int x,y;
				cin>>x>>y;
				a[x].push_back(y),a[y].push_back(x);
			}
			if(k>=n/2) cout<<"1/n";
			else cout<<(n+1)/2-(n/2+k-1)/k*(k-1)-1<<'\n';
			for(int i=1; i<=n; i++) a[i].clear();
		}
		return 0;
	}
	while(t--)
	{
		cin>>n>>k;
		for(int i=1; i<n; i++)
		{
			int x,y;
			cin>>x>>y;
			a[x].push_back(y),a[y].push_back(x);
		}
		dfs(1,0);
		cout<<minn<<'\n';
		minn=1e9;
		for(int i=1; i<=n; i++) a[i].clear();
	}
	return 0;
}

