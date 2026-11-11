#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e4 + 1;
int tr[501][MAXN][21]; // 第几条线 第几个地铁站 可以换哪些线
int st[MAXN][501];	   // 每个站有那些地铁线经过
int a[MAXN];		   // 地铁站厅到站台时间
int stnum[MAXN];		   // 地铁站经过多少个线
map<pair<int, int>, int>trnext;											  // i车下一个站
vector<vector<int>> traintm(501, vector<int>(MAXN, -78)); // i车到站厅的时间(第一行表示经过的地铁站数量)
int start, eend;
int f(int nowst, int nowtr)
{
	if (nowst == eend)
	{
		return a[nowst] + traintm[nowtr][nowst];
	}
	if (tr[nowtr][nowst][1] == 0)
	{
		return 2000000;
	}
	pair<int, int> pr;
	pr.first = nowtr;
	pr.second = nowst;
	int anstemp = 20000000;
	for (int i = 1; i <= tr[nowtr][nowst][tr[nowtr][nowst][0] - 1]; i++)
	{
		pair<int, int> pr3;
		pr3.first = tr[nowtr][nowst][i];
		pr3.second = nowst;
		anstemp = min(anstemp, f(trnext[pr3], tr[nowtr][nowst][i]) + a[nowst] + a[nowst]);
	}
	return min(f(trnext[pr], nowtr), anstemp);
	return traintm[nowtr][nowst];
}
int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	int c, n, m, d, q;
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++)
		cin >> a[i];
	int pastst = 0;
	for (int i = 1; i <= n; i++)
	{
		int t1, t2, t3;
		cin >> t1;
		traintm[i][0] = t1; // 经过的站数
		for (int j = 1; j <= t1; j++)
		{
			cin >> t2 >> t3;
			traintm[i][t2] = t3;
			st[t2][++st[t2][0]] = i;
			stnum[t2]++;
			pair<int, int> pr2;
			pr2.first = i;
			pr2.second = pastst;
			trnext[pr2] = t3;
			pastst = t3;
		}
	}
	// 处理tr数组
	for (int i = 1; i <= n; i++)
	{
		for (int temp = 1; temp <= m; temp++)
		{
			if (traintm[i][temp] != -78)
			{
				// temp为该车经过的站
				for (int j = 1; j <= stnum[temp] - 1; j++)
				{
					if (st[temp][j] == i)
						continue;
					tr[i][temp][++tr[i][temp][0]] = st[temp][j];
				}
			}
		}
	}
	while (q--)
	{
		cin >> start >> eend;
		int finalans = INT_MAX;
		for (int i = 1; i <= st[start][st[start][0] - 1]; i++)
		{
			finalans = min(finalans, f(start, st[start][i]));
		}
		cout << finalans << '\n';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
