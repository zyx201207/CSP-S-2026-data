#include<bits/stdc++.h>
#define ll long long
#define For(i, x, y) for(int i = x; i <= y; i++)
#define RFor(i, x, y) for(int i = x; i >= y; i--)
using namespace std;
const int N = 2e3+5;
int c, T;
int n;
ll d, x[N];
vector<int> to[N];
int dis[N][N], cnt[N][N];
int tmp;
ll ans;
void sol()
{
	scanf("%d%lld",&n, &d);
	For(i, 1, n)
		scanf("%lld",&x[i]);
	memset(dis, 0x3f, sizeof dis);
	memset(cnt, 0, sizeof cnt);
	For(i, 1, n)
	{
		dis[i][i] = 0;
		For(j, i, n) if(x[j]-x[i] <= d)
			dis[i][j] = 1;
	}
	For(i, 1, n) For(j, i+1, n) 
	{
		if(dis[i][j] == 1) continue;
//		printf("%d\n",dis[i][j]);
		For(mid, i, j) if(x[mid]-x[i] <= d && x[j]-x[mid] <= d)
		{
			tmp = dis[i][mid]+dis[mid][j];
			if(tmp < dis[i][j])
			{
				dis[i][j] = tmp;
				cnt[i][j] = 0;
			}
			if(tmp == dis[i][j])
				cnt[i][j]++;
		}
	}
	ans = 0;
	For(i, 1, n) For(j, i+1, n)
		ans += (cnt[i][j] == 2);
	printf("%lld\n",ans);
}
int main()
{
  freopen("migrate.in", "r", stdin);
  freopen("migrate.out", "w", stdout);
	scanf("%d%d",&c, &T);
	while(T--)
		sol();
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/
/*
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/
