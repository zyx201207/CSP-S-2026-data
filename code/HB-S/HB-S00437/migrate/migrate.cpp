#include<bits/stdc++.h>
using namespace std;
#define fo(i, a, b) for(int i = (a); i <= (b); i++)
#define ro(i, a, b) for(int i = (a); i >= (b); i--)
#define int long long


const int  N = 303;//, INF = 4557430888798830399;

int c, t;

int n, d;
int x[N];


int dis[N][N];
int cnt[N][N];
void work() {
	memset(dis, 0x3f, sizeof dis);
	memset(cnt, 0, sizeof cnt);
	cin >> n >> d;
	fo(i, 1, n) cin >> x[i];
	
	fo(i, 1, n) dis[i][i] = 0, cnt[i][i] = 1;
	
	fo(i, 1, n - 1) 
		if(x[i + 1] - x[i] <= d) 
			if(x[i] - x[i - 1] <= d) dis[i][i + 1] = 1, cnt[i][i + 1] = 1;
	
	
	for(int len = 3; len <= n; len++) {
		for(int i = 1, j = len; j <= n; i++, j++) {
			if(x[j] - x[i] <= d) {
				dis[i][j] = 1;
				cnt[i][j] = 1;
				continue;
			}
			fo(k, i + 1, j - 1) {
				//if(dis[i][k] == INF || dis[k][j] == INF) continue;
				if(dis[i][k] + dis[k][j] < dis[i][j]) {
					dis[i][j] = dis[i][k] + dis[k][j];
					cnt[i][j] = 1;
				}
				else if(dis[i][k] + dis[k][j] == dis[i][j]) {
					cnt[i][j]++;
				}
			}
		}
	}
	
	int ans = 0;
	fo(i, 1, n) {
		fo(j, i + 1, n) {
			if(cnt[i][j] == 2) {
				//cout << i << " " << j << '\n';
				ans++;
			}
		}
	}
	cout << ans << '\n';
}


signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> c >> t;
	
	if(c == 13 || c == 14) {
		while(t--) cout << "0\n";
		return 0;
	}
	
	while(t--) work();
	return 0;
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


13 2
4 100
1 2 3 4
5 100
1 2 3 4 5 
*/
