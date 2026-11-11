#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const int maxn = 5010;
int C,T;
int n , d , a[maxn];
int dp[maxn][maxn];
int res;
void solve(){
	cin >> n >> d;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++){
		for (int j = i + 1; j <= n; j++){
			if (a[j] - a[i] <= d){
				dp[i][j] = 1;
				continue;
			}
			int now = maxn , cur = 0 , cnt = 0;
			for (int k = j; k > i; k--){
				if (a[j] - a[k] <= d){
					now = min (now , dp[i][k]);
				}else{
					cur = k;
					break;
				}
			}
			for (int k = j; k > max(cur , i); k--){
				if (dp[i][k] == now){
					cnt++;
				} 
			}
			dp[i][j] = cnt;
			if (dp[i][j] == 2) res++;
		}
	}
	
	cout << res << endl;
	return ;
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> C >> T;
	while (T--){
		solve();
	}
	return 0;
}

