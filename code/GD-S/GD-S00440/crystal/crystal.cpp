#include<iostream>
#include<cstring>

using namespace std;

long long a[20];
long long d[20];
bool vis[20];
int cnt;
int n;
int g[20];

void dfs(int u,int limit,int x,int score)
{
	cnt = max(cnt,score);
	if(limit == 0)
	{
		return;
	}
	for(int i = 1; i <= n; i ++ )
	{
		if(g[i] >= n) return ;
	}
	for(int v = 1; v <= n; v ++ )
	{
		if(!vis[v])
		{
			if(x + d[v] <= limit)
			{
				vis[v] = 1;
				g[v] ++ ;
				dfs(v,limit,x + d[v], score + 1);
				vis[v] = 0;
			}
		}
	}
}

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int m;
	cin >> n >> m;
	bool f = true; 
	for(int i = 1; i <= n; i ++ )
	{
		cin >> a[i];
		if(a[i] != i) f = false;
	}
	if(f == true)
	{
		int cnt = 1,pos = 0x3f3f3f3f;
		while(m)
		{
			if(m % 2 == 1) pos = min(pos,cnt);
			m /= 2;
			cnt ++ ;
		}
		cout << (1 << (cnt - pos));
		return 0;
	}
	int ans = 0;
	for(int i = 1; i <= n; i ++ )
	{
		memset(vis,0,sizeof(vis));
		int res = 0;
		cnt = 0;
		for(int j = 1; j <= n; j ++ )
		{
			d[j] = llabs(a[i] - a[j]);
			if(d[j] == 0)
			{
				res ++ ;
				vis[j] = 1;
			}
		}
		dfs(i,m,0,0);
		ans = max(ans,cnt + res);
	}
	cout << ans;
	return 0;
}
