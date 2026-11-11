#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5+5;
int n,m;
int a[N],dp[N],vis[N];
void hshu(int x,int last,int dep){
	int aa = dp[x];
	dp[x] = aa & a[last + 1];
	for(int j = last + 2; j <= n; j++){
		if(vis[j] == 1){
			continue;
		}
		if(a[x] == dp[x]){
			dp[x] = aa & a[j];
			vis[j] = 1;
			last = j;
		}
		if(aa & a[j] > dp[x]){
			dp[x] = max(dp[x],aa & a[j]);
			vis[j] = 1;
			last = j;
		}
		if(dep == m){
			return ;
		}
		hshu(x,j,dep + 1);
		
	}	
	for(int j = 1; j <= n; j++){
		vis[j] = 0;
	}
}

signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		dp[i] = a[i];
	}
	for(int i = 1; i <= n; i++){
		hshu(i,i,1);
	}
	int ma_ = 0;
	for(int i = 1; i <= n; i++){
		ma_ = max(ma_,dp[i]);
	}
	cout << ma_;
	return 0;
} 
