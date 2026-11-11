#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll inf = 100000000000000010;
int ccc,n,m,ddd,q;
ll w[500010];
ll cst[1010][1010];
ll a[1010],t[1010];
int que[1000010];
vector <int> e[1010];

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> ccc >> n >> m >> ddd >> q;
	for (int i = 1 ; i <= m ; i++)
	{
		scanf("%lld",&w[i]);
	}
	if (ccc <= 11)
	{
		for (int i = 1 ; i <= m ; i++)
		{
			for (int j = 1 ; j <= m ; j++)
			{
				if (i != j)
				{
					cst[i][j] = cst[j][i] = inf;
				}
			}
		}
		int k;
		for (int i = 1 ; i <= n ; i++)
		{
			cin >> k;
			for (int j = 1 ; j <= k ; j++)
			{
				cin >> a[j] >> t[j];
			}
			for (int j = 1 ; j <= k ; j++)
			{
				for (int j1 = 1 ; j1 <= k ; j1++)
				{
					if (j != j1)
					{
						cst[a[j]][a[j1]] = min(cst[a[j]][a[j1]],t[j] + t[j1]);
						cst[a[j1]][a[j]] = min(cst[a[j1]][a[j]],t[j] + t[j1]);
					}
				}
			}
		}
		for (int i = 1 ; i <= m ; i++)
		{
			for (int j = 1 ; j <= m ; j++)
			{
				if (i != j)
				{
					e[i].push_back(j);
					e[j].push_back(i);
				}
			}
		}
		for (int i = 1 ; i <= m ; i++)
		{
			int l = 1,r = 1;
			que[l] = i;
			int tmp;
			while (l <= r)
			{
				tmp = que[l];
				for (auto k : e[tmp])
				{
					if (cst[k][i] > cst[k][tmp] + cst[tmp][i] || tmp == i)
					{
						cst[k][i] = cst[k][tmp] + cst[tmp][i];
						r++;
						que[r] = k;
					}
				}
				l++;
			}
		}
	}
	int x,y;
	ll ans;
	while (q--)
	{
		scanf("%d %d",&x,&y);
		ans = w[x] + w[y] + cst[x][y];
		printf("%lld\n",ans);
	}
	return 0;
}
