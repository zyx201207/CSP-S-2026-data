#include<bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 10;
const int maxd = 25;
const int linen = 510;
#define int long long
struct node
{
	int v,w;
};
struct edge
{
	int u,dis;
	friend bool operator <(edge x,edge y)
	{
		return x.dis < y.dis;
	}
};
struct edge2
{
	int u,dis;
};
struct re
{
	int line,tim;
};
vector<re> box[maxn];
int hc[maxn];
int dis[linen+50][linen+50];
bool vis[linen+50];
vector<node> g[linen+50];
void dijkstra(int s)
{
	for(int i = 1;i <= linen+5;i++)
		dis[s][i] = 1e18;
	memset(vis,0,sizeof(vis));
	priority_queue<edge> q;
	dis[s][s] = 0; q.push({s,0});
	while(!q.empty())
	{
		int u = q.top().u; 
		q.pop();
		if(vis[u]) continue;
		vis[u] = 1;
		for(int i = 0;i < g[u].size();i++)
		{
			int v = g[u][i].v,w = g[u][i].w;
			if(dis[s][v] > dis[s][u] + w)
			{
				dis[s][v] = dis[s][u] + w;
				q.push({v,dis[s][v]});
			}
		}
	}
	return;
}
int c,n,m,d,q;
int w[maxn];
int get_min(int st,int ed)
{
	int sum = w[st] + w[ed];
	int mi = 1e18;
	for(int i = 0;i < box[st].size();i++)
	{
		for(int j = 0;j < box[ed].size();j++)
		{
			int u = box[st][i].line,v = box[ed][j].line;
			int w1 = box[st][i].tim,w2 = box[ed][j].tim;
			mi = min(mi,dis[u][v]+w1+w2);
		}
	}
	sum += mi;
	return sum;
}
int qre[maxn]; bool flag[maxn];
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;i++)
		cin >> w[i];
	int len = 0;
	for(int i = 1;i <= n;i++)
	{
		int k; cin >> k;
		for(int j = 1;j <= k;j++)
		{
			int nowx,nowy;
			cin >> nowx >> nowy;
			box[nowx].push_back({i,nowy}); 
			hc[nowx]++;
			if(hc[nowx] > 1 && !flag[nowx])
				flag[nowx] = 1,qre[++len] = nowx; 
		}
	}
	for(int r = 1;r <= len;r++)
	{
		int now = qre[r];
		if(hc[now] > 1)
		{
			for(int i = 0;i < box[now].size();i++)
				for(int j = i+1;j < box[now].size();j++)
				{
					int u = box[now][i].line;
					int v = box[now][j].line;
					int w = box[now][i].tim + box[now][j].tim;
					g[u].push_back({v,w});
					g[v].push_back({u,w});
				}
		}
	}
	for(int i = 1;i <= n;i++)
		dijkstra(i);
	while(q--)
	{
		int qx,qy; cin >> qx >> qy;
		cout << get_min(qx,qy) << "\n";
	}
	return 0;
}

