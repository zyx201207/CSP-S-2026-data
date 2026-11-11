#include<bits/stdc++.h>

using namespace std;

const int maxn = 510;
const int maxm = 5e5 + 10;
const int maxq = 1e5;

int c, n, m, d, q, w[maxm], a[maxm], t[maxm], qx[maxq], qy[maxq];

vector<int> edge[maxn];

void build()
{
	for (int i = 1;i <= n;i++)
	{
		for (int j = 1;j <= n;j++)
		{
			if (i != j && abs(a[i] - a[j]) <= d)
			{
				edge[i].push_back(j);
				edge[j].push_back(i);
			}
		}
	}
}

int main()
{
	cin >> c >> n >> m >> d >> q;
	
	for (int i = 1;i <= m;i++)
	{
		scanf("%d", &w[i]);
	}
	
	for (int i = 1;i <= n;i++)
	{
		int kk;
		scanf("%d", &kk);
		
		for (int j = 1;j <= kk;j++)
		{
			scanf("%d%d", &a[j], &t[j]);
		}
	}
	
	for (int r = 1;r <= q;r++)
	{
		scanf("%d%d", &qx[r], &qy[r]);
	}
	
	if (7 <= c && c <= 11)
	{
		
	}
}
