#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int N = 5e5 + 10;
const int INF = 0x3f3f3f3f;

LL ans[N] , n , m , a[N] , z[N] , cnt;
LL vis[N];

int main()
{
	freopen("card.in" , "r" , stdin);
	freopen("card.out" , "w" , stdout);
	
	cin >> n >> m;
	for(int i = 1; i<=n; i++)
	{
		cin >> a[i];
	}
	for(int i = 1; i<=n; i++)
	{
		for(int j = i; j<=n; j++)
		{
			if(vis[a[j]] == 0)
			{
				vis[a[j]] = cnt;
				z[++cnt] = a[j];
			}
			else
			{
				while(cnt > vis[a[j]])
				{
					cnt--;
					vis[z[cnt]] = 0;
					z[cnt] = 0;
				}
			}
		}
		for(int j = 1; j<=m; j++)
		{
			if(vis[j])
				ans[j]++;
		}
	}
	for(int i = 1; i<=m; i++)
		cout << ans[i] << ' ';
	
	return 0;
}
