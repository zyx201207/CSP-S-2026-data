#include <bits/stdc++.h>
using namespace std;
#define LL long long

const int N = 1010;
const LL inf = 1e19;

int ceshi,t;
int n; LL m;
LL a[N];
LL d[N][N];
LL cnt[N][N];

void floyd()
{
	for (int k = 1;k <= n;k++)
	for (int i = 1;i <= n;i++)
	for (int j = 1;j <= n;j++)
	{
		if (d[i][k] != inf && d[k][j] != inf){
			d[i][j] = min(d[i][j],d[i][k] + d[k][j]);
			//if (d[i][j] > m) d[i][j] = inf;
		}
	}
}

int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	scanf("%d%d",&ceshi,&t);
	while (t--)
	{
		cin>>n>>m;
		for (int i = 1;i <= n;i++) cin>>a[i];
		for (int i = 1;i <= n;i++)
		for (int j = 1;j <= n;j++)
			d[i][j] = (i == j ? 0 : inf),cnt[i][j] = 0;
		for (int i = 1;i <= n;i++){
			for (int j = 1;j <= n;j++){
				if (abs(a[i] - a[j]) <= m)
				{
					d[i][j] = 1;
					cnt[i][j] = 1;
				}
			}
		}
		floyd();
		for (int k = 1;k <= n;k++)
		{
			for (int i = 1;i <= n;i++)
			{
				for (int j = 1;j <= n;j++)
				{
					if (d[i][j] > m) continue;
					if (d[i][k] > m) continue;
					if (d[k][j] > m) continue;
					if (k == i || k == j || i == j) continue;
					if (d[i][k] + d[k][j] == d[i][j]){
						cnt[i][j]++;
					}
				}
			}
		}
		LL ans = 0;
		for (int i = 1;i <= n;i++){
			for (int j = i + 1;j <= n;j++)
			{
				if (cnt[i][j] == 2) ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
