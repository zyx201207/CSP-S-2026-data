//暴力floyd算法拿部分分
//一条线路不需要步行，看作一个点（编号1-n），换乘站也看作点（编号>n），点之间连线成图
//若进（出）站为换乘站，考虑起（终）点为换乘站点；若不是换乘站，考虑为线路点 
#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;

const int N = 505, M = 1005;
int c, n, m, d, q;
int ch[M + N]; //线路点和换乘点
int fch[M]; //换乘点对应ch序号 
int w[M]; //地铁口到站厅 
int t[M][N]; //站厅到 该站 的 该线路站台 
int dp[M + N][M + N];
vector<int> line[M]; //该站点有几条线路经过 

int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++)
		scanf("%d", &w[i]);
	for(int i = 1; i <= n; i++)
	{
		int k;
		scanf("%d", &k);
		for(int j = 1; j <= k; j++)
		{
			int a;
			scanf("%d", &a);
			line[a].push_back(i);
			scanf("%d", &t[a][i]);
		}
	}
	for(int i = 1; i <= n; i++)
		ch[i] = i;
	int tmp_cnt = n;
	for(int i = 1; i <= m; i++)
	{
		if(line[i].size() > 1)
		{
			ch[++tmp_cnt] = i;
			fch[i] = tmp_cnt;
		}
	}
	memset(dp, 0x3f, sizeof(dp));
	for(int i = 1; i <= tmp_cnt; i++)
		dp[i][i] = 0;
	for(int i = 1; i <= m; i++)
	{
		if(line[i].size() > 1) //该站点是换乘站 
		{
			for(int j = 0; j < line[i].size(); j++)
			{
				int jj = line[i][j]; //这是哪条线路 
				dp[jj][fch[i]] = t[i][jj];
				dp[fch[i]][jj] = t[i][jj];
			}
		}
	}
	for(int k = 1; k <= tmp_cnt; k++)
	{
		for(int i = 1; i <= tmp_cnt; i++)
		{
			for(int j = 1; j <= tmp_cnt; j++)
			{
				dp[ch[i]][ch[j]] = min(dp[ch[i]][ch[j]], dp[ch[i]][ch[k]] + dp[ch[k]][ch[j]]);
			}
		}
	}
	while(q--)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		int inw, outw, ins, outs;
		if(line[x].size() > 1) //换乘点入站 
		{
			inw = w[x];
			ins = fch[x];
		}
		if(line[x].size() <= 1)
		{
			inw = w[x] + t[x][line[x][0]];
			ins = line[x][0];
		}
		if(line[y].size() > 1) //换乘点出站
		{
			outw = w[y];
			outs = fch[y];
		} 
		if(line[y].size() <= 1)
		{
			outw = w[y] + t[y][line[y][0]];
			outs = line[y][0];
		}
		int anans = inw + outw + dp[ins][outs];
		cout << anans << endl;
	}
	return 0;
} 

//floyd忘记怎么写了QwQ 
