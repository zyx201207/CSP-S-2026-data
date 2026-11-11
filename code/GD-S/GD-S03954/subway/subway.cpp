#include<bits/stdc++.h>
#define ll long long
#define For(i, x, y) for(int i = x; i <= y; i++)
#define RFor(i, x, y) for(int i = x; i >= y; i--)
using namespace std;
const int N = 505, M = 5e5+5, Q = 1e5+5;
const ll inf = 0x3f3f3f3f;
int c, n, m, d, q; // c测试点编号  n条线路  m个地铁站  最多d条路线穿过一个地铁站  q个测试 
int w[M]; //地铁口到站厅时间 
int k[N]; //i路线穿过k[i]个地铁口 
int tmp;
struct node {
	int a, t; //a[i][j] a:i路线经过地铁站a  t:地铁站的站厅a走到第i条线路的站台需要t时间 
}tmpa;
vector<node> to[N+M];
bool cmp(node x, node y)
{
	return x.t < y.t;
}
int T;
bool mar = 1;
void init()
{
	scanf("%d%d%d%d%d",&c, &n, &m, &d, &q);
	For(i, 1, m)
		scanf("%d",&w[i]);
	For(i, 1, n)
	{
		scanf("%d",&tmp);
		For(j, 1, tmp)
		{
			scanf("%d%d",&tmpa.a, &tmpa.t);
			to[m+i].push_back(tmpa);			
			to[tmpa.a].push_back({m+i, tmpa.t});			
		}
	}
	tmp = n+m;
	For(i, 1, tmp)
		sort(to[i].begin(), to[i].end(), cmp);
}
ll ans, res;
int st, ed;
int vis[M+N], now;
void dfs(int x, ll sum)
{
//	printf("%d %lld\n",x, sum);
	if(x == ed)
	{
		ans = min(sum, ans);
		return;
	}
	for(node j:to[x])
	{	
//		printf("%d to %d\n",x, j.a);
		res = sum+j.t;
		if(vis[j.a] > res)
		{
			vis[j.a] = res;
			dfs(j.a, res);
		}
	}
}
queue<node> que;
void dfs_2(int x)
{
//	printf("%d %lld\n",x, sum);
	que.push({x, 0});
	vis[x] = 1;
	while(!que.empty())
	{
		node e = que.front();
		que.pop();
		for(node j:to[e.a]) if(!vis[j.a])
		{
//			printf("%d to %d %d\n",e.a, j.a, e.t+j.t);
			if(j.a == ed)
			{
				ans = e.t+j.t;
				return;
			}
			vis[j.a] = 1;
			que.push({j.a, e.t+j.t});
		}
	}
}
//void out();
int main()
{
  freopen("subway.in", "r", stdin);
  freopen("subway.out", "w", stdout);
	init();
//	out(); 
	T = to[m+1][0].t;
	For(i, m+1, m+n) for(node j:to[i])
		mar &= (j.t == T);
//	cout<< "mar"<< mar<< "\n";
	if(!mar)
	{
		for(now = 1; now <= q; now++)
		{
			scanf("%d%d",&st, &ed);
			ans = inf;
			memset(vis, 0x3f, sizeof vis);
			dfs(st, 0);
	//		printf("%lld ",ans);
			printf("%lld\n",ans+w[st]+w[ed]);
		}
	}
	else
	{
		for(now = 1; now <= q; now++)
		{
			scanf("%d%d",&st, &ed);
			memset(vis, 0, sizeof vis);
			dfs_2(st);
	//		printf("%lld ",ans);
			printf("%lld\n",ans+w[st]+w[ed]);
		}
	}
	return 0;
}
//void out()
//{
//	For(i, 1, m+n)
//	{
//		printf("to[%d]:",i);
//		for(node j:to[i])
//			printf("%d ",j.a);
//		printf("\n");
//	}
//}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
