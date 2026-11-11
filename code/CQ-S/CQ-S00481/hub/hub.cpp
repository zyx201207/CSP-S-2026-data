#include <bits/stdc++.h>
using namespace std;

int c, T, n, k, dp[1010][1010], ff[1010][1010], mid;
vector<int> edge[1000010];

inline void dfs(int x, int fa){
	dp[x][0] = 1;
	for (int i = 0; i <= mid; i++)
		ff[x][i] = 0;
	for (auto y : edge[x])
		if (y != fa){
			dfs(y, x);
			for (int i = 1; i <= mid; i++)
				if (ff[x][i] < 1 << 30)
					for (int j = 1; i + j <= mid; j++)
						if (ff[y][j - 1] < 1 << 30)
							dp[x][i + j] = min(dp[x][i + j], ff[x][i] + ff[y][j - 1]);
			int res = 1 << 30;
			for (int i = 1; i <= mid; i++){
				res = min(res, ff[y][i - 1]);
				ff[x][i] += res;
			}
			dp[x][0] += res;
		}
//	cout<<mid<<" "<<x<<" "<<dp[x][0]<<"\n";
}

int main(){
	freopen ("hub.in", "r", stdin);
	freopen ("hub.out", "w", stdout);
	scanf ("%d%d", &c, &T);
	for (; T--; ){
		scanf ("%d%d", &n, &k);
		for (int i = 1; i <= n; i++)
			edge[i].clear();
		for (int i = 1; i < n; i++){
			int x, y;
			scanf ("%d%d", &x, &y);
			edge[x].push_back(y);
			edge[y].push_back(x); 
		}
		int L = 0, R = n;
		for (; L + 1 < R; ){
			mid = (L + R) / 2;
			dfs(1, 0);
			for (int i = 1; i <= n; i++)
				for (int j = 0; j <= mid; j++)
					dp[i][j] = ff[i][j] = 1 << 30;
			int res = 1 << 30;
			for (int i = 0; i <= mid; i++)
				res = min(res, dp[1][i]);
//			cout<<res<<" "<<k<<" "<<mid<<"\n";
			if (res <= k)
				R = mid;
			else
				L = mid;
		}
		if (k == n)
			printf ("0\n");
		else
			printf ("%d\n", R);
	}                           
	return 0;
}
