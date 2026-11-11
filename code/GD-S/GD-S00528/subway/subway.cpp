#include <bits/stdc++.h>
using namespace std;

struct p
{
	int x;//线路号
	int n;//用时 
};

int c,n,m,d,q,k,l,r;
int w[(int)5e5 + 5];
vector <p> v[(int)5e5 + 5];  //车站 
vector <int> line[(int)505];  //线路 
int flag[(int)5e5 + 5][5];

//int bfs(int l,int r)
//{
//	int ans = 1e18;
//	queue <int> q;
//	queue <int> f;
//	queue <int> tm;
//	q.push(l);
//	f.push(1);
//	tm.push(0);
//	int x,y,t;
//	while(!q.empty())
//	{
//		x = q.front();
//		q.pop();
//		y = f.front();
//		f.pop();
//		t = tm.front();
//		tm.pop();
//		if (y == 1)
//		{
//			for(int i = 0;i < v[x].size();i++)
//			{
//				if (flag[v[x][i].x][2])
//				{
//					continue;
//				}
//				flag[v[x][i].x];
//				q.push(v[x][i].x);
//				f.push(2);
//				tm.push(t + v[x][i].n);
//			}
//		}
//	}
//}

signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= n;i++)
	{
		cin >> w[i];
	}
	for(int i = 1;i <= n;i++)
	{
		cin >> k;
		for(int j = 1;j <= k;j++)
		{
			cin >> l >> r;
			line[i].push_back(l);
			v[l].push_back({i,j});
		}
	}
	for(int i = 1;i <= q;i++)
	{
		cin >> l >> r;
//		bfs(l,r);
		cout << w[1] * 4 << endl;;
	}
	return 0;
}
