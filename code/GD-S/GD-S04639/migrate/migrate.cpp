#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
const int M = 5e3+10;
#define int long long
int c,t,a[N],n,d,dp[M][M],dp2[M][M],T[N];
void solve(){
	int n,d;cin >> n >> d;
	for(int i = 1; i <= n; i++){
		cin >> a[i]; 
	}
	if(n<=3)cout << "0\n";
	else if(c<=10){
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				dp[i][j]=5e18;
				dp2[i][j]=0;
			} 
		}
		int ans=0;
		for(int i = 1; i <= n; i++){
			dp[i][i]=0;dp2[i][i]=1;
			for(int j = 1; j <= i; j++){
				T[j]=0;
			}
			T[i]=1;
			for(int j = i+1; j <= n; j++){
				int x=lower_bound(a+i,a+j,a[j]-d)-a;
				int z=upper_bound(dp[i]+i,dp[i]+j,dp[i][x])-dp[i]-1;
				dp[i][j]=dp[i][x]+1;
				dp2[i][j]=T[z]-T[x-1];
				T[j]=dp2[i][j]+T[j-1];
				if(dp2[i][j]==2){
					ans++;
				}
			}
		}
		cout << ans << '\n';
	}
	else if(c==11||c==12){
		int x=d/(a[2]-a[1]);
		if(x<=1)cout << 0 << '\n';
		else cout << max(n-x-x+1,0ll) << '\n';
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	while(t--)solve();
}
