#include <iostream>
#define int long long 
using namespace std;
const int maxn = 2e6 + 10, inf = 1e9;
int a[maxn], r[305][305];
signed main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int c, t;
	cin >> c >> t;
	while(t--){
		int n, d, flag = 1;
		cin >> n >> d;
		for(int i = 1; i <= n; i++)
			cin >> a[i];
		for(int i = 2; i < n; i++){
			if(a[i + 1] - a[i] != a[i] - a[i - 1]) flag = 0;
		}
		if(flag){
			int x = d / (a[2] - a[1]);
			if(x <= 1) cout << 0 << '\n';
			else {
				int ans = max(0ll, n + 1 - 2 * x);
				cout << ans << '\n';
			}
		}
		else if(n <= 300){
			int ans = 0;
			for(int i = 1; i <= n; i++) 
				for(int j = i + 1; j <= n; j++)
					r[i][j] = inf;
			for(int i = 1; i < n; i++){
				int k = i, cnt = 1;
				for(int j = i + 1; j <= n; j++){
					if(a[j] - a[k] <= d) r[i][j] = cnt;
					else {
						if(k + 1 == j) break;
						cnt++;
						k = j;
						r[i][j] = cnt;
					}
				}
			}
			for(int i = 1; i < n; i++){
				for(int j = i + 3; j <= n; j++){
					if(r[i][j] >= inf) break;
					int cnt = 0;
					for(int k = i + 1; k < j; k++) {
						if(r[i][k] + r[k][j] == r[i][j]) cnt++;
					}
					if(cnt == 2) ans++;
				}
			}
			cout << ans << '\n';
		}
		else cout << 0 << '\n';
	}
	return 0;
}
