#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2e3 + 5;

struct node{
	int num, a[MAXN], t[MAXN];
};

int c, n, m, d, q, w[MAXN], x, y, minn = 0x3f3f3f3f;
int f[MAXN][MAXN]; 
node k[MAXN];
vector<int> mapp[MAXN];
bool da[MAXN] = {0};
 
void dfs(int now, int total) //当前站台 和 步行时间 
{
	if(now == y) 
	{
		minn = min(total + w[now], minn);
		return;
	}
	
	for(int i = 0; i < mapp[now].size(); i++) //当前站台可达的台线 
	{
		int now_xian = mapp[now][i]; //当前站台能到的线 
		int s = k[now_xian].t[now]; //到当前站台的时间
		 
		for(int j = 1; j <= k[now_xian].num; j++)//枚举地铁(站台)可达 
		{
			s = w[now];
			int v = k[now_xian].a[j]; 
			s += k[now_xian].t[k[now_xian].a[j]];	//加上到当前线路的时间 
			
			if(!da[v] && s < minn) 
			{
				da[v] = 1;
				dfs(v, total + s); 
				da[v] = 0;
			}
		}
	 } 
}

// Floyd 多源最短路 
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(NULL),cout.tie(NULL);
	
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++)
	{
		cin >> w[i];
	}
	
	for(int i = 1; i <= n; i++) 
	{
		cin >> k[i].num;
		for(int j = 1; j <= k[i].num; j++)
		{
			cin >> k[i].a[j] >> k[i].t[j];
			//分别意为 第 i 条线经过的站台 和 从此地铁站站厅(j)走到第 i 条线的时间
			mapp[k[i].a[j]].push_back(i); 
		}
	}
	
	/*for(int k = 1; k <= n; k++)
	{
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= n; j++)
			{
				
			}
		}
	}*/
	
	while(q--)
	{
		memset(da, 0, sizeof(da));
		cin >> x >> y;
		dfs(x, w[x]);
		cout << minn << endl; 
	}
	
	
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
*/
/*0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3*/
