#include<bits/stdc++.h>
#define endl '\n' 
#define int long long
using namespace std;
const int N = 5e2+5;
const int M = 5e5+5;
int c,n,m,d,q;
int w[M],k[N];
struct node{
	int v,w;
	
	const bool operator>(const node &b)const{
		return w > b.w;
	}
};
vector<node> edge[M + N];
const int inf = 1e18;
int dis[N + M];
void dij(int start,int end)
{
	bool vis[N + M];
	for(int i = 1;i < N+M;i++)vis[i] = 0;
	for(int i = 1;i < N+M;i++)dis[i] = inf;
	dis[start] = 0;
	priority_queue<node,vector<node>,greater<node> > q;
	q.push((node){start,dis[start]});
	while(!q.empty())
	{
		int u = q.top().v;
		q.pop();
		if(vis[u])continue;
		vis[u] = 1;
		for(node t : edge[u])
		{
			if(dis[t.v] > dis[u] + t.w)
			{
				dis[t.v] = dis[u] + t.w;
				q.push((node){t.v,dis[t.v]});
			}
			if(t.v == end)return;
		}
	}
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;i++)
	{
		cin >> w[i];
	}
	for(int i = 1;i <= n;i++)
	{
		cin >> k[i];
		for(int j = 1;j <= k[i];j++)
		{
			int a,t;
			cin >> a >> t;
			int line = M + i;
			edge[line].push_back((node){a,t});
			edge[a].push_back((node){line,t});
		}
	}
	while(q--)
	{
		int x,y;
		cin >> x >> y;
		int ans = w[x] + w[y];
		
		dij(x,y);
		cout << ans + dis[y] << endl;
	}
	return 0;
}
