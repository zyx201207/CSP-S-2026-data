#include<bits/stdc++.h>
//#define endl '\n'
#define debug() cout << "qwq" << endl;
#define int long long
using namespace std;

const int N = 310;
int c, t, n, d;
int x[N];
int f[N][N], g[N][N];

signed main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	cin >> c >> t;
	while(t --){
		cin >> n >> d;
		for(int i = 1; i <= n; i ++) cin >> x[i];
		x[n + 1] = x[n + 2] = x[n + 3] = 1e18;
		
		if(c <= 10){
			int res = 0;
			for(int u = 1; u < n; u ++) if(x[u + 1] - x[u] <= d) f[u][u + 1] = 1, g[u][u + 1] = 1;
			for(int u = 1; u < n - 1; u ++){
				if(x[u + 2] - x[u] <= d) f[u][u + 2] = 2, g[u][u + 1] = 1	;
				else if(x[u + 2] - x[u + 1] <= d && x[u + 1] - x[u] <= d) f[u][u + 2] = 1;
				else f[u][u + 2] = 0;
			}
			for(int len = 3; len <= n; len ++){
				for(int u = 1; u <= n; u ++){
					int v = u + len;
					for(int k = u + 1; k < v; k ++){
						f[u][v] = max(f[u][v], f[u][k] * f[k][v]);
					}
					if(f[u][v] == 2) res ++;
				}
			}
			cout << res << endl;
		}
	}

	return 0;
}

