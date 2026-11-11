#include<bits/stdc++.h>
using namespace std;
const int N = 2e6 + 10;
int n;
long long a[N], d, cnt, mn;
void dfs(int u, int s, int t)
{
//	cout << u << ' ' << s << endl;
	if(cnt > 2) return;
	if(u == t)
	{
		if(s == mn) cnt++;
		else if(s < mn)
		{
			mn = s;
			cnt = 1;
		}
		
		return;
	}
	if(s > mn) return;
	for(int i = t; i >= u+1; i--)
	{
		if(a[i]-a[u] <= d)
		{
			dfs(i, s+1, t);
		}
	}
}
int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, t;
	cin >> c >> t;
	while(t--)
	{
		cin >> n >> d;
		int ans = 0;
		for(int i = 1; i <= n; i++)
		{
			scanf("%lld", &a[i]);
		}
		if(c == 11 || c == 12)
		{
			long long k = a[2] - a[1];
			if(d/2 < k) printf("0\n");
			else
			{
				printf("%lld\n", max(0ll, n - (d/k)*2+1));
			}
		}
		else if(c == 13 || c == 14)
		{
			printf("0");
		}
		else
		{
			for(int i = 1; i <= n-1; i++)
			{
				for(int j = i+1; j <= n; j++)
				{
//					cout << i << ", " << j << endl;
					cnt = 0;
					mn = 1e9;
					dfs(i, 0, j);
					if(cnt == 2)
					{
	//					printf("%d, %d\n", i, j);
						ans++;
					}
				}
			}
			printf("%lld\n", ans);
		}
	}
	return 0;
}
