#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 5005;

int n, d, a[N];
int f[N][N], c[N][N];

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int k, _;
	cin >> k >> _;
	while(_ --) {
		cin >> n >> d;
		for(int i = 1; i <= n + 5; i ++) {
			for(int j = 1; j <= n + 5; j ++)
				f[i][j] = 0x3f3f3f3f3f, c[i][j] = 0;
			f[i][i] = 0;
		}
		for(int i = 1; i <= n; i ++) cin >> a[i];
		for(int i = 1; i <= n; i ++) {
			for(int j = i + 1; j <= n; j ++) {
				if(a[j] - a[i] <= d) f[i][j] = 1;
			}
		}
		for(int u = 1; u <= n; u ++) {
			for(int i = u; i <= u + d; i ++) {
				for(int j = i; j <= i + d; j ++) {
					if(i > n || j > n) continue;
					f[u][j] = min(f[u][i] + f[i][j], f[u][j]);
				}
			}		
		}
		for(int u = 1; u <= n; u ++) {
			for(int i = u; i <= n; i ++) {
				for(int j = i; j <= n; j ++) {
					if(i > n || j > n) continue;
					if(a[i] - a[u] > d || a[j] - a[i] > d) continue;
					if(f[u][i] + f[i][j] == f[u][j] && i != j) c[u][j] ++;
				}
			}			
		}
		int ans = 0;
		for(int i = 1; i <= n; i ++) {
			for(int j = 1; j <= n; j ++) {
				if(c[i][j] == 2) ans ++;
//				if(c[i][j] == 0x3f3f3f3f3f) cout << "S ";
//				else cout << c[i][j] << " ";
			}
//			cout << endl;
		}
//		cout << "->";
		cout << ans << '\n';
	}
	return 0;
} 

/*
Folyd´ó·¨ºÃ£¨£¿ 
fraopen() fraopen() fraopen() fraopen() fraopen() fraopen() fraopen() fraopen() fraopen() fraopen() fraopen() fraopen() fraopen() fraopen() fraopen() fraopen() fraopen() fraopen() fraopen() fraopen() fraopen() fraopen() fraopen() fraopen() fraopen() fraopen() fraopen() fraopen() fraopen() fraopen() fraopen() fraopen() fraopen() fraopen() fraopen() fraopen() fraopen() fraopen() fraopen() fraopen() fraopen() fraopen() fraopen() fraopen() fraopen() fraopen() fraopen() fraopen() fraopen() fraopen() fraopen() fraopen() fraopen() fraopen() fraopen() fraopen() fraopen() fraopen() fraopen() fraopen() fraopen() fraopen() fraopen() fraopen() fraopen() fraopen() fraopen() fraopen() fraopen() fraopen() fraopen() fraopen() fraopen() fraopen() fraopen() fraopen() fraopen() fraopen() fraopen() fraopen() fraopen() fraopen() fraopen() fraopen() fraopen() fraopen() fraopen() fraopen() fraopen() fraopen() fraopen() fraopen() fraopen() fraopen() fraopen() fraopen() fraopen() fraopen() fraopen() fraopen() fraopen() fraopen() fraopen() fraopen() fraopen() fraopen() fraopen() fraopen() fraopen() fraopen() fraopen() fraopen() fraopen() fraopen() fraopen() fraopen() fraopen() fraopen() fraopen() fraopen() fraopen() fraopen() fraopen() fraopen() fraopen() fraopen() fraopen() 
*/
