#include <bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[500005],k[505];
vector<long long> a[505],t[505];
long long f[505][505];
struct Node{
	long long v,w;
};
vector<Node> v[500005];
long long ans;
long long minn(long long a,long long b)
{
	if (a > b)
		return b;
	return a;
}
void floyd()
{
	for (int i = 1;i <= n;i++)
		for (int j = 1;j <= n;j++)
			for (int k = 1;k <= n;k++)
				if (i != j && i != k && j != k)
					f[i][j] = minn(f[i][j],f[i][k] + f[j][k]);
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1;i <= m;i++)
		cin >> w[i];
	for (int i = 1;i <= n;i++)
	{
		cin >> k[i];
		for (int j = 1;j <= k[i];j++)
		{
			int aa,tt;
			cin >> aa >> tt;
			a[i].push_back(aa);
			t[i].push_back(tt);
			v[aa].push_back({i,tt});
		}
	}
	for (int i = 1;i <= n;i++)
		for (int j = 1;j <= n;j++)
			f[i][j] = f[j][i] = 1e18;
	for (int i = 1;i <= m;i++)
	{
		for (int j = 1;j < v[i].size();j++)
		{
			for (int k = 0;k < j;k++)
			{
//				e[v[i][j].v].push_back({v[i][k].v,v[i][j].w + v[i][k].w});
//				e[v[i][k].v].push_back({v[i][j].v,v[i][j].w + v[i][k].w});
				f[v[i][j].v][v[i][k].v] = f[v[i][k].v][v[i][j].v] = minn(f[v[i][j].v][v[i][k].v],v[i][j].w + v[i][k].w);
			}
		}
	}
	floyd();
	for (int i = 1;i <= n;i++)
		f[i][i] = 0;
	for (int i = 1;i <= q;i++)
	{
		int s,e;
		ans = INT_MAX;
		cin >> s >> e;
		for (Node j : v[s])
			for (Node k : v[e])
				ans = minn(ans,f[j.v][k.v] * 1LL + j.w + k.w);
		ans += w[s] + w[e];
		cout << ans << endl;
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
