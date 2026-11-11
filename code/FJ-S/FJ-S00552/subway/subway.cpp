#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;

int c, n, m, d, q;
int w[N], a[505], t[505];
struct node{
	int v, w;
};
int dp[2005][2005];

int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	memset(dp, 0x3f, sizeof(dp));
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++){
		cin >> w[i];
	}
	for(int i = 1; i <= n; i++){
		int k;
		cin >> k;
		for(int j = 1; j <= k; j++){
			cin >> a[j] >> t[j];
			for(int v = 1; v < j; v++){
				dp[a[j]][a[v]] = min(dp[a[j]][a[v]], t[j] + t[v]);
				dp[a[v]][a[j]] = min(dp[a[j]][a[v]], t[j] + t[v]);
			}
		}
	}
	for(int k = 1; k <= m; k++){
		for(int i = 1; i <= m; i++){
			for(int j = 1; j <= m; j++){
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
			}
		}
	}
	for(int i = 1; i <= q; i++){
		int x, y;
		cin >> x >> y;
		cout << w[x] + w[y] + dp[x][y] << endl;
	}
	return 0;
}
