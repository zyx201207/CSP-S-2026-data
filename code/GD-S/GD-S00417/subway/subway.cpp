#include <bits/stdc++.h>
#define ll long long
using namespace std;
int c1 , n , m , d , q;
const int N = 500 + 5 , M = 2 * 5e5 + 5;
int cnt , head[M] , edge[2 * M][3];
void add(int x , int y , int c)
{
	edge[++cnt][0] = x , edge[cnt][1] = c , edge[cnt][2] = head[y] , head[y] = cnt;
}
int w[M];
int a[M] , num[M];
ll dis[M];
ll g1[N][N];
int que[M];
bool vis[M];
ll cs[N];
ll g2[100 + 1][int(5e5 + 1)];
priority_queue<pair<ll , int>>h;
void dij(int x)
{
	for(int i = 1;i <= n + m;i++)dis[i] = 1e18;
	dis[x] = 0;
	h.push({dis[x] , x});
	while(!h.empty())
	{
		auto p = h.top();
		h.pop();
		for(int i = head[p.second];i;i = edge[i][2])
		{
			int y = edge[i][0] , z = edge[i][1];
			if(dis[p.second] + z < dis[y])
			{
				dis[y] = dis[p.second] + z , h.push({dis[y] , y});
			}
		}
	}
}
void bfs(int x)
{
	for(int i = 1;i <= n + m;i++)dis[i] = 1e18 , vis[i] = 0;
	int head2 = 0 , tail = 1;
	que[tail] = x;
	dis[x] = 0;
	vis[x] = 1;
	while(head2 < tail)
	{
		head2++;
		int s = que[head2];
		for(int i = head[s];i;i = edge[i][2])
		{
			int y = edge[i][0] , c = edge[i][1];
			if(vis[y] == 0)
			{
				vis[y] = 1;
				dis[y] = dis[que[head2]] + c;
				que[++tail] = y;
			}
		}
	}
}
int main()
{
	freopen("subway.in" , "r" , stdin) , freopen("subway.out" , "w" , stdout);
	cin>>c1>>n>>m>>d>>q;
	for(int i = 1;i <= m;i++)cin>>w[i];
	bool B = 1;
	int sss = -1;
	for(int i = 1;i <= n;i++)
	{
		int k;
		cin>>k;
		for(int j = 1;j <= k;j++)
		{
			cin>>a[j];
			cin>>num[j];
			if(sss == -1)sss = num[j];
			else if(sss != num[j])B = 0;
			add(a[j] , i + m , num[j]) , add(i + m , a[j] , num[j]);
		}
	}
	for(int i = 1;i <= n;i++)cs[i] = n;
	for(int i = 1;i <= n;i++)
	{
		if(cs[i] == 0)continue;
		if(B == 0)dij(i + m);
		else bfs(i + m);
		for(int j = 1;j <= n;j++)
			g1[i][j] = g1[j][i] = dis[j + m] , cs[j]--;
	}
	for(int i = 1;i <= q;i++)
	{
		int l , r;
		cin>>l>>r;
		ll ans = 1e18 + 5;
		for(int j = head[r];j;j = edge[j][2])
		{
			int y = edge[j][0] , c = edge[j][1];
			for(int j2 = head[l];j2;j2 = edge[j2][2])
			{
				int y2 = edge[j2][0] , c2 = edge[j2][1];
				ans = min(ans , g1[y2 - m][y - m] + c + c2);
			}
		}
		cout<<(ll)(w[l]) + (ll)(w[r]) + ans<<endl; 
	}
	return 0;
} 
