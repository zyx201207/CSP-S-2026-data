#include<bits/stdc++.h>
using namespace std;
#define int long long
#define debug(n) cout << #n << " = " << n << "\n";
#define deb(n) cout << #n << " = " << n << "    ";
#define div() cout << "\n---------------------\n";
int n,k;int ans;
int a[200005];
int dp[2005][2005];
inline void worksmall(){
	for(int mask = 0;mask < (1 << n);mask++){
		if(__builtin_popcount(mask) == k){
			int sum = 0;
			for(int j = 1;j <= n;j++){
				if(mask & (1 << (j-1))){
					if(sum == 0){sum = a[j];}
					else{sum &= a[j];}
				}
			}
			ans = max(ans,sum);
		}
	}
	cout << ans;
}
inline void workmiddle(){
	sort(a+1,a+n+1);
	dp[1][1] = a[1];
	for(int i = 2;i <= n;i++){
		for(int j = 1;j <= i;j++){
			dp[i][1] = max(dp[i][1],a[j]);
		}
		for(int j = 2;j <= i;j++){
			dp[i][j] = max(dp[i-1][j],(dp[i-1][j-1]&a[i]));
		}
	}
	cout << dp[n][k];
}
inline void workbig(){
	sort(a+1,a+n+1,greater<int>());
	for(int j = 30;j >= 0;j--){
		int cnt = 0; 
		int sum = 0;
		for(int i = 1;i <= n;i++){
			if((a[i] & (1 << j))){
				cnt++;
				if(sum == 0){sum = a[i];}
				else{sum &= a[i];}
				if(cnt == k){
					cout << sum;return;
				}
			}
		}
	}
	cout << "0";
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> k;
	for(int i = 1;i <= n;i++){cin >> a[i];}
	if(n <= 20){worksmall();return 0;}
	if(n <= 2000){workmiddle();return 0;}
	workbig();
	return 0;
}
