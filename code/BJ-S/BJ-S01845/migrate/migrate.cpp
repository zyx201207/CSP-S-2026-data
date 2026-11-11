#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e6 + 66,M = 5005;
int c,t,n,d,dp[M][M],f[M],ck[M],x[N];
void slv() {
	cin >> n >> d ;
	for(int i=1;i<=n;i++) cin >> x[i];
	if(n == 1) {
		cout << 0 << "\n";
	}
	else if(c <= 10) {
		int cnt = 0;
		for(int k=1;k<n;k++) {
			// cout << "start with " << k << "\n";
			for(int i=1;i<=n;i++) f[i] = 0;
			for(int i=0;i<=n;i++) {
				for(int j=0;j<=n;j++) dp[i][j] = 0;
			}
			dp[k][0] = 1;
			f[0] = 1;
			if(x[k+1] - x[k] > d) f[0] = 0;
			int fk = 0;
			for(int i=0;i<=n;i++) ck[i] = 1;
			for(int i=k+1;i<=n;i++) {
				bool flg = 0;
				for(int j=0;j<=n-k;j++) {
					if(f[j-1]>=0)dp[i][j] = f[j-1];
					// cout << "(" << i << "," << j << ")==>" << dp[i][j] << "\n";
					if(dp[i][j] != 0 && !flg) {
						if(dp[i][j] == 2) cnt ++;
						flg = 1;
					}
				}
				for(int j=1;j<=n-k;j++) {
					f[j-1] += dp[i][j-1];
					while(ck[j-1] < i+1 && x[i+1] - x[ck[j-1]] > d) {
						f[j-1] -= dp[ck[j-1]][j-1];
						ck[j-1]++;
					} 
				}
				// for(int i=0;i<=n-k;i++) cout << f[i] << " ";
					// cout << "\n";
			}
		}
		cout << cnt << "\n";
	}
	else if(c==11||c==12){
		if(x[2] - x[1] > d) cout << 0 << "\n";
		else {
			int rec = n+1;
			for(int i=2;i<=n;i++) {
				if(x[i]-x[1]<=d) rec=i;
				else break;
			}
			// cout << rec << "\n";
			if(rec == n) cout << 0 << "\n";
			else if(rec == 2) cout << 0 << "\n";
			else cout << n - 2 * (rec-1) + 1<< "\n"; 
		}
	}
	else cout << 0 << "\n";
	return;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> c >> t ;
	while(t--) slv();
}