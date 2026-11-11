#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <map>
using namespace std;
struct node{int v;long long w;};
bool operator <(node a,node b)
{
	return a.w>b.w;
}
int c,n,m,d,w[500005],tmp,qq,tt;
vector<node>g[510005];
void spfa(int st,int end)
{
	vector<bool>vis(m+n+5,0);
	priority_queue<node>q;
	q.push({st,0});
	while(q.size())
	{
		int u=q.top().v;
		long long len=q.top().w;
//		cout << u << " ";
		q.pop();
		if(u==end)
		{
			cout << len+w[st]+w[end] << endl;
			return;
		}
//		cout << g[u].size() << "->";
		for(node i:g[u])
			if(!vis[i.v])
			{
				q.push({i.v,len+i.w});
				vis[i.v]=1;
			}
	}
}
void bfs(int st,int end)
{
	vector<bool>vis(m+n+5,0);
	queue<node>q;
	q.push({st,0});
	while(q.size())
	{
		int u=q.front().v;
		long long len=q.front().w;
		q.pop();
		if(vis[u])continue;
		vis[u]=1;
		if(u==end)
		{
			cout << len*tt+w[st]+w[end] << endl;
			return;
		}
		for(node i:g[u])
			if(!vis[i.v])
				q.push({i.v,len+1});
	}
}
int main()
{
	ios::sync_with_stdio(false);cin.tie(nullptr);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> qq;
	for(int i = 1;i<=m;i++)cin >> w[i];
	for(int i = 1;i<=n;i++)
	{
		cin >> tmp;
		for(int j = 1;j<=tmp;j++)
		{
			int a,t;
			cin >> a >> t;
			g[i+m].push_back({a,t});
			g[a].push_back({i+m,t});
			tt=t;
		}
	}
	while(qq--)
	{
		int l,r;
		cin >> l >> r;
		if(12<=c && c<=19)bfs(l,r);
		else spfa(l,r);
	}
	return 0;
}
