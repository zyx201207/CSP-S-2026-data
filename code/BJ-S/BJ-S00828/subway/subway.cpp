#include <bits/stdc++.h>
using namespace std;
const int maxm = 5e4 + 5;
const int INF = 5e4 + 5;
int c,n,m,d,q,ans = INF;
int w[maxm];
vector<pair<int,int>> v[maxm];
struct Node
{
	int num;
	pair<int,int> k[maxm];
}a[505];
int dis[maxm][505];
void dfs(int x,int y,int ti)
{
	int cnt = v[x].size();
	for(int j = 0;j < cnt;j++)
	{
		int kkk = v[x][j].first;//当前线路
		int tii = v[x][j].second;
		dis[x][kkk] = 1;
		for(int i = 1;i <= a[kkk].num;i++)
		{
			int vv = a[kkk].k[i].first;
			int ww = a[kkk].k[i].second;
			if(v[vv].size() <= 1 && vv != y) continue;
			if(dis[vv][kkk]) continue;
			if(vv == y) {ans = min(ans,ti + tii + ww);continue;}
			dfs(vv,y,ti + tii + ww);
		}
		dis[x][kkk] = 0;
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;i++) cin >> w[i];
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i].num;
		int kk = a[i].num;
		for(int j = 1;j <= kk;j++)
		{
			cin >> a[i].k[j].first >> a[i].k[j].second;
			v[a[i].k[j].first].push_back({i,a[i].k[j].second});
		}
	}
	while(q--)
	{
		int x,y;
		cin >> x >> y;
		dfs(x,y,0);
		cout << ans + w[x] + w[y] << endl;
	}
	return 0;
}
