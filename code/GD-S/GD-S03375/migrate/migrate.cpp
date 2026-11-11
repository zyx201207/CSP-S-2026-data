#include <bits/stdc++.h>
using namespace std;
constexpr int N = 5e3+5;
long long a[N],dp[N][N]; //dp[i][j]表示从i到j的走法数 
long long n,d;

void solve(){
	cin>>n>>d;
	for(int i = 1;i<=n;i++) cin>>a[i];
	dp[1][2] = 1;
	int last = 1;
	for(int i = 2;i<=n;i++) {
		for(int j = i+1;j<=n;j++){
			for(int k = 1;k<=d;k++){
				if(j-i<d){
					dp[i][i+k] += dp[last][];
				}
			}
		}
	}
} 

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--) solve();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
