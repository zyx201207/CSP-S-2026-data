#include <bits/stdc++.h>
using namespace std;
const int N = 5e5+5;
int m, n, q, d, c;
int w[N];
vector <int> line[505];
struct node{
	int l, time;
};
vector <int> v[N];
bool f[505][1005];
vector <int> s[N];

//int p[N];
//void root(int x)
//{
//	return x == p[x] ? x : x = root(p[x]);
//}
//void add(int x, int y)
//{
//	int rx = root(x), ry = root(y);
//	if (rx == ry)
//		return;
//	p[rx] = ry;
//}

int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++)
	{
		cin>> w[i];
		//p[i] = i;
	}
	for (int i = 1, k; i <= n; i++)
	{
		cin >> k;
		for (int j = 1, a, t; j<= k; j++)
		{
			cin >> a >> t;
			line[i].push_back(a);
			f[i][a] = 1;
			v[a].push_back({i, t});
		}
	}
	for (int i = 1; i <= n; i++)
	{
		int siz = line[i].size();
		for (int j = 0; j < siz-1; i++)
		{
			s[line[i][j]].push_back(line[i][j+1]);
			s[line[i][j+1]].push_back(line[i][j]);
		}
		s[line[i][siz-1]].push_back(line[i][0]);
		s[line[i][0]].push_back(line[i][siz-1]);
	}
	for (int i = 1, x, y; i <= q; i++)
	{
		cin >> x >> y;
	}
	return 0;
}
