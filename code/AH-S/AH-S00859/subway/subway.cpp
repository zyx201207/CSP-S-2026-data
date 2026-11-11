#include<bits/stdc++.h>
using namespace std;
#define LL long long
int c, n, m, d, q; 
int a[500005], nn[505], s[500005];
struct node
{
	int x, y;
};
vector<node> b[505];
bool v[505][500005];
struct abc
{
	int x, y, z;
};
bool operator <(abc a, abc b)
{
	return a.x < b.x;
}
set<abc> vis;
LL minn = 10000000000000000;
int check(int x, int y)
{
	for(int i = 0; i < nn[x]; i ++)
	{
		if(b[x][i].x == y)
			return i;
	}
}
void DFS(int u, int x, LL sum, int id)
{
//	cout << u << ' ' << x << ' ' << sum << ' ' << id << '\n';
	if(u == id)
	{
		minn = min(minn, sum + b[x][check(x, u)].y);
		return;
	}
	if(vis.count({u, x, sum}))
		return;
	vis.insert({u, x, sum});
	for(int i = 0; i < nn[x]; i ++)
	{
		int t = b[x][i].x;
		if(t == id)
			DFS(t, x, sum, id);
		if(s[t] != 1)
		{
//			cout << t << '\n';
			for(int j = 1; j <= m; j ++)
			{
				if(j == x)
					continue;
				if(v[j][t])
					DFS(t, j, sum + b[x][check(x, t)].y + b[j][check(j, t)].y, id);
			}
		}
	}
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
	cin >> c >> m >> n >> d >> q;
	for(int i = 1; i <= n; i ++)
		scanf("%d", &a[i]);
	for(int i = 1; i <= m; i ++)
	{
		int t1, t2;
		scanf("%d", &nn[i]);
//		b[i].resize(t);
		for(int j = 1; j <= nn[i]; j ++)
		{
			scanf("%d%d", &t1, &t2);
			v[i][t1] = 1;
			s[t1] ++;
//			cout << s[t1] << '\n';
			b[i].push_back({t1, t2});
		}
	}
	while(q --)
	{
		int t1, t2;
		scanf("%d%d", &t1, &t2);
		minn = 10000000000000000;
		for(int i = 1; i <= m; i ++)
		{
//			cout << v[i][t1] << '\n';
			if(v[i][t1])
			{
				vis.clear();
//				cout << i << '\n';
				DFS(t1, i, a[t1] + a[t2] + b[i][check(i, t1)].y, t2);
//				cout << a[t1] + a[t2] + b[i][t1].y << ' ';
			}
				
		}
		printf("%lld\n", minn);
	}
	return 0;
}

