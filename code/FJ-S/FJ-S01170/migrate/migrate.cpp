#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e6 + 5;
int C, T, n, sum[305][305], f[305][305];
ll d, x[N];
void solveA(){
	while(T--){
		cin >> n >> d;
		for (int i = 1;i <= n;i++) cin >> x[i];
		ll s = abs(x[2] - x[1]);
		ll sum = d / s;
		if (s > d || sum == 1){
			cout << 0 << endl;
			continue;
		}
		ll ans = 0;
		for (int i = 1;i <= n;i++){
			if (i + sum + sum - 1 <= n) ans++; 
		}
		cout << ans << endl;
	}
}
int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> C >> T;
	if (11 <= C && C <= 12){
		solveA();
		return 0;
	}
	
	while(T--){
		cin >> n >> d;
		memset(sum, -1, sizeof(sum));
		memset(f, 0, sizeof(f));
		for (int i = 1;i <= n;i++) cin >> x[i];
		for (int i = 1;i <= n;i++){
			int last = i;
			sum[i][i] = 0;
			for (int j = i + 1;j <= n;j++){
				if (abs(x[j] - x[j - 1]) > d) break;
				if (abs(x[j] - x[last]) <= d)
					sum[i][j] = sum[i][last] + 1;
				else{
					sum[i][j] = sum[i][j - 1] + 1;
					last = j - 1;
				}
			}
		}
		for (int i = 1;i < n;i++)
			if (sum[i][i + 1])
				f[i][i + 1] = 1;
		int ans = 0;
		for (int len = 3;len <= n;len++){
			for (int l = 1;l <= n;l++){
				int r = l + len - 1;
				if (r > n) break;
				if (sum[l][r] == 1){
					f[l][r] = 1;
					continue;
				}
				for (int k = l + 1;k < r;k++){
					if (sum[k][r] == 1 && sum[l][k] + sum[k][r] == sum[l][r]){
						f[l][r] += f[l][k];
					}
				}
				if (f[l][r] == 2) ans++;
			}
		}
//		for (int i = 1;i < n;i++){
//			for (int j = i + 1;j <= n;j++)
//				cout << f[i][j] << " ";
//			cout << endl;
//		}
		cout << ans << endl;
	}
	return 0;
}

//10 3
// 0 3 6 7 8 9 10 13 16 19 
