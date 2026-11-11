#include <bits/stdc++.h>
using namespace std;
long long head[1000005], nex[2000005], to[2000005], w[2000005], cnt;
long long k[505], kou[500005], dis[505][2005], book[2005], pq[505], line[500005], pq1[505], pq2[505];
const long long INF = 1000000000000000000;

void bdd(long long x, long long y, long long z)
{
	nex[++cnt] = head[x];
	head[x] = cnt;
	to[cnt] = y;
	w[cnt] = z;
}

struct node
{
	long long v, id;
	operator < (const node c)const
	{
		return v > c.v;
	}
};

priority_queue <node> q;

int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	long long c, n, m, d, qc;
	cin >> c >> n >> m >> d >> qc;
	for (int i = 1; i <= m; i++)
		cin >> kou[i];
	long long op = m;
	for (int i = 1; i <= n; i++)
	{
		cin >> k[i];
		for (int j = 1; j <= k[i]; j++)
		{
			long long q1, q2;
			cin >> q1 >> q2;
			op++;
			if (c <= 11)
			{
				bdd(q1, op, q2);
				bdd(op, q1, q2);
				if (j > 1)
					bdd(op - 1, op, 0);
			}
			else
				bdd(q1, i, q2);
		}
	}
	if (c <= 11)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= op; j++)
			{
				dis[i][j] = INF;
				book[j] = 0;
			}
			while (!(q.empty()))
				q.pop();
			node a;
			dis[i][i] = 0;
			a.v = 0;
			a.id = i;
			q.push(a);
			while (!q.empty())
			{
				node now = q.top();
				q.pop();
				if (book[now.id])
					continue;
				book[now.id] = 1;
				for (int j = head[now.id]; j; j = nex[j])
				{
					if (dis[i][to[j]] > now.v + w[j])
					{
						dis[i][to[j]] = now.v + w[j];
						a.v = now.v + w[j];
						a.id = to[j];
						q.push(a);
					}
				}
			}
		}
		for (int i = 1; i <= qc; i++)
		{
			long long s, t;
			cin >> s >> t;
			cout << dis[s][t] + kou[s] + kou[t];
			if (i != qc)
				cout << endl;
		}
		return 0;
	}
	else if (c <= 19)
	{
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				dis[i][j] = INF;
		for (int i = 1; i <= m; i++)
		{
			line[i] = 0;
			for (int j = head[i]; j; j = nex[j])
				pq[++line[i]] = to[j];
			for (int j1 = 1; j1 <= line[i]; j1++)
				for (int j2 = 1; j2 <= line[i]; j2++)
					dis[pq[j1]][pq[j2]] = 1;
		}
		for (int i = 1; i <= n; i++)
			dis[i][i] = 0;
		for (int k = 1; k <= n; k++)
			for (int i = 1; i <= n; i++)
				for (int j = 1; j <= n; j++)
					dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
		for (int i = 1; i <= qc; i++)
		{
			long long s, t;
			cin >> s >> t;
			long long minn = INF;
			int cnt = 0;
			for (int j = head[s]; j; j = nex[j])
				pq1[++cnt] = to[j];
			cnt = 0;
			for (int j = head[t]; j; j = nex[j])
				pq2[++cnt] = to[j];
			for (int j = 1; j <= line[s]; j++)
				for (int k = 1; k <= line[t]; k++)
					minn = min(minn, dis[pq1[j]][pq2[k]]);
			cout << (minn + 1) * 2 * w[1] + kou[s] + kou[t];
			if (i != qc)
				cout << endl;
		}
		return 0;
	}
	return 0;
}
