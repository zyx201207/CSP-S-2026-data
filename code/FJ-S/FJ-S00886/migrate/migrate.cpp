#include <cstdio>
using namespace std;

const int SIZE = 2e6 + 10;
int c, t, n;
int net[SIZE] = {0};
long long d, res;
long long a[SIZE] = {0};

void dfs(int l, int r)
{
	int dis = 0, cnt = 1;
	for(int i = l; i < r; i = net[i])
	{
		dis++;
		if(net[i] == i)
		{
			return;
		}
	}
	
	int t;
	for(int k = l; k <= r; k++)
	{
		t = 0;
		for(int i = k; i < r; i = net[i])
		{
			t++;
		}
		if(dis == t)
		{
			cnt++;
			continue;
		}
		break;
	}
	if(cnt == 2)
	{
		res++;
	}
}

void solve()
{
	for(int i = 1, j = 2, t; i <= n; i++)
	{	
		while(a[j] - a[i] <= d && j <= n)
		{
			t = j;
			j++;
		}
		net[i] = t;
	}
	
	for(int i = 1; i <= n; i++)
	{
		for(int j = i + 3; j <= n; j++)
		{
			dfs(i, j);
		}
	}
}

int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	scanf("%d%d", &c, &t);
	while((t--) > 0)
	{
		scanf("%d%lld", &n, &d);
		for(int i = 1; i <= n; i++)
		{
			scanf("%lld", &a[i]);
		}
		
		res = 0;
		solve();
		printf("%lld\n", res);
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
