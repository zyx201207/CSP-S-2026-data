#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 3e2+10;
bool MB1;
int a[N],dp[N][N][N],f[N][N][N],h[N];
bool MB2;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	//cout<<(&MB1 - &MB2)/1024.0/1024.0<<endl;
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int c; cin>>c;
	int T; cin>>T;
	while(T--){
		int n; cin>>n;
		int d; cin>>d;
		for(int i = 1;i<=n;i++){
			cin>>a[i];
			h[i] = 0;
			for(int j = 1;j<=n;j++){
				for(int k = 1;k<=n;k++){
					dp[i][j][k] = 0;
					f[i][j][k] = 0;
				}
			}
		}
		for(int i = 1;i<=n;i++){
			int last = 1;
			while(a[i] - a[last] > d) last++;
			h[i] = last;
		}
		for(int i = 1;i<=n;i++){
			dp[i][i][0] = 1;
			f[i][i][0] = 1;
			for(int j = i+1;j<=n;j++){
				f[i][j][0] = 1;
				for(int k = 1;k<=n;k++){
					dp[i][j][k] -= f[i][h[j] - 1][k-1];
					dp[i][j][k] += f[i][j][k-1];
					f[i][j][k] += f[i][j-1][k];
					f[i][j][k] += dp[i][j][k];
				}
			}
		}
		int ans = 0;
		for(int i = 1;i<=n;i++){
			for(int j = i+1;j<=n;j++){
				int flag = 0;
				for(int k = 1;k<=n;k++){
					if(dp[i][j][k] != 0){
						flag = k;
						break;
					}
				}
				if(dp[i][j][flag] == 2) ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

*/
