#include <bits/stdc++.h>
using namespace std;
#define LL long long

const int N = 1010;
const int inf = 1e9;

int ceshi,t;
int n,m;
vector<int> g[N];
int d[N][N];
int v[N],lv;
int fa[N];
int ans;

void floyd()
{
	for (int k = 1;k <= n;k++)
	{
		for (int i = 1;i <= n;i++)
		{
			for (int j = 1;j <= n;j++)
			{
				if (d[i][k] != inf && d[k][j] != inf){
					d[i][j] = min(d[i][j],d[i][k] + d[k][j]);
				}
			}
		}
	}
}
int find(int x)
{
	if (fa[x] == x) return x;
	return fa[x] = find(fa[x]);
}
bool check()
{
	for (int i = 1;i <= lv;i++) fa[v[i]] = i;
	for (int i = 1;i <= lv;i++){
		for (int j = 1;j <= lv;j++){
			if (i == j) continue;
			int x = v[i],y = v[j];
			int tx = find(x),ty = find(y);
			if (d[x][y] == 1 && tx != ty) fa[tx] = ty;
		}
	}
	int cnt = 0;
	for (int i = 1;i <= lv;i++){
		if (fa[v[i]] == i) cnt++;
	}
	return (cnt > 2);
}
void dfs(int u,int x)
{
	if (u == m + 1){
		if (check()) return ;
		int cnt = 0;
		for (int i = 1;i <= n;i++){
			int sum = 1e9;
			for (int j = 1;j <= lv;j++){
				if (i == v[j]) sum = 0;
				sum = min(sum,d[i][v[j]]);
			}
			cnt = max(cnt,sum);
		}
		ans = min(ans,cnt);
		return ;
	}
	for (int i = x;i <= n;i++)
	{
		v[++lv] = i;
		dfs(u + 1,i + 1);
		v[lv--] = 0;
	}
}

int main()
{
	cin>>ceshi>>t;
	while (t--)
	{
		memset(v,0,sizeof(v)); lv = 0;
		cin>>n>>m;
		for (int i = 1;i <= n;i++) g[i].clear();
		for (int i = 1;i <= n;i++)
		for (int j = 1;j <= n;j++)
			d[i][j] = (i == j ? 0 : inf);
		for (int i = 1;i < n;i++)
		{
			int x,y; cin>>x>>y;
			d[x][y] = d[y][x] = 1;
		}
		floyd();
		ans = 1e9;
		dfs(1,1);
		cout<<ans<<"\n";
	}
	return 0;
}
