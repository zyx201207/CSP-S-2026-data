#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 510,M = 5 * 1e5 + 10;
int c,n,m,d,q,w[M],st[M],INF = 0x3f3f3f3f;
struct node{
	int id,w;
};
struct cmp{
	bool operator()(const node &x,const node &y){
		return x.w > y.w;
	}
};
vector <node> a[N];
vector <node> s[M];
vector <node> rode[M];
priority_queue<node,vector<node>,cmp> que;
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1;i <= m;i++) cin >> w[i];
	for (int i = 1;i <= n;i++)
	{
		int T;
		cin >> T;
		for (int j = 1;j <= T;j++)
		{
			int x,y;
			cin >> x >> y;
			a[i].push_back({x,y});
			s[x].push_back({i,y});
			st[x]++;
		}
		for (int j = 1;j <= T;j++)
		{
			for (int k = 1;k <= T;k++)
			{
				if (j == k) continue;
				rode[a[i][j].id].push_back({a[i][k].id,i});
			}
		}
	}
	while (q--)
	{
		int x,y,ans = INF;
		cin >> x >> y;
		if (c == 20 || c == 21)
		{
			int minx = INF,miny = INF;
			node tx1,tx2,ty1,ty2;
			tx1.id = 0;
			tx2.id = 0;
			for (int i = 0;i < s[x].size();i++)
			{
				minx = min(minx,s[x][i].w);
				for (int j = 0;j < s[y].size();j++)
				{
					miny = min(miny,s[y][j].w);
					if (s[x][i].id == s[y][j].id) 
					{
						if (tx1.id == 0)
						{
							tx1 = s[x][i];
							ty1 = s[y][j]; 
						}
						else 
						{
							tx2 = s[x][i];
							ty2 = s[y][j];
						}
					}
				}
			}
			if (tx1.id)
			{
				ans = min(ans,w[x] + w[y] + tx1.w + ty1.w);
			}
			if (tx2.id)
			{
				ans = min(ans,w[x] + w[y] + tx2.w + ty2.w);
			}
			while(!que.empty()) que.pop();
			for (int i = 1;i <= n;i++)
			{
				if (st[i] == 2 && i != x && i != y)
				{
					que.push({i,s[i][0].w + s[i][1].w});
				}
			}
			while (!que.empty())
			{
				node tt = que.top();
				que.pop();
				ans = min(ans,w[x] + w[y] + tt.w + minx + miny);
			}
			cout << ans << endl;
		}
		else
		{
			int minx = INF,miny = INF;
			for (int i = 0;i < s[x].size();i++) minx = min(minx,s[x][i].w);
			for (int j = 0;j < s[y].size();j++) miny = min(miny,s[y][j].w);
			cout << w[x] + w[y] + minx + miny << endl;
		}
	}
	return 0;
}
