#include <bits/stdc++.h>
using namespace std;
int cnt = 1;
int head[100005];
long long dis[100005];
bool visiter[100005];
int score[500005];
long long au[100005];
int m,n,c,d,q;
int cnt_dz;
struct f{
	int from;
	int to;
	int w;
	int next;
}e[200005];

struct cter{
	int l;
	int r;
	int id;
}tcd[100005];

bool cmp(cter x,cter y)
{
	return x.l < y.l;
}

struct node{
	int id;
	long long val;
};

bool operator < (node x,node y)
{
	return x.val > y.val;
}

priority_queue<node> pq;

void add(int u,int v,int w)
{
	e[cnt].from = u;
	e[cnt].to = v;
	e[cnt].w = w;
	e[cnt].next = head[u];
	head[u] = cnt++;
}


void ginit()
{
	for(int i=1;i<=cnt_dz;i++)
	{
		visiter[i] = false;
		dis[i] = 1e18;
	}
}

void dijkstra(int s)
{
	ginit();
	dis[s] = 0;
	pq.push({s,dis[s]});
	while(!pq.empty())
	{
		node p = pq.top();
		pq.pop();
		int idx = p.id;
		if(visiter[idx]) continue;
		visiter[idx] = true;
		for(int i=head[idx];i!=-1;i=e[i].next)
		{
			int v = e[i].to;
			int w = e[i].w;
			if(dis[v] >= dis[idx] + w)
			{
				dis[v] = dis[idx] + w;
				pq.push({v,dis[v]});
			}
		}
	}
}

void init()
{
	for(int i=1;i<=100001;i++)
	{
		head[i] = -1;
	}
}

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> c >> m >> n >> d >> q;
	init();
	for(int i=1;i<=n;i++)
	{
		cin >> score[i];
	}
	cnt_dz = n;
	for(int i=1;i<=m;i++)
	{
		int l;
		cin >> l;
		for(int j=1;j<=l;j++)
		{
			int x,y;
			cin >> x >> y;
			cnt_dz++;
			if(j == 1)
			{
				add(x,cnt_dz,y);
				add(cnt_dz,x,y);
			}
			else
			{
				add(x,cnt_dz,y);
				add(cnt_dz,x,y);
				add(cnt_dz-1,cnt_dz,0);
				add(cnt_dz,cnt_dz-1,0);
			}
		}
	}
	for(int i=1;i<=q;i++)
	{
		cin >> tcd[i].l >> tcd[i].r;
		tcd[i].id = i;
	}
	sort(tcd+1,tcd+q+1,cmp);
	for(int i=1;i<=q;i++)
	{
		if(tcd[i].l != tcd[i-1].l) dijkstra(tcd[i].l);
		int ll = tcd[i].l,rr = tcd[i].r;
		long long answer = dis[rr];
		answer += score[ll];
		answer += score[rr];
		au[tcd[i].id] = answer;
	}
	for(int i=1;i<=q;i++)
	{
		cout << au[i] << '\n';
	}
	return 0;
}
