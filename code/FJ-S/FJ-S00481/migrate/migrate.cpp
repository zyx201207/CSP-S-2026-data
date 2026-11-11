#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e4 + 5;
int c, T, n, d;
int sum, r[N][N];
int x[N], f[N][N];
signed main(){
	freopen("migrate.in" ,"r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> c >> T;
	while(T--){
		sum = 0;
		cin >> n >> d;
		for(int i = 1;i <= n;i++) cin >> x[i];
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= n;j++) r[i][j] = abs(x[j] - x[i]);
		}
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= n;j++) f[i][j] = 1145141919810;
		}
		for(int k = 1;k <= n;k++){
			for(int i = 1;i <= n;i++){
				for(int j = 1;j <= n;j++){
						if(r[i][j] <= d) f[i][j] = r[i][j];
						if(r[i][k] <= d && r[k][j] <= d) f[i][j] = min({f[i][j], f[i][k] + f[k][j]});
				}
			}
		}
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= n;j++){
				cout << f[i][j] << " ";
			}
			cout << "\n";
		}
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= n;j++){
				int ans = 0;
				for(int k = i+1;k <= j;k++){
					if(f[i][k] + f[k][j] == f[i][j]) ans++;
				}
				if(ans == 2){
					sum++;
					cout << i << " " << j << "\n";
				}
			}
		}
		cout << sum << "\n";
	}
	return 0;
}
