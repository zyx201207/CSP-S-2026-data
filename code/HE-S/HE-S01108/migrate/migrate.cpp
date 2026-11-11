#include <iostream>
#include <cstring>
using namespace std;
#define int long long

const int N = 2e6 + 10;
int a[N];
int dis[305][305], cnt[305][305];

signed main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	int c, T; cin >> c >> T;
	while(T--)
	{
		int n, d; cin >> n >> d;
		memset(dis, 0x3f, sizeof(dis));
		memset(cnt, 0, sizeof(cnt));
		for(int i = 1; i <= n; i++) cin >> a[i];
		for(int i = 1; i <= n; i++)
		{
			int j = i + 1;
			while(j <= n && abs(a[i] - a[j]) <= d)
				dis[i][j] = dis[j][i] = 1,
				cnt[i][j] = cnt[j][i] = 1,
				j++;
		}
		
		for(int k = 1; k <= n; k++)
			for(int i = 1; i <= n; i++) 
				for(int j = 1; j <= n; j++)
				{
					// if(k > j || k < i) continue;
					if(dis[i][j] > dis[i][k] + dis[k][j])
						dis[i][j] = dis[i][k] + dis[k][j],
						cnt[i][j] = 1;
					else if(dis[i][j] == dis[i][k] + dis[k][j])
						cnt[i][j]++;
				}
					
		int ans = 0;
		for(int i = 1; i <= n; i++)
			for(int j = i + 1; j <= n; j++) 
				if(cnt[i][j] == 2) ans++;
		
		cout << ans << '\n';
		
	}
}

/*
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6


0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

*/
