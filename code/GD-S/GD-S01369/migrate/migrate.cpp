#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e6+10;
int x[N],d[N],dp[N],f[5010][5010];
signed main(){
	//freopen("migrate.in","r",stdin);
	//freopen("migrate.out","w",stdout);
	int c,t;
	cin >> c >> t;
	while (t--){
		int n,d;
		cin >> n >> d;
		int ans = 0,st = 0;
		for (int i = 1;i <= n;i++){
			cin >> x[i];
		}
		int di = x[2] - x[1];
		bool flag = true;
		for (int i = 3;i <= n;i++){
			if(x[i] - x[i-1] != di){
				flag = false;
				break;
			}
		}
		if(flag){
			if(d / di <= 1) cout << 0;
			else{
				int len = d / di;
				if(n - len - len + 1 <= 0) cout << 0;
				else{
					cout << n - len - len + 1;
				}
			}
			cout << "\n";
		}
		else{
			if(n <= 5000){
				memset(dp,63,sizeof(dp));
				dp[1] = 1;
				for (int i = 1;i <= n;i++){
					f[i][i] = 1;
					int total = 0;
					for (int j = i+1;j <= 3;j++){
						f[i][j] = f[i][j-1];
						if(total > d) total = x[j] - x[j-1],f[i][j]++;
						else total += x[j] - x[j-1]; 
					}
				}
				for (int i = 1;i <= n;i++){
					for (int j = i - 1;j >= 1;j--){
						dp[i] = min(dp[i],dp[j] + f[j][i]);
					}
				}
				int ans = 0;
				for (int i = 1;i <= n;i++){
					int luxian = 0;
					for (int j = i-1;j >= 1;j--){
						if(dp[j] + f[j][i] == dp[i]) luxian++;
					}
					if(luxian == 2) ans++;
				}
				cout << ans;
				cout << "\n";
			}
		}
	}
	return 0;
}
