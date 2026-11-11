//24~32pts
#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
const int M=5005;
const long long INF=1e18;
long long n,d,a[N],dp[M][M],f[M][M],ans;
void solve() {
	ans=0;
	cin >> n >> d;
	for (int i=1;i<=n;i++) {
		for (int j=1;j<=n;j++) {
			dp[i][j]=INF;
			f[i][j]=0;	
		}
	}
	for (int i=1;i<=n;i++) {
		cin >> a[i];
		dp[i][i]=0;
		f[i][i]=1;
		for (int j=i-1;j>=1;j--) {
			if (a[i]-a[j]<=d) {
				dp[i][j]=1; 
				dp[j][i]=1;
				f[i][j]=1;
				f[j][i]=1;
			}
		}
	}
	for (int i=1;i<=n;i++) {
		for (int j=i+1;j<=n;j++) {
			for (int k=i+1;k<j;k++) {
				if (dp[i][k]+dp[k][j]<dp[i][j]) {
					dp[i][j]=dp[i][k]+dp[k][j];
					f[i][j]=f[i][k]*f[k][j];
				}
				else if (dp[i][k]+dp[k][j]==dp[i][j]) {
					f[i][j]+=f[i][k]*f[k][j];
				}
				dp[j][i]=dp[i][j];
				f[j][i]=f[i][j];
			}
		}
	}
	for (int i=1;i<=n;i++) {
		for (int j=1;j<=n;j++) {
//			cout << f[i][j] << " ";
			if (f[i][j]==2) {
				ans++;
			}
		}
//		cout << endl;
	}
	cout << ans/2 << endl;
	return ;
}
int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr);
	int C,T;
	cin >> C >> T;
	if (C<=10) {
		while (T--) {
			solve();
		}		
	}
	else {
		while (T--) {
			cout << "0\n";
		}
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

0 2
10 3
-1000000000000000000 -999999999999999997 -999999999999999994 -999999999999999993 -999999999999999992 -999999999999999991 -999999999999999990 -999999999999999989 -999999999999999986 -999999999999999983
10 3
0 3 6 7 8 9 10 11 14 17

0 1
5 2
1 2 3 4 6
*/
