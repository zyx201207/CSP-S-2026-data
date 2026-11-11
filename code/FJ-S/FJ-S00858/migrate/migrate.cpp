#include<bits/stdc++.h>
#define int long long

using namespace std;

const int N = 2e6 + 10;

int c, t;
int n, d;
int x[N];

int dp[310][310], num[310][310], dis[310][310];

signed main() {
	freopen("migrate3.in", "r", stdin);
//	freopen("migrate.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> c >> t;

	while(t --) {
		memset(dp, 0, sizeof(dp));
		memset(num, 0, sizeof(num));
		memset(dis, 0x3f, sizeof(dis));
		
		cin >> n >> d;
		for(int i = 1 ; i <= n ; i ++)
			cin >> x[i];
			
		for(int i = 1 ; i <= n ; i ++) 
			for(int j = i + 1 ; j <= n ; j ++) 
				if(x[j] - x[i] <= d) 
					dp[i][j] = 1;
		
		
		
		for(int i = 1 ; i <= n ; i ++) {
			queue<int> q;
			dis[i][i] = 0;
			q.push(i);
			while(q.size()) {
				int u = q.front();
				
				q.pop();
				for(int j = u + 1 ; j <= n ; j ++) {
					if(dp[u][j] == 0)
						continue;
					if(dis[i][u] + 1 < dis[i][j]) {
						num[i][j] = 1;
						dis[i][j] = dis[i][u] + 1;
						q.push(j);
					}
					else if(dis[i][u] + 1 == dis[i][j])
						num[i][j] ++;
				} 
				
			}
		}
		int ans = 0;
		for(int i = 1 ; i <= n ; i ++) 
			for(int j = 1 ; j <= n ; j ++) 
				if(num[i][j] == 2) 
					ans ++; 				
		
		cout << ans << '\n';
	}
	
	return 0;
}
