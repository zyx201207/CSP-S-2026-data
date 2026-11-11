#include <bits/stdc++.h>
using namespace std;

const int N = 305;

int cnt[N][N][N];
int c, t;
int n, d;
int a[N];

void dfs(int s, int nw, int stp){
	cnt[s][nw][stp]++;
	for (int i = nw + 1; i <= n && a[i] - a[nw] <= d; i++){
		dfs(s, i, stp + 1);
	}
	return;
}

int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> t;
	while (t--){
		cin >> n >> d;
		memset(cnt, 0, sizeof(cnt));
		for (int i = 1; i <= n; i++){
			cin >> a[i];
		}
		for (int i = 1; i <= n; i++){
			dfs(i, i, 0);
		}
		int ans = 0;
		for (int i = 1; i <= n; i++){
			for (int j = i + 1; j <= n; j++){
				for (int k = 0; k <= n; k++){
					if (cnt[i][j][k] > 0){
						//cout << i << " " << j << " " << k << " " << cnt[i][j][k] << "\n";
						if (cnt[i][j][k] == 2){
							ans++;
						}
						break;
					}
				}
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
